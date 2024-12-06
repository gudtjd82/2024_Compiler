/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
// scope 마다 다른 location var을 가져야됨.
static int location = 0;
static ScopeList global_scope=NULL;

// pj3
void init_scopeList()
{
  global_scope = init_currScope();
}

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)
{ 
  static int isFirstCompound = FALSE;
  switch (t->nodekind)
  { 
    case DeclK:
      switch (t->kind.decl)
      {
        case VarDK:
          // redefined error check
          if(st_lookup(t->attr.name) == -1)
          {
            // if (t->type == Void)
            //   print_error(t->attr.name, t->lineno, 2);
            // else
              st_insert(t, NULL);
          }
          else
            print_error(t->attr.name, t->lineno, 10);
          break;
        case FuncDK:
          // redefined error check
          if(st_lookup_all(t->attr.name) == NULL)
          {
            st_insert(t, NULL);
            insert_scope(t->attr.name);
            isFirstCompound = TRUE;
          }
          else
            print_error(t->attr.name, t->lineno, 10);
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { 
        case IfK: 
        case IfElseK:
        case WhileK:
          insert_scope(NULL);
          isFirstCompound = TRUE;
          break;
        case ReturnK: 
          exitScope();
          break;
        case CompoundK:
          if(!isFirstCompound)
          {
            insert_scope(NULL);
          }
          else
            isFirstCompound = FALSE;
          break;
        // case ReadK:
        //   if (st_lookup(t->attr.name) == -1)
        //   /* not yet in table, so treat as new definition */
        //     st_insert(t->attr.name,t->lineno,location++);
        //   else
        //   /* already in table, so ignore location, 
        //      add line number of use only */ 
        //     st_insert(t->attr.name,t->lineno,0);
        //   break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { 
        case AssignK:
        case OpK:
        case ConstK:
          break;
        case VarK:
          // undeclared variable check
          ScopeList found_scope = st_lookup_all(t->attr.name);
          if(found_scope == NULL) /* undetermined variable */
          {
            t->kind.decl = VarDK;
            t->type = Undet;
          }
          st_insert(t, found_scope);
          break;
        case CallK:
          // undeclared function call check
          ScopeList found_scope = st_lookup_all(t->attr.name);
          if(found_scope == NULL) /* undetermined variable */
          {
            t->kind.decl = FuncDK;
            t->type = Undet;
          }
          st_insert(t, found_scope);
          break;
        case ParamK:
          break;
        // case IdK:
        //   if (st_lookup(t->attr.name) == -1)
        //   /* not yet in table, so treat as new definition */
        //     st_insert(t->attr.name,t->lineno,location++);
        //   else
        //   /* already in table, so ignore location, 
        //      add line number of use only */ 
        //     st_insert(t->attr.name,t->lineno,0);
        //   break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ traverse(syntaxTree,insertNode,nullProc);
  if (TraceAnalyze)
  { 
    fprintf(listing,"\nSymbol table:\n\n");
    if(global_scope != NULL)
      printSymTab(listing, global_scope);
    else
      fprintf(listing, "Global scope is not initialized. Symbol table does not exist.\n");
  }
}

static void print_error(char *name, int lineno, int errorNo)
{ 
  switch (errorNo)
  {
    case 0:
      fprintf(listing, "Error: undeclared function \"%s\" is called at line %d\n", name, lineno);
      break;
    case 1:
      fprintf(listing, "Error: undeclared variable \"%s\" is used at line %d\n", name, lineno);
      break;
    case 2:
      fprintf(listing, "Error: The void-type variable is declared at line %d (name : \"%s\")\n", lineno, name);
      break;
    case 3:
      fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indicies should be integer\n", lineno, name);
      break;
    case 4:
      fprintf(listing, "Error: Invalid array indexing at line %d (name : \"%s\"). indexing can only allowed for int[] variables\n", lineno, name);
      break;
    case 5:
      fprintf(listing, "Error: Invalid function call at line %d (name : \"%s\")\n", lineno, name);
      break;
    case 6:
      fprintf(listing, "Error: Invalid return at line %d\n", lineno);
      break;
    case 7:
      fprintf(listing, "Error: invalid assignment at line %d\n", lineno);
      break;
    case 8:
      fprintf(listing, "Error: invalid operation at line %d\n", lineno);
      break;
    case 9:
      fprintf(listing, "Error: invalid condition at line %d\n", lineno);
      break;
    case 10:
      fprintf(listing, "Error: Symbol \"%s\" is redefined at line %d\n", name, lineno);
      break;
    
    default:
      break;
  }
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  {
    case ExpK:
      switch (t->kind.exp)
      { 
        case AssignK:
          
          break;
        case OpK:
          if ((t->child[0]->type != Integer) ||
              (t->child[1]->type != Integer))
            {
              print_error(t->attr.name, t->lineno, 8);
              t->type = Undet;
            }

          // if ((t->attr.op == EQ) || (t->attr.op == LT))
          //   t->type = Boolean;
          else
            t->type = Integer;
          break;
        case ConstK:
          t->type = Integer;
          break;
        case VarK:
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { case IfK:
          if (t->child[0]->type == Integer)
            typeError(t->child[0],"if test is not Boolean");
          break;
        case AssignK:
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"assignment of non-integer value");
          break;
        case WriteK:
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"write of non-integer value");
          break;
        case RepeatK:
          if (t->child[1]->type == Integer)
            typeError(t->child[1],"repeat test is not Boolean");
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 * AST의 아래에서 위로 type checking
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}
