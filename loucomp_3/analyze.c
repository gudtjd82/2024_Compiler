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
static int location = 0;

// pj3
void init_scopeList()
{
  init_currScope();
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
          if(st_lookup(t->attr.name) == -1)
          {
            if (t->type == Void)
              print_error(t->attr.name, t->lineno, 2);
            else
              st_insert(t, location++);
          }
          else
            print_error(t->attr.name, t->lineno, 10);
          break;
        case FuncDK:
          if(st_lookup_all(t->attr.name) == -1)
          {
            st_insert(t, location++);
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
        case CompoundK:
          if(!isFirstCompound)
          {
            insert_scope(NULL);
          }
          else
            isFirstCompound = FALSE;
          break;

        case ReadK:
          if (st_lookup(t->attr.name) == -1)
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++);
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_insert(t->attr.name,t->lineno,0);
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
          if (st_lookup(t->attr.name) == -1)
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++);
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_insert(t->attr.name,t->lineno,0);
          break;
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
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
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
  { case ExpK:
      switch (t->kind.exp)
      { case OpK:
          if ((t->child[0]->type != Integer) ||
              (t->child[1]->type != Integer))
            typeError(t,"Op applied to non-integer");
          if ((t->attr.op == EQ) || (t->attr.op == LT))
            t->type = Boolean;
          else
            t->type = Integer;
          break;
        case ConstK:
        case IdK:
          t->type = Integer;
          break;
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
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}
