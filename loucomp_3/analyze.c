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
// static int location = 0;
static ScopeList global_scope=NULL;

// pj3
void init_scopeList()
{
  global_scope = init_currScope();

  // Built-in Functions
  // int input(void)
  TreeNode *inputFunc = (TreeNode *)malloc(sizeof(TreeNode));
  inputFunc->attr.name = "input";
  inputFunc->type = Integer; 
  inputFunc->kind.decl = FuncDK;
  inputFunc->lineno = 0;

  st_insert(inputFunc, NULL); 

  TreeNode *outputFunc = (TreeNode *)malloc(sizeof(TreeNode));
  outputFunc->attr.name = "output";
  outputFunc->type = Void; 
  outputFunc->kind.decl = FuncDK;
  outputFunc->lineno = 0;
  TreeNode *outputParam = (TreeNode*)malloc(sizeof(TreeNode));
  outputParam->type = Integer;
  outputParam->attr.name = "value";

  st_insert(outputFunc, NULL);
  insert_scope(outputFunc->attr.name);
  insert_param(outputParam, NULL);
  exitScope();
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
  { 
    preProc(t);
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
          // fprintf(listing,"VarDK\n");
          // redefined error check
          if(st_lookup(t->attr.name) == -1)
          {
            // Void-type variable error
            if (t->type == Void)
            {
              print_error(t->attr.name, t->lineno, 2);
              t->type = Undet;
            }
            st_insert(t, NULL);
          }
          else
            print_error(t->attr.name, t->lineno, 10);
          break;
        case FuncDK:
          // fprintf(listing,"FunDK\n");
          // redefined error check
          if(st_lookup_up(t->attr.name) == NULL)
          {
            st_insert(t, NULL);
            insert_scope(t->attr.name);
            isFirstCompound = TRUE;

            // // Insert parameters
            // for(int i = 0; i < MAXCHILDREN; i++)
            // {
            //   TreeNode *child;
            //   if((child = t->child[i]) != NULL)
            //     if(child->kind.exp == ParamK)
            //       if(insert_param(child, NULL) <0)
            //         print_error(child->attr.name, child->lineno, 10);
            // }
          }
          else  /* redefined error */
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
          // fprintf(listing,"IFWHILE\n");
          insert_scope(NULL);
          isFirstCompound = TRUE;
          break;
        case ReturnK: 
          // fprintf(listing,"return\n");
          // exitScope();
          break;
        case CompoundK:
          // fprintf(listing,"compound\n");
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
      ScopeList found_scope;
      switch (t->kind.exp)
      { 
        case AssignK:
        case OpK:
        case ConstK:
          // fprintf(listing,"dds\n");
          break;
        case VarK:
          // fprintf(listing,"Var\n");
          // undeclared variable check
          found_scope = st_lookup_up(t->attr.name);
          if(found_scope == NULL) /* undetermined variable */
          {
            print_error(t->attr.name, t->lineno, 1);
            t->kind.decl = VarDK;
            t->type = Undet;
          }
          st_insert(t, found_scope);
          break;
        case CallK:
          // fprintf(listing,"Call\n");
          // undeclared function call check
          found_scope = st_lookup_up(t->attr.name);
          if(found_scope == NULL) /* undetermined Function */
          {
            print_error(t->attr.name, t->lineno, 0);
            t->kind.decl = FuncDK;
            t->type = Undet;
            st_insert(t, found_scope);
            insert_scope(t->attr.name);

            TreeNode *undet_param = (TreeNode*) malloc(sizeof(TreeNode));
            undet_param->type = Undet;
            undet_param->attr.name = "Undet";
            insert_param(undet_param, NULL);
          }
          else  /* function call */
          {
            // TreeNode *child;
            // ExpType arg_type;
            // for(int i = 0; i < MAXCHILDREN; i++)
            // {
            //   if((child = t->child[i]) != NULL)
            //   {
            //     arg_type = get_argType(found_scope, i);
            //     if((arg_type < 0) || (arg_type != child->type))
            //     {
            //       print_error(t->attr.name, t->lineno, 5);
            //       t->type = Undet;
            //       break;
            //     }
            //   }
            // }
            st_insert(t, found_scope);
          }
          break;
        case ParamK:
          // fprintf(listing,"Param\n");
          if (t->type != Void)
            if(insert_param(t, NULL) <0)
              print_error(t->attr.name, t->lineno, 10);
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

static void postProcessNode(TreeNode *t)
{
  if(t->nodekind == DeclK && t->kind.decl == FuncDK)
    exitScope();
  if(t->nodekind == StmtK && t->kind.stmt == CompoundK)
    exitScope();
}
/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  traverse(syntaxTree,insertNode,postProcessNode);
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
{ 
  static ExpType return_type = -1;
  switch (t->nodekind)
  {
    case DeclK:
      switch (t->kind.decl)
      {
      case FuncDK:
        // return_type = t->type;
        if(t->type != return_type)
        {
          print_error(t->attr.name, t->lineno, 6);
          t->type = Undet;
        }
        break;
      
      default:
        break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { 
        case AssignK:
          if(t->child[0]->type != t->child[1]->type)
          {
            print_error(t->attr.name, t->lineno, 7);
            t->type = Undet;
          }
          break;
        case OpK:
          // if((t->child[0] == NULL) || (t->child[1] == NULL))
          //   fprintf(listing, "Error\n");
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
          // index must be Integer type
          if(t->type == VoidArr || t->type == IntArr) /* Array type */
          {
            if(t->child[0]->type != Integer)
            {
              print_error(t->attr.name, t->lineno, 3);
              t->type = Undet;
            }
          }
          else  /* Non-Array type */
          {
            if(t->child[0] != NULL)
            {
              print_error(t->attr.name, t->lineno, 4);
              t->type = Undet;
            }
          }
          break;
        case CallK:
          ScopeList found_scope = st_lookup_down(t->attr.name, global_scope);
          if(found_scope != NULL)
          {
            TreeNode *child;
            ExpType arg_type;
            for(int i = 0; i < MAXCHILDREN; i++)
            {
              if((child = t->child[i]) != NULL)
              {
                arg_type = get_argType(found_scope, i);
                if((arg_type < 0) || (arg_type != child->type))
                {
                  fprintf(listing,"arg:%d, param:%d\n", arg_type, child->type);
                  print_error(t->attr.name, t->lineno, 5);
                  t->type = Undet;
                  break;
                }
              }
            }
          }
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
          if (t->child[0]->type != Integer)
            print_error(t->attr.name, t->lineno, 9);
          break;
        case ReturnK:
          TreeNode *child;
          if((child = t->child[0]) != NULL)
          {
            return_type = child->type;
            // if(child->type != return_type)
            //   print_error(t->attr.name, t->lineno, 6);
          }
          else
          {
            return_type = Void;
            // if(return_type != Void)
            //   print_error(t->attr.name, t->lineno, 6);
          }

          // return_type = -1;
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
