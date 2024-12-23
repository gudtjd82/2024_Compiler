/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"


/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

// pj3
typedef enum {Variable, Function, Argument} SymK;
const char* SymKStrings[] = {"Variable", "Function", "Argument"};

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     SymK symbolK;
     ExpType type;    // 0:Void, 1:Integer, 2:VoidArr, 3:IntArr
     char * scope_name;
     LineList lines;
     int memloc ; /* memory location for variable */
     struct BucketListRec * next;
   } * BucketList;

typedef struct scopeList
  {
    char * name;
    BucketList hashTable[SIZE];
    struct scopeList * parent;
    struct scopeList * child[SCPMAXCHILDREN];
    int child_cnt;
    int next_location;
  } * ScopeList;

// pj3
static ScopeList currScope;

ScopeList init_currScope()
{
  currScope = (ScopeList) malloc(sizeof(struct scopeList));
  currScope->name = "global";
  currScope->parent = NULL;
  currScope->child_cnt = 0;
  currScope->next_location = 0;

  return currScope;
}


ScopeList insert_scope(char * name)
{
  ScopeList newScope = (ScopeList)malloc(sizeof(struct scopeList));

  // Generate scope name 
  if (name == NULL)
  {
    name = (char *)malloc(100 * sizeof(char));
    sprintf(name, "%s.%d", currScope->name, currScope->child_cnt);
  }
  else
    newScope->name = name;

  newScope->parent = currScope;
  newScope->child_cnt = 0;
  newScope->next_location = 0;

  if (currScope != NULL && currScope->child_cnt < SCPMAXCHILDREN)
  {
    currScope->child[currScope->child_cnt++] = newScope;
  }

  currScope = newScope;

  return newScope;
}

void exitScope()
{
  if(currScope != NULL)
  {
    currScope = currScope->parent;
  }
}

/* the hash table */
// static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 * 인자로 받은 scope에 insert
 * scope가 null이라면 current scope에 insert
 */
void st_insert(TreeNode * s, ScopeList scope)
{ 
  if (scope == NULL)
    scope = currScope;
  int h = hash(s->attr.name);

  BucketList l = scope->hashTable[h];
  while ((l != NULL) && (strcmp(s->attr.name,l->name) != 0))
    l = l->next;

  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = s->attr.name;
    l->symbolK = s->kind.decl;
    l->type = s->type;
    l->scope_name = scope->name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = s->lineno;
    l->memloc = scope->next_location++;
    l->lines->next = NULL;
    l->next = scope->hashTable[h];
    scope->hashTable[h] = l; 
  }
  else /* found in table, so just add line number */
  { LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = s->lineno;
    t->next->next = NULL;
  }
} /* st_insert */

int insert_param(TreeNode *s, ScopeList scope)
{
  if (scope == NULL)
    scope = currScope;
  int h = hash(s->attr.name);

  BucketList l = scope->hashTable[h];
  while ((l != NULL) && (strcmp(s->attr.name,l->name) != 0))
    l = l->next;

  if (l == NULL) /* variable not yet in table */
  { l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = s->attr.name;
    l->symbolK = Argument;
    l->type = s->type;
    l->scope_name = scope->name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = s->lineno;
    l->memloc = scope->next_location++;
    l->lines->next = NULL;
    l->next = scope->hashTable[h];
    scope->hashTable[h] = l; 

    return 0;
  }
  else
    return -1;
}

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
// Find Symbol in current scope
int st_lookup ( char * name )
{ 
  int h = hash(name);
    BucketList l = currScope->hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;
    if (l != NULL) return l->memloc; 
    return -1; 
}
/*Find Symbol including all parent scopes
  symbol이 존재하는 scope를 반환
*/ 
ScopeList st_lookup_up ( char * name )
{ 
  int h = hash(name);
  ScopeList scope = currScope;
  while (scope != NULL)
  {
    BucketList l = scope->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
      l = l->next;
    if (l != NULL) return scope;
    scope = scope->parent;
  }
  return NULL;
}
ScopeList st_lookup_down ( char * name, ScopeList scope )
{ 
  if (scope == NULL) {
        return NULL; 
    }

    int h = hash(name);
    BucketList l = scope->hashTable[h];
    while (l != NULL) {
        if (strcmp(name, l->name) == 0)
            return scope; 
        l = l->next;
    }

    for (int i = 0; i < SCPMAXCHILDREN; i++) {
        if (scope->child[i] != NULL) {
            ScopeList found = st_lookup_down(name, scope->child[i]);
            if (found != NULL)
                return found; 
        }
    }

    return NULL; 
}

ExpType get_argType(ScopeList scope, int memloc)
{
  if (scope == NULL)
    scope = currScope;
  
  for(int i=0; i < SIZE; i++)
  {
    BucketList l = scope->hashTable[i];
    if(l == NULL)
      continue;
      
    if(l->symbolK == Argument)
      if(l->memloc == memloc)
        return l->type;
  }

  return -1;
}

// pj3
const char *type_strings[] = {"void", "int", "void[]", "int[]", "undetermined"};
/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing, ScopeList scope)
{ 
  int i;
  BucketList l;
  fprintf(listing,"\n");
  fprintf(listing,"\n");
  fprintf(listing,"Symbol Name    Symbol Kind    Symbol Type    Scope Name    Location   Line Numbers\n");
  fprintf(listing,"------------   ------------   ------------   ------------  --------   ------------\n");
  for (i=0;i<SIZE;++i)
  { if ((l = scope->hashTable[i]) != NULL)
    { 
      // BucketList l =scope->hashTable[i];
      while (l != NULL)
      { 
        LineList t = l->lines;
        fprintf(listing,"%-14s ",l->name);
        fprintf(listing,"%-14s ",SymKStrings[l->symbolK]);
        fprintf(listing,"%-14s ",type_strings[l->type]);
        fprintf(listing,"%-14s ",l->scope_name);
        fprintf(listing,"%-9d  ",l->memloc);
        while (t != NULL)
        { fprintf(listing,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->next;
      }
    }
  }
  for(i=0; i < SCPMAXCHILDREN; i++)
    if(scope->child[i] != NULL)
      printSymTab(listing, scope->child[i]);
} /* printSymTab */
