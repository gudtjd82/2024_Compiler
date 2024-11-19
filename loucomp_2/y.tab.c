/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    RETURN = 261,                  /* RETURN  */
    INT = 262,                     /* INT  */
    VOID = 263,                    /* VOID  */
    ID = 264,                      /* ID  */
    NUM = 265,                     /* NUM  */
    ASSIGN = 266,                  /* ASSIGN  */
    EQ = 267,                      /* EQ  */
    NE = 268,                      /* NE  */
    LT = 269,                      /* LT  */
    LE = 270,                      /* LE  */
    GT = 271,                      /* GT  */
    GE = 272,                      /* GE  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    TIMES = 275,                   /* TIMES  */
    OVER = 276,                    /* OVER  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LBRACKET = 279,                /* LBRACKET  */
    RBRACKET = 280,                /* RBRACKET  */
    LBRACE = 281,                  /* LBRACE  */
    RBRACE = 282,                  /* RBRACE  */
    SEMI = 283,                    /* SEMI  */
    COMMA = 284,                   /* COMMA  */
    ENDFILE = 285,                 /* ENDFILE  */
    ERROR = 286                    /* ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define RETURN 261
#define INT 262
#define VOID 263
#define ID 264
#define NUM 265
#define ASSIGN 266
#define EQ 267
#define NE 268
#define LT 269
#define LE 270
#define GT 271
#define GE 272
#define PLUS 273
#define MINUS 274
#define TIMES 275
#define OVER 276
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_OVER = 21,                      /* OVER  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_SEMI = 28,                      /* SEMI  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_ENDFILE = 30,                   /* ENDFILE  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_decl_list = 34,                 /* decl_list  */
  YYSYMBOL_decl = 35,                      /* decl  */
  YYSYMBOL_var_decl = 36,                  /* var_decl  */
  YYSYMBOL_type = 37,                      /* type  */
  YYSYMBOL_func_decl = 38,                 /* func_decl  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_param_list = 40,                /* param_list  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_compound = 42,                  /* compound  */
  YYSYMBOL_local_decls = 43,               /* local_decls  */
  YYSYMBOL_stmt_list = 44,                 /* stmt_list  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_exp_stmt = 46,                  /* exp_stmt  */
  YYSYMBOL_if_stmt = 47,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 48,                /* while_stmt  */
  YYSYMBOL_return_stmt = 49,               /* return_stmt  */
  YYSYMBOL_exp = 50,                       /* exp  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simple_exp = 52,                /* simple_exp  */
  YYSYMBOL_relop = 53,                     /* relop  */
  YYSYMBOL_add_exp = 54,                   /* add_exp  */
  YYSYMBOL_addop = 55,                     /* addop  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_mulop = 57,                     /* mulop  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_call = 59,                      /* call  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_arg_list = 61                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    29,    29,    32,    44,    46,    47,    49,    56,    70,
      75,    81,    92,    93,   101,   114,   116,   124,   134,   136,
     149,   151,   164,   166,   167,   168,   169,   170,   171,   173,
     174,   176,   181,   188,   194,   198,   204,   210,   212,   217,
     223,   230,   232,   233,   234,   235,   236,   237,   239,   246,
     248,   249,   251,   257,   259,   260,   262,   264,   265,   266,
     271,   273,   280,   281,   283,   296
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "VOID", "ID", "NUM", "ASSIGN", "EQ", "NE", "LT", "LE",
  "GT", "GE", "PLUS", "MINUS", "TIMES", "OVER", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "SEMI", "COMMA", "ENDFILE",
  "ERROR", "$accept", "program", "decl_list", "decl", "var_decl", "type",
  "func_decl", "params", "param_list", "param", "compound", "local_decls",
  "stmt_list", "stmt", "exp_stmt", "if_stmt", "while_stmt", "return_stmt",
  "exp", "var", "simple_exp", "relop", "add_exp", "addop", "term", "mulop",
  "factor", "call", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      14,   -49,   -49,     1,    14,   -49,   -49,     9,   -49,   -49,
     -49,    62,    81,    17,   -49,    10,    28,    22,    11,   -49,
      23,    27,    38,    14,    65,    69,   -49,   -49,   -49,   -49,
     -49,    14,   -49,    86,     4,   -22,    54,    74,    75,     7,
      63,   -49,    43,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,    70,    88,   -49,    64,    -9,   -49,   -49,    43,    43,
     -49,   -49,    72,    40,    43,    78,   -49,    43,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,    43,    43,   -49,   -49,
      43,    79,    80,   -49,   -49,    82,    77,    83,   -49,   -49,
     -49,    73,    -9,   -49,    33,    33,   -49,    43,   -49,   100,
     -49,   -49,    33,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,     0,     0,     0,     7,    10,     0,     0,    12,    15,
       0,    16,     0,     0,     0,     0,    20,    11,    14,     8,
      17,    22,    19,     0,     0,     0,    28,     0,     0,     0,
      38,    59,     0,    18,    30,    24,    21,    23,    25,    26,
      27,     0,    57,    37,    41,    49,    53,    58,     0,     0,
      60,    34,     0,     0,     0,     0,    29,     0,    46,    47,
      43,    42,    44,    45,    50,    51,     0,     0,    54,    55,
       0,     0,     0,    35,    65,     0,    62,     0,    56,    36,
      57,    40,    48,    52,     0,     0,    61,     0,    39,    31,
      33,    64,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   103,    84,    -8,   -49,   -49,   -49,    87,
      89,   -49,   -49,   -48,   -49,   -49,   -49,   -49,   -39,   -20,
     -49,   -49,    36,   -49,    32,   -49,    34,   -49,   -49,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    17,    18,    19,
      45,    31,    34,    46,    47,    48,    49,    50,    51,    52,
      53,    76,    54,    77,    55,    80,    56,    57,    85,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,     9,    13,    65,    16,    36,    14,    37,    60,    38,
      39,    78,    79,    40,    41,    16,    40,    41,    11,    81,
      82,     1,     2,    33,    84,    87,    42,    20,    89,    42,
      26,    43,    44,   -13,    36,    61,    37,    21,    38,    39,
      23,    60,    40,    41,    60,    22,    99,   100,    24,    40,
      41,    25,    40,    41,   103,    42,    90,    90,   101,    26,
      90,    44,    42,   -63,    26,    42,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    68,    69,    70,    71,
      72,    73,    74,    75,    12,    63,    13,    64,     1,    15,
      14,    74,    75,    29,    30,    35,    58,    59,    66,    67,
      83,    88,    94,    95,   102,    96,    97,    10,    98,    92,
      28,    27,    91,     0,    93,    32
};

static const yytype_int8 yycheck[] =
{
      39,     0,    24,    42,    12,     1,    28,     3,     1,     5,
       6,    20,    21,     9,    10,    23,     9,    10,     9,    58,
      59,     7,     8,    31,    63,    64,    22,    10,    67,    22,
      26,    27,    28,    23,     1,    28,     3,     9,     5,     6,
      29,     1,     9,    10,     1,    23,    94,    95,    25,     9,
      10,    24,     9,    10,   102,    22,    76,    77,    97,    26,
      80,    28,    22,    23,    26,    22,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    12,    13,    14,    15,
      16,    17,    18,    19,    22,    22,    24,    24,     7,     8,
      28,    18,    19,    28,    25,     9,    22,    22,    28,    11,
      28,    23,    23,    23,     4,    23,    29,     4,    25,    77,
      23,    22,    76,    -1,    80,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    33,    34,    35,    36,    37,    38,     0,
      35,     9,    22,    24,    28,     8,    37,    39,    40,    41,
      10,     9,    23,    29,    25,    24,    26,    42,    41,    28,
      25,    43,    36,    37,    44,     9,     1,     3,     5,     6,
       9,    10,    22,    27,    28,    42,    45,    46,    47,    48,
      49,    50,    51,    52,    54,    56,    58,    59,    22,    22,
       1,    28,    50,    22,    24,    50,    28,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    53,    55,    20,    21,
      57,    50,    50,    28,    50,    60,    61,    50,    23,    50,
      51,    54,    56,    58,    23,    23,    23,    29,    25,    45,
      45,    50,     4,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    59,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     2,     3,     3,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_list  */
