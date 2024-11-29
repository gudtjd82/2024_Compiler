/****************************************************/
/* File: cminus.y                                     */
/* The C-MINUS Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char*);
TreeNode * parse(void);
%}

%nonassoc IF
%nonassoc ELSE
%token WHILE RETURN
%token INT VOID

%token ID NUM 

%left PLUS MINUS
%left TIMES OVER
%nonassoc LT LE GT GE
%nonassoc EQ NE
%right ASSIGN

%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMI COMMA

%token ENDFILE ERROR 

%% /* Grammar for C-MINUS */

program     : decl_list
                 { savedTree = $1;} 
            ;
decl_list   : decl_list decl
                { YYSTYPE t = $1;
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $2;
                    $$ = $1;
                  }
                  else
                    $$ = $2;
                }
            | decl  { $$ = $1; }
            ;
decl        : var_decl  { $$ = $1; }
            | func_decl { $$ = $1; }
            ;
var_decl    : type identifier SEMI
                {
                  TreeNode *t = newDeclNode(VarDK);
                  t->attr.name = copyString($2->attr.name);
                  t->type = $1->type;
                  $$ = t;
                }
            | type identifier LBRACKET NUM RBRACKET SEMI
                {
                  TreeNode *t = newDeclNode(VarDK);
                  t->attr.name = copyString($2->attr.name);
                  t->type = $1->type;
                  t->isArray = TRUE;

                  TreeNode *arrSize = newExpNode(ConstK);
                  arrSize->attr.val = atoi(tokenString);
                  t->child[0] = arrSize;

                  $$ = t;
                }
            ;
type        : INT 
                {
                  $$ = newBasicNode();
                  $$->type = Integer;
                }
            | VOID 
                {
                  $$ = newBasicNode();
                  $$->type = Void;
                }
            ;
identifier  : ID
                {
                  TreeNode *t = newBasicNode();
                  t->attr.name = copyString(tokenString);

                  $$ = t;
                }
            ;
func_decl   : type identifier LPAREN params RPAREN compound
                {
                  TreeNode *t = newDeclNode(FuncDK);
                  t->attr.name = copyString($2->attr.name);
                  t->type = $1->type;
                  t->child[0] = $4;
                  t->child[1] = $6;

                  $$ = t;
                }
            ;
params      : param_list { $$ = $1; }
            | VOID 
                { 
                  TreeNode *t = newExpNode(ParamK);
                  t->type = Void;

                  $$ = t;
                }
            ;
param_list  : param_list COMMA param
                {
                  YYSTYPE t = $1;
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $3;
                    $$ = $1;
                  }
                  else
                    $$ = $3;
                }
            | param { $$ = $1; }
            ;
param       : type identifier
                {
                  TreeNode *t = newExpNode(ParamK);
                  t->attr.name = copyString($2->attr.name);
                  t->type = $1->type;

                  $$ = t;
                }
            | type identifier LBRACKET RBRACKET
                {
                  TreeNode *t = newExpNode(ParamK);
                  t->attr.name = copyString($2->attr.name);
                  t->type = $1->type;
                  t->isArray = TRUE;

                  $$ = t;
                }
            ;
compound    : LBRACE local_decls stmt_list RBRACE
                {
                  TreeNode *t = newStmtNode(CompoundK);
                  t->child[0] = $2;
                  t->child[1] = $3;

                  $$ = t;
                }
            ;
local_decls : local_decls var_decl
                {
                  YYSTYPE t = $1;
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $2;
                    $$ = $1;
                  }
                  else
                    $$ = $2;
                }
            | { $$ = NULL; }
            ;
stmt_list   : stmt_list stmt
                {
                  YYSTYPE t = $1;
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $2;
                    $$ = $1;
                  }
                  else
                    $$ = $2;
                }
            | { $$ = NULL; }
            ;
stmt        : exp_stmt { $$ = $1; }
            | compound { $$ = $1; }
            | if_stmt { $$ = $1; }
            | while_stmt { $$ = $1; }
            | return_stmt { $$ = $1; }
            ;
