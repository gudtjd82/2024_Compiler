/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     RETURN = 261,
     INT = 262,
     VOID = 263,
     ID = 264,
     NUM = 265,
     MINUS = 266,
     PLUS = 267,
     OVER = 268,
     TIMES = 269,
     GE = 270,
     GT = 271,
     LE = 272,
     LT = 273,
     NE = 274,
     EQ = 275,
     ASSIGN = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACKET = 279,
     RBRACKET = 280,
     LBRACE = 281,
     RBRACE = 282,
     SEMI = 283,
     COMMA = 284,
     ENDFILE = 285,
     ERROR = 286
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define RETURN 261
#define INT 262
#define VOID 263
#define ID 264
#define NUM 265
#define MINUS 266
#define PLUS 267
#define OVER 268
#define TIMES 269
#define GE 270
#define GT 271
#define LE 272
#define LT 273
#define NE 274
#define EQ 275
#define ASSIGN 276
#define LPAREN 277
#define RPAREN 278
#define LBRACKET 279
#define RBRACKET 280
#define LBRACE 281
#define RBRACE 282
#define SEMI 283
#define COMMA 284
#define ENDFILE 285
#define ERROR 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