#line 30 "cminus.y"
                 { savedTree = yyvsp[0];}
#line 1306 "y.tab.c"
    break;

  case 3: /* decl_list: decl_list decl  */
#line 33 "cminus.y"
                { YYSTYPE t = yyvsp[-1];
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-1];
                  }
                  else
                    yyval = yyvsp[0];
                }
#line 1322 "y.tab.c"
    break;

  case 4: /* decl_list: decl  */
#line 44 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1328 "y.tab.c"
    break;

  case 5: /* decl: var_decl  */
#line 46 "cminus.y"
                        { yyval = yyvsp[0]; }
#line 1334 "y.tab.c"
    break;

  case 6: /* decl: func_decl  */
#line 47 "cminus.y"
                        { yyval = yyvsp[0]; }
#line 1340 "y.tab.c"
    break;

  case 7: /* var_decl: type ID SEMI  */
#line 50 "cminus.y"
                {
                  TreeNode *t = newDeclNode(VarDK);
                  t->attr.name = copyString(tokenString);
                  t->type = yyvsp[-2]->type;
                  yyval = t;
                }
#line 1351 "y.tab.c"
    break;

  case 8: /* var_decl: type ID LBRACKET NUM RBRACKET SEMI  */
#line 57 "cminus.y"
                {
                  TreeNode *t = newDeclNode(VarDK);
                  t->attr.name = copyString(tokenString);
                  t->type = yyvsp[-5]->type;
                  t->isArray = TRUE;

                  TreeNode *arrSize = newExpNode(ConstK);
                  arrSize->attr.val = atoi(tokenString);
                  t->child[0] = arrSize;

                  yyval = t;
                }