exp_stmt    : exp SEMI  { $$ = $1; }
            | SEMI      { $$ = NULL; }
            ;
if_stmt     : IF LPAREN exp RPAREN stmt %prec IF
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            | IF LPAREN exp RPAREN stmt ELSE stmt
                 { $$ = newStmtNode(IfElseK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
while_stmt : WHILE LPAREN exp RPAREN stmt
                 { $$ = newStmtNode(WhileK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            ;
return_stmt : RETURN SEMI
                {
                  $$ = newStmtNode(ReturnK);
                }
            | RETURN exp SEMI
                {
                  $$ = newStmtNode(ReturnK);
                  $$->child[0] = $2;
                }
            ;
exp         : var ASSIGN exp
                {
                  $$ = newExpNode(AssignK);
                  $$->child[0] = $1;
                  $$->child[1] = $3;
                }
            | simple_exp { $$ = $1; }
            ;
var         : identifier
                {
                  $$ = newExpNode(VarK);
                  $$->attr.name = copyString($1->attr.name);
                }
            | identifier LBRACKET exp RBRACKET
                {
                  $$ = newExpNode(VarK);
                  $$->attr.name = copyString($1->attr.name);
                  $$->isArray = TRUE;
                  $$->child[0] = $3;
                }
            ;
simple_exp  : add_exp relop add_exp
                {
                  $$ = newExpNode(OpK);
                  $$->attr.op = $2->attr.op;
                  $$->child[0] = $1;
                  $$->child[1] = $3; 
                }
            | add_exp { $$ = $1; }
            ;
relop       : LE 
                { 
                  $$ = newBasicNode();
                  $$->attr.op = LE;
                }
            | LT
                { 
                  $$ = newBasicNode();
                  $$->attr.op = LT;
                }
            | GT
                { 
                  $$ = newBasicNode();
                  $$->attr.op = GT;
                }
            | GE
                { 
                  $$ = newBasicNode();
                  $$->attr.op = GE;
                }
            | EQ
                { 
                  $$ = newBasicNode();
                  $$->attr.op = EQ;
                }
            | NE
                { 
                  $$ = newBasicNode();
                  $$->attr.op = NE;
                }
            ;
add_exp     : add_exp addop term
                {
                  $$ = newExpNode(OpK);
                  $$->attr.op = $2->attr.op;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
                }
            | term { $$ = $1; }
            ;
addop       : PLUS
                { 
                  $$ = newBasicNode();
                  $$->attr.op = PLUS;
                }
            | MINUS
                { 
                  $$ = newBasicNode();
                  $$->attr.op = MINUS;
                }            
            ;
term        : term mulop factor 
                 { $$ = newExpNode(OpK);
                   $$->attr.op = $2->attr.op;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            | factor { $$ = $1; }
            ;
mulop       : TIMES
                { 
                  $$ = newBasicNode();
                  $$->attr.op = TIMES;
                }
            | OVER
                { 
                  $$ = newBasicNode();
                  $$->attr.op = OVER;
                }            
            ;
factor      : LPAREN exp RPAREN
                 { $$ = $2; }
            | var { $$ = $1; }
            | call { $$ = $1; }
            | NUM
                {
                  $$ = newExpNode(ConstK);
                  $$->attr.val = atoi(tokenString);
                }
            ;
call        : identifier LPAREN args RPAREN
              {
                $$ = newExpNode(CallK);
                $$->attr.name = copyString($1->attr.name);
                $$->child[0] = $3;
              }
            ;
args        : arg_list  { $$ = $1; }
            | { $$ = NULL; }
            ;
arg_list    : arg_list COMMA exp
                {
                  YYSTYPE t = $1;
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = $3;
                    $$ = $1;
                  }
                  else
                    $$ = $3;
                }
            | exp { $$ = $1; }
            ;

%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ 
  yyparse();
  if (savedTree == NULL) {
    fprintf(listing, "Error: savedTree is NULL\n");
    exit(1);
  }
  return savedTree;
}

