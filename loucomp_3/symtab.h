/****************************************************/
/* File: symtab.h                                   */
/* Symbol table interface for the TINY compiler     */
/* (allows only one symbol table)                   */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
#include "globals.h"

#ifndef _SYMTAB_H_
#define _SYMTAB_H_

// pj3
#define SCPMAXCHILDREN 100

typedef struct scopeList *ScopeList;

ScopeList init_currScope();
ScopeList insert_scope(char * name);
void exitScope();

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
// pj3
    // current scope의 next_location 값을 이용하기 때문에 인자로 loc을 받을 필요 없음.
void st_insert(TreeNode * s, ScopeList scope);
int insert_param(TreeNode *s, ScopeList scope);

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name );
ScopeList st_lookup_up ( char * name );
ScopeList st_lookup_down ( char * name, ScopeList scope );
ExpType get_argType(ScopeList scope, int memloc);

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing, ScopeList scope);

#endif