#line 1368 "y.tab.c"
    break;

  case 9: /* type: INT  */
#line 71 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Integer;
                }
#line 1377 "y.tab.c"
    break;

  case 10: /* type: VOID  */
#line 76 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Void;
                }
#line 1386 "y.tab.c"
    break;

  case 11: /* func_decl: type ID LPAREN params RPAREN compound  */
#line 82 "cminus.y"
                {
                  TreeNode *t = newDeclNode(FuncDK);
                  t->attr.name = copyString(tokenString);
                  t->type = yyvsp[-5]->type;
                  t->child[0] = yyvsp[-2];
                  t->child[1] = yyvsp[0];

                  yyval = t;
                }
#line 1400 "y.tab.c"
    break;

  case 12: /* params: param_list  */
#line 92 "cminus.y"
                         { yyval = yyvsp[0]; }
#line 1406 "y.tab.c"
    break;

  case 13: /* params: VOID  */
#line 94 "cminus.y"
                { 
                  TreeNode *t = newExpNode(ParamK);
                  t->type = Void;

                  yyval = t;
                }
#line 1417 "y.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 102 "cminus.y"
                {
                  YYSTYPE t = yyvsp[-2];
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-2];
                  }
                  else
                    yyval = yyvsp[0];
                }
#line 1434 "y.tab.c"
    break;

  case 15: /* param_list: param  */
#line 114 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1440 "y.tab.c"
    break;

  case 16: /* param: type ID  */
#line 117 "cminus.y"
                {
                  TreeNode *t = newExpNode(ParamK);
                  t->attr.name = copyString(tokenString);
                  t->type = yyvsp[-1]->type;

                  yyval = t;
                }
#line 1452 "y.tab.c"
    break;

  case 17: /* param: type ID LBRACKET RBRACKET  */
#line 125 "cminus.y"
                {
                  TreeNode *t = newExpNode(ParamK);
                  t->attr.name = copyString(tokenString);
                  t->type = yyvsp[-3]->type;
                  t->isArray = TRUE;

                  yyval = t;
                }
#line 1465 "y.tab.c"
    break;

  case 19: /* local_decls: local_decls var_decl  */
#line 137 "cminus.y"
                {
                  YYSTYPE t = yyvsp[-1];
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-1];
                  }
                  else
                    yyval = yyvsp[0];
                }
#line 1482 "y.tab.c"
    break;

  case 20: /* local_decls: %empty  */
#line 149 "cminus.y"
              { yyval = NULL; }
#line 1488 "y.tab.c"
    break;

  case 21: /* stmt_list: stmt_list stmt  */
#line 152 "cminus.y"
                {
                  YYSTYPE t = yyvsp[-1];
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-1];
                  }
                  else
                    yyval = yyvsp[0];
                }
#line 1505 "y.tab.c"
    break;

  case 22: /* stmt_list: %empty  */
#line 164 "cminus.y"
              { yyval = NULL; }
#line 1511 "y.tab.c"
    break;

  case 23: /* stmt: exp_stmt  */
#line 166 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1517 "y.tab.c"
    break;

  case 24: /* stmt: compound  */
#line 167 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1523 "y.tab.c"
    break;

  case 25: /* stmt: if_stmt  */
#line 168 "cminus.y"
                      { yyval = yyvsp[0]; }
#line 1529 "y.tab.c"
    break;

  case 26: /* stmt: while_stmt  */
#line 169 "cminus.y"
                         { yyval = yyvsp[0]; }
#line 1535 "y.tab.c"
    break;

  case 27: /* stmt: return_stmt  */
#line 170 "cminus.y"
                          { yyval = yyvsp[0]; }
#line 1541 "y.tab.c"
    break;

  case 28: /* stmt: error  */
#line 171 "cminus.y"
                     { yyval = NULL; }
#line 1547 "y.tab.c"
    break;

  case 29: /* exp_stmt: exp SEMI  */
#line 173 "cminus.y"
                        { yyval = yyvsp[-1]; }
#line 1553 "y.tab.c"
    break;

  case 30: /* exp_stmt: SEMI  */
#line 174 "cminus.y"
                        { yyval = NULL; }
#line 1559 "y.tab.c"
    break;

  case 31: /* if_stmt: IF LPAREN exp RPAREN stmt  */
#line 177 "cminus.y"
                 { yyval = newStmtNode(IfK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1568 "y.tab.c"
    break;

  case 32: /* if_stmt: IF LPAREN exp RPAREN stmt ELSE stmt  */
#line 182 "cminus.y"
                 { yyval = newStmtNode(IfElseK);
                   yyval->child[0] = yyvsp[-4];
                   yyval->child[1] = yyvsp[-2];
                   yyval->child[2] = yyvsp[0];
                 }
#line 1578 "y.tab.c"
    break;

  case 33: /* while_stmt: WHILE LPAREN exp RPAREN stmt  */
#line 189 "cminus.y"
                 { yyval = newStmtNode(WhileK);
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1587 "y.tab.c"
    break;

  case 34: /* return_stmt: RETURN SEMI  */
#line 195 "cminus.y"
                {
                  yyval = newStmtNode(ReturnK);
                }
#line 1595 "y.tab.c"
    break;

  case 35: /* return_stmt: RETURN exp SEMI  */
#line 199 "cminus.y"
                {
                  yyval = newStmtNode(ReturnK);
                  yyval->child[0] = yyvsp[-1];
                }
#line 1604 "y.tab.c"
    break;

  case 36: /* exp: var ASSIGN exp  */
#line 205 "cminus.y"
                {
                  yyval = newExpNode(AssignK);
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                }
#line 1614 "y.tab.c"
    break;

  case 37: /* exp: simple_exp  */
#line 210 "cminus.y"
                         { yyval = yyvsp[0]; }
#line 1620 "y.tab.c"
    break;

  case 38: /* var: ID  */
#line 213 "cminus.y"
                {
                  yyval = newExpNode(VarK);
                  yyval->attr.name = copyString(tokenString);
                }
#line 1629 "y.tab.c"
    break;

  case 39: /* var: ID LBRACKET exp RBRACKET  */
#line 218 "cminus.y"
                {
                  yyval = newExpNode(VarK);
                  yyval->child[0] = yyvsp[-1];
                }
#line 1638 "y.tab.c"
    break;

  case 40: /* simple_exp: add_exp relop add_exp  */
#line 224 "cminus.y"
                {
                  yyval = newExpNode(OpK);
                  yyval->attr.op = yyvsp[-1];
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0]; 
                }
#line 1649 "y.tab.c"
    break;

  case 41: /* simple_exp: add_exp  */
#line 230 "cminus.y"
                      { yyval = yyvsp[0]; }
#line 1655 "y.tab.c"
    break;

  case 42: /* relop: LE  */
#line 232 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1661 "y.tab.c"
    break;

  case 43: /* relop: LT  */
#line 233 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1667 "y.tab.c"
    break;

  case 44: /* relop: GT  */
#line 234 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1673 "y.tab.c"
    break;

  case 45: /* relop: GE  */
#line 235 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1679 "y.tab.c"
    break;

  case 46: /* relop: EQ  */
#line 236 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1685 "y.tab.c"
    break;

  case 47: /* relop: NE  */
#line 237 "cminus.y"
                 { yyval = yyvsp[0]; }
#line 1691 "y.tab.c"
    break;

  case 48: /* add_exp: add_exp addop term  */
#line 240 "cminus.y"
                {
                  yyval = newExpNode(OpK);
                  yyval->attr.op = yyvsp[-1];
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                }
#line 1702 "y.tab.c"
    break;

  case 49: /* add_exp: term  */
#line 246 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1708 "y.tab.c"
    break;

  case 50: /* addop: PLUS  */
#line 248 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1714 "y.tab.c"
    break;

  case 51: /* addop: MINUS  */
#line 249 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1720 "y.tab.c"
    break;

  case 52: /* term: term mulop factor  */
#line 252 "cminus.y"
                 { yyval = newExpNode(OpK);
                   yyval->attr.op = yyvsp[-1];
                   yyval->child[0] = yyvsp[-2];
                   yyval->child[1] = yyvsp[0];
                 }
#line 1730 "y.tab.c"
    break;

  case 53: /* term: factor  */
#line 257 "cminus.y"
                     { yyval = yyvsp[0]; }
#line 1736 "y.tab.c"
    break;

  case 54: /* mulop: TIMES  */
#line 259 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1742 "y.tab.c"
    break;

  case 55: /* mulop: OVER  */
#line 260 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1748 "y.tab.c"
    break;

  case 56: /* factor: LPAREN exp RPAREN  */
#line 263 "cminus.y"
                 { yyval = yyvsp[-1]; }
#line 1754 "y.tab.c"
    break;

  case 57: /* factor: var  */
#line 264 "cminus.y"
                  { yyval = yyvsp[0]; }
#line 1760 "y.tab.c"
    break;

  case 58: /* factor: call  */
#line 265 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1766 "y.tab.c"
    break;

  case 59: /* factor: NUM  */
#line 267 "cminus.y"
                {
                  yyval = newExpNode(ConstK);
                  yyval->attr.val = atoi(tokenString);
                }
#line 1775 "y.tab.c"
    break;

  case 60: /* factor: error  */
#line 271 "cminus.y"
                    { yyval = NULL; }
#line 1781 "y.tab.c"
    break;

  case 61: /* call: ID LPAREN args RPAREN  */
#line 274 "cminus.y"
              {
                yyval = newExpNode(CallK);
                yyval->attr.name = copyString(tokenString);
                yyval->child[0] = yyvsp[-1];
              }
#line 1791 "y.tab.c"
    break;

  case 62: /* args: arg_list  */
#line 280 "cminus.y"
                        { yyval = yyvsp[0]; }
#line 1797 "y.tab.c"
    break;

  case 63: /* args: %empty  */
#line 281 "cminus.y"
              { yyval = NULL; }
#line 1803 "y.tab.c"
    break;

  case 64: /* arg_list: arg_list COMMA exp  */
#line 284 "cminus.y"
                {
                  YYSTYPE t = yyvsp[-2];
                  if (t != NULL)
                  {
                    while (t->sibling != NULL)
                      t = t->sibling;
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-2];
                  }
                  else
                    yyval = yyvsp[0];
                }
#line 1820 "y.tab.c"
    break;

  case 65: /* arg_list: exp  */
#line 296 "cminus.y"
                  { yyval = yyvsp[0]; }
#line 1826 "y.tab.c"
    break;


#line 1830 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 299 "cminus.y"


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
{ yyparse();
  return savedTree;
}

