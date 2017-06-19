/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "spl.y" /* yacc.c:339  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

//nice to have...
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

// For GCC - determine system arch.
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ARCH_64
#else
#define ARCH_32
#endif
#endif

#ifdef ARCH_64
#define MEM_SIZE long
#else 
#define MEM_SIZE int
#endif
/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { 
PROGRAM_NT, BLOCK_NT, DECLARATION_BLOCK_NT, IDENTIFIER_LIST_NT, IDENTIFIER_LIST_SINGLE_NT, STATEMENT_LIST_NT, STATEMENT_NT, ASSIGNMENT_STATEMENT_NT, IF_STATEMENT_NT, DO_STATEMENT_NT,
WHILE_STATEMENT_NT, FOR_STATEMENT_NT, WRITE_STATEMENT_NT, READ_STATEMENT_NT, OUTPUT_LIST_NT, FOR_ITERATOR_NT,
CONSTANT_NT, CONSTANTchl_NT, VALUE_ID_NT, VALUE_CL_NT ,VALUE_EX_NT, INTEGER_CONSTANT_NT, FLOAT_CONSTANT_NT,
COMPARATORet_NT, COMPARATORnet_NT, COMPARATORltet_NT, COMPARATORgtet_NT, COMPARATORgt_NT, COMPARATORlt_NT,
CONDITIONALand_NT, CONDITIONALor_NT, CONDITIONALnot_NT, EXPRESSIONadd_NT, EXPRESSIONminus_NT, 
EXPRESSION_NT, TERM_NT, TERMm_NT, TERMd_NT, 
CONDITIONAL_NT, CONDITIONAL_INNER_NT,
TYPEchar_NT, TYPEint_NT , TYPEreal_NT
};  

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    MEM_SIZE  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };
typedef int bool;
typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
void destroy_nodes_from(TERNARY_TREE pt);
void diagnosticsMode(TERNARY_TREE pt);
void indentController(int direction, int * current);
void generate_output(TERNARY_TREE ParseTree);
void do_optimisations(TERNARY_TREE pt, TERNARY_TREE * feedback);
int generateTypedTable(TERNARY_TREE pt, int thingof);
void cast(TERNARY_TREE pt, TERNARY_TREE * from);
void maketypelist(TERNARY_TREE pt);
void PRINT_TREE(TERNARY_TREE pt);
void CODE_TREE(TERNARY_TREE pt);
void simplify(TERNARY_TREE pt, TERNARY_TREE * replacetree);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;


#line 169 "spltab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    NUMBER = 259,
    CHARLITERAL = 260,
    FLOAT = 261,
    ENDP = 262,
    DECLARATIONS = 263,
    CODE = 264,
    OF = 265,
    TYPE = 266,
    CHARACTER = 267,
    INTEGER = 268,
    REAL = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ENDIF = 273,
    DO = 274,
    ENDDO = 275,
    WHILE = 276,
    ENDWHILE = 277,
    FOR = 278,
    IS = 279,
    BY = 280,
    TO = 281,
    ENDFOR = 282,
    WRITE = 283,
    READ = 284,
    NEWLINE = 285,
    AND = 286,
    OR = 287,
    NOT = 288,
    ET = 289,
    NET = 290,
    LT = 291,
    GT = 292,
    LTET = 293,
    GTET = 294,
    ADD = 295,
    MINUS = 296,
    DIVIDE = 297,
    MULTIPLY = 298,
    LCBRAC = 299,
    RCBRAC = 300,
    ASSIGN = 301,
    POINT = 302,
    COMMA = 303,
    SEMICOLON = 304,
    COLON = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 118 "spl.y" /* yacc.c:355  */

    int iVal;
    TERNARY_TREE  tVal;

#line 262 "spltab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 279 "spltab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   153,   157,   162,   166,   171,   175,   180,
     184,   188,   193,   197,   202,   206,   210,   214,   218,   222,
     226,   231,   236,   240,   245,   250,   255,   261,   265,   270,
     275,   279,   284,   288,   292,   296,   301,   306,   310,   314,
     318,   322,   326,   331,   335,   339,   344,   349,   353,   359,
     363,   367,   373,   377,   383,   387,   391,   395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "NUMBER", "CHARLITERAL",
  "FLOAT", "ENDP", "DECLARATIONS", "CODE", "OF", "TYPE", "CHARACTER",
  "INTEGER", "REAL", "IF", "THEN", "ELSE", "ENDIF", "DO", "ENDDO", "WHILE",
  "ENDWHILE", "FOR", "IS", "BY", "TO", "ENDFOR", "WRITE", "READ",
  "NEWLINE", "AND", "OR", "NOT", "ET", "NET", "LT", "GT", "LTET", "GTET",
  "ADD", "MINUS", "DIVIDE", "MULTIPLY", "LCBRAC", "RCBRAC", "ASSIGN",
  "POINT", "COMMA", "SEMICOLON", "COLON", "$accept", "program", "block",
  "declaration_block", "identifier_list", "type", "statement_list",
  "statement", "assignment_statement", "if_statement", "do_statement",
  "while_statement", "for_statement", "write_statement", "read_statement",
  "output_list", "conditional", "conditional_inner", "comparator",
  "expression", "term", "value", "constant", "number_constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -33,    31,    13,   -47,    45,    22,    52,   -47,    69,
      -9,   -47,   -47,   -47,   -47,    64,    22,    64,    82,    29,
      48,   -47,    34,    30,    40,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -22,    51,   -47,   -47,   -47,    93,    22,
      95,   101,    64,    91,    67,    75,    -5,    98,    96,    30,
     118,   -47,   -47,    36,    22,    30,    30,   119,    30,    30,
      76,    40,    70,   -47,   -47,    22,    64,    64,   -47,   -47,
     -47,   -47,   -47,   -47,    30,    64,    22,    30,   -39,   -47,
      79,   -47,   -47,    51,    51,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,    77,    -3,   -47,   -47,    62,   105,    -2,    50,
     -47,    30,   -47,    45,    22,   -47,   -47,   -47,    30,   -47,
     -47,    -7,    46,   -47,    30,    39,    22,   -19,   -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     7,     0,
       0,    49,    54,    53,    56,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     4,    12,    14,    15,    16,    17,
      18,    19,    20,     0,    43,    46,    50,    52,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,    55,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     8,    35,     0,     0,     0,    37,    38,
      39,    40,    41,    42,     0,     0,     0,     0,     0,    30,
       0,    51,    13,    44,    45,    21,    48,    47,     2,     9,
      10,    11,     0,     0,    33,    34,    36,     0,     0,     0,
      27,     0,    29,     5,     0,    23,    24,    25,     0,    31,
       6,     0,     0,    22,     0,     0,     0,     0,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,    24,   -47,   -47,   -16,    74,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -10,   -47,   -47,   -13,
      63,   -46,   -47,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    92,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    78,    43,    44,    74,    33,
      34,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    40,    45,    79,    45,     1,   100,    47,   118,   101,
      53,   113,    86,    87,   104,   105,    75,     3,    55,    56,
     107,     5,     6,    61,    57,    11,    12,    13,    14,    45,
      54,     4,    64,    11,    12,    13,    14,    15,    51,    41,
      52,    16,    54,    17,    54,    18,    54,    54,     8,    93,
      19,    20,    21,    45,    45,   109,    94,    95,   116,    38,
      98,    96,    45,    22,    99,    97,    23,    11,    12,    13,
      14,    22,   114,    49,    23,   108,    55,    56,    39,    55,
      56,    81,    89,    90,    91,    48,    55,    56,   111,    54,
      55,    56,    50,    58,    59,   112,    60,    42,    66,    67,
     117,   115,    55,    56,    63,    22,    62,    65,    23,    68,
      69,    70,    71,    72,    73,    55,    56,    76,    83,    84,
      77,    80,    85,    88,   102,   106,   103,   110,    82
};

static const yytype_uint8 yycheck[] =
{
      16,    10,    15,    49,    17,     3,    45,    17,    27,    48,
      23,    18,    58,    59,    17,    18,    21,    50,    40,    41,
      22,     8,     9,    39,    46,     3,     4,     5,     6,    42,
      49,     0,    42,     3,     4,     5,     6,    15,     4,    48,
       6,    19,    49,    21,    49,    23,    49,    49,     3,    65,
      28,    29,    30,    66,    67,   101,    66,    67,    19,     7,
      76,    74,    75,    41,    77,    75,    44,     3,     4,     5,
       6,    41,    26,    44,    44,    25,    40,    41,     9,    40,
      41,    45,    12,    13,    14,     3,    40,    41,   104,    49,
      40,    41,    44,    42,    43,   108,     3,    33,    31,    32,
     116,   114,    40,    41,     3,    41,    11,    16,    44,    34,
      35,    36,    37,    38,    39,    40,    41,    19,    55,    56,
      24,     3,     3,    47,    45,    20,    49,   103,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    50,     0,     8,     9,    53,     3,    54,
      55,     3,     4,     5,     6,    15,    19,    21,    23,    28,
      29,    30,    41,    44,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    70,    71,    72,    73,    74,     7,     9,
      10,    48,    33,    67,    68,    70,    57,    67,     3,    44,
      44,     4,     6,    70,    49,    40,    41,    46,    42,    43,
       3,    57,    11,     3,    67,    16,    31,    32,    34,    35,
      36,    37,    38,    39,    69,    21,    19,    24,    66,    72,
       3,    45,    58,    71,    71,     3,    72,    72,    47,    12,
      13,    14,    56,    57,    67,    67,    70,    67,    57,    70,
      45,    48,    45,    49,    17,    18,    20,    22,    25,    72,
      54,    57,    70,    18,    26,    70,    19,    57,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    59,    60,    60,    61,    62,    63,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     5,     6,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     7,     5,     5,     5,    11,     4,     1,     4,
       1,     3,     1,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       1,     3,     1,     1,     1,     2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 141 "spl.y" /* yacc.c:1646  */
    {
			TERNARY_TREE ParseTree;
			ParseTree = create_node((yyvsp[-5].iVal), PROGRAM_NT, (yyvsp[-3].tVal), NULL, NULL); 
			if(ParseTree != NULL) 
			{
				generateTypedTable(ParseTree,-1);
				generate_output(ParseTree);
				destroy_nodes_from(ParseTree); //cleanup
				//symbol table also needs a cleanup routine...
			}
		}
#line 1450 "spltab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 154 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, BLOCK_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL); 
		}
#line 1458 "spltab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 158 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, BLOCK_NT, (yyvsp[0].tVal), NULL, NULL);
		}
#line 1466 "spltab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 163 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK_NT, (yyvsp[-4].tVal), (yyvsp[-1].tVal), NULL);
			}
#line 1474 "spltab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 167 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK_NT, (yyvsp[-5].tVal), (yyvsp[-2].tVal), (yyvsp[0].tVal));
			}
#line 1482 "spltab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 172 "spl.y" /* yacc.c:1646  */
    {
					(yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER_LIST_SINGLE_NT, NULL, NULL, NULL);
				}
#line 1490 "spltab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 176 "spl.y" /* yacc.c:1646  */
    {
					(yyval.tVal) = create_node((yyvsp[0].iVal), IDENTIFIER_LIST_NT, (yyvsp[-2].tVal), NULL, NULL);
				}
#line 1498 "spltab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 181 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TYPEchar_NT, NULL, NULL, NULL);
		}
#line 1506 "spltab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 185 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TYPEint_NT, NULL, NULL, NULL);
		}
#line 1514 "spltab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 189 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TYPEreal_NT, NULL, NULL, NULL);
		}
#line 1522 "spltab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST_NT, (yyvsp[0].tVal), NULL, NULL);
		}
#line 1530 "spltab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 198 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
		}
#line 1538 "spltab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 203 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1546 "spltab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1554 "spltab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1562 "spltab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 215 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1570 "spltab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1578 "spltab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 223 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1586 "spltab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 227 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, STATEMENT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1594 "spltab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 232 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), ASSIGNMENT_STATEMENT_NT, (yyvsp[-2].tVal), NULL, NULL);
			}
#line 1602 "spltab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 237 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, IF_STATEMENT_NT, (yyvsp[-5].tVal), (yyvsp[-3].tVal), (yyvsp[-1].tVal));
			}
#line 1610 "spltab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 241 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, IF_STATEMENT_NT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
			}
#line 1618 "spltab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 246 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, DO_STATEMENT_NT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
			}
#line 1626 "spltab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 251 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT_NT, (yyvsp[-3].tVal), (yyvsp[-1].tVal), NULL);
			}
#line 1634 "spltab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 256 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[-9].iVal), FOR_STATEMENT_NT,(TERNARY_TREE)(create_node(NOTHING, FOR_ITERATOR_NT, (yyvsp[-7].tVal), (yyvsp[-5].tVal), (yyvsp[-3].tVal))), (yyvsp[-1].tVal), NULL);
			}
#line 1642 "spltab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 262 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT_NT, (yyvsp[-1].tVal), NULL, NULL);
			}
#line 1650 "spltab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 266 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT_NT, NULL, NULL, NULL);
			}
#line 1658 "spltab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 271 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[-1].iVal), READ_STATEMENT_NT, NULL, NULL, NULL);
			}
#line 1666 "spltab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 276 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_NT, (yyvsp[0].tVal), NULL, NULL);
		}
#line 1674 "spltab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 280 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
		}
#line 1682 "spltab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 285 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONDITIONAL_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1690 "spltab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 289 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONDITIONALand_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
			}
#line 1698 "spltab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 293 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONDITIONALor_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
			}
#line 1706 "spltab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 297 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONDITIONALnot_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1714 "spltab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 302 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONDITIONAL_INNER_NT, (yyvsp[-2].tVal), (yyvsp[-1].tVal), (yyvsp[0].tVal));
			}
#line 1722 "spltab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORet_NT, NULL, NULL, NULL);
			}
#line 1730 "spltab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 311 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORnet_NT, NULL, NULL, NULL);
			}
#line 1738 "spltab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 315 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORlt_NT, NULL, NULL, NULL);
			}
#line 1746 "spltab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 319 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORgt_NT, NULL, NULL, NULL);
			}
#line 1754 "spltab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 323 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORltet_NT, NULL, NULL, NULL);
			}
#line 1762 "spltab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 327 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, COMPARATORgtet_NT, NULL, NULL, NULL);
			}
#line 1770 "spltab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 332 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, EXPRESSION_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1778 "spltab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 336 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, EXPRESSIONadd_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
			}
#line 1786 "spltab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 340 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, EXPRESSIONminus_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
			}
#line 1794 "spltab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 345 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TERM_NT, (yyvsp[0].tVal), NULL, NULL);
		}
#line 1802 "spltab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 350 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TERMm_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
		}
#line 1810 "spltab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 354 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, TERMd_NT, (yyvsp[-2].tVal), (yyvsp[0].tVal), NULL);
		}
#line 1818 "spltab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 360 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node((yyvsp[0].iVal), VALUE_ID_NT, NULL, NULL, NULL);
		}
#line 1826 "spltab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 364 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, VALUE_CL_NT, (yyvsp[0].tVal), NULL, NULL);
		}
#line 1834 "spltab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "spl.y" /* yacc.c:1646  */
    {
			(yyval.tVal) = create_node(NOTHING, VALUE_EX_NT, (yyvsp[-1].tVal), NULL, NULL);
		}
#line 1842 "spltab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 374 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node(NOTHING, CONSTANT_NT, (yyvsp[0].tVal), NULL, NULL);
			}
#line 1850 "spltab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 378 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), CONSTANTchl_NT, NULL, NULL, NULL);
			}
#line 1858 "spltab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 384 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			}
#line 1866 "spltab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 388 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((-(yyvsp[0].iVal)), INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			}
#line 1874 "spltab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 392 "spl.y" /* yacc.c:1646  */
    {
				(yyval.tVal) = create_node((yyvsp[0].iVal), FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			}
#line 1882 "spltab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 396 "spl.y" /* yacc.c:1646  */
    {
				*((double*)((MEM_SIZE)(yyvsp[0].iVal))) = -*((double*)((MEM_SIZE)(yyvsp[0].iVal)));
				(yyval.tVal) = create_node((yyvsp[0].iVal), FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			}
#line 1891 "spltab.c" /* yacc.c:1646  */
    break;


#line 1895 "spltab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 405 "spl.y" /* yacc.c:1906  */


int identityTable[50];

/* Code for routines for managing the Parse Tree */

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

void indentController(int direction, int * current)
{
	*current = *current + (direction * 5);
}

//for write look up table.
char *ntypes[] = {"PROGRAM_NT", "BLOCK_NT", "DECLARATION_BLOCK_NT", "IDENTIFIER_LIST_NT", "IDENTIFIER_LIST_SINGLE_NT", "STATEMENT_LIST_NT", "STATEMENT_NT",
"ASSIGNMENT_STATEMENT_NT", "IF_STATEMENT_NT", "DO_STATEMENT_NT", "WHILE_STATEMENT_NT", "FOR_STATEMENT_NT", "WRITE_STATEMENT_NT", "READ_STATEMENT_NT", "OUTPUT_LIST_NT",
"FOR_ITERATOR_NT", "CONSTANT_NT", "CONSTANTchl_NT", "VALUE_ID_NT", "VALUE_CL_NT" ,"VALUE_EX_NT", "INTEGER_CONSTANT_NT", "FLOAT_CONSTANT_NT","COMPARATORet_NT", "COMPARATORnet_NT",
"COMPARATORltet_NT", "COMPARATORgtet_NT", "COMPARATORgt_NT", "COMPARATORlt_NT", "CONDITIONALand_NT", "CONDITIONALor_NT", "CONDITIONALnot_NT", "EXPRESSIONadd_NT", "EXPRESSIONminus_NT", 
"EXPRESSION_NT", "TERM_NT", "TERMm_NT", "TERMd_NT", "CONDITIONAL_NT", "CONDITIONAL_INNER_NT", "TYPEchar_NT", "TYPEint_NT" , "TYPEreal_NT"};
void generate_output(TERNARY_TREE pt)
{	
	#ifndef DEBUG	
		printf("#include<stdio.h>\n\n");
		CODE_TREE(pt);
	#else
		diagnosticsMode(pt);
	#endif
}	

void diagnosticsMode(TERNARY_TREE pt)
{
	printf("\n/*\n--------------------diagnostics--------------------\n");
	PRINT_TREE(pt);
	printf("\n--------------------end of diag--------------------\n*/\n");
}

void PRINT_TREE(TERNARY_TREE pt)
{
	static int indent =0;
	static bool indenton = TRUE;

	if(pt==NULL) return; 

	printf("%*s",indent, " ");
	
	if(pt->nodeIdentifier == VALUE_ID_NT || pt->nodeIdentifier == CONSTANTchl_NT ||  pt->nodeIdentifier == IDENTIFIER_LIST_NT ||  pt->nodeIdentifier == IDENTIFIER_LIST_SINGLE_NT)
	{
		printf("%s has value: %s\n\n", ntypes[pt->nodeIdentifier], symTab[pt->item]->identifier);
	}
	else if(pt->nodeIdentifier == INTEGER_CONSTANT_NT)
	{
		printf("%s has value: %i\n\n", ntypes[pt->nodeIdentifier], pt->item);
	}
	else if(pt->nodeIdentifier == FLOAT_CONSTANT_NT)
	{
		printf("%s has value: %f\n\n", ntypes[pt->nodeIdentifier], *((double*)((MEM_SIZE)pt->item)));	
	}
	else 
	{
		printf("%s\n", ntypes[pt->nodeIdentifier]);	
	}

	if(indenton)
	{ 
		if(pt->nodeIdentifier == PROGRAM_NT ||  pt->nodeIdentifier == BLOCK_NT || pt->nodeIdentifier == DECLARATION_BLOCK_NT 
		||  pt->nodeIdentifier ==  STATEMENT_NT || (pt->nodeIdentifier >=7 && pt->nodeIdentifier <=13))
		{
			indentController(1, &indent); //incriment
		}
	}
	if(pt->nodeIdentifier != STATEMENT_LIST_NT && pt->nodeIdentifier != IDENTIFIER_LIST_NT)
	{
		PRINT_TREE(pt->first);	
		PRINT_TREE(pt->second);	
		PRINT_TREE(pt->third);	
	}
	else 
	{
		PRINT_TREE(pt->second);	
		PRINT_TREE(pt->first);	
	}
	if(indenton)
	{ 
		if(pt->nodeIdentifier == PROGRAM_NT ||  pt->nodeIdentifier == BLOCK_NT || pt->nodeIdentifier == DECLARATION_BLOCK_NT 
		||  pt->nodeIdentifier ==  STATEMENT_NT || (pt->nodeIdentifier >=7 && pt->nodeIdentifier <=13))
		{
			indentController(-1, &indent); //decriment
		}
	}
	
}

const int stackmaxlimit = 100;
MEM_SIZE stackdata[100];
int stackcounter=0;

void typepop()
{
	if(stackcounter>0)
	stackdata[stackcounter--]=(MEM_SIZE)NULL;
}
void typequeue()
{
	if(stackcounter>1)
	{
		memmove(stackdata, stackdata+1, sizeof(MEM_SIZE) * (stackcounter-1));
		stackcounter--;
	}
}
void typepush(MEM_SIZE newitem)
{
	if(stackcounter<stackmaxlimit)
	stackdata[stackcounter++]=newitem;
	
	//printf("push!%i\n", stackcounter);
}
MEM_SIZE typetop()
{
	if(stackcounter>0)
	return stackdata[stackcounter-1];
	else
	return NULL;
}
MEM_SIZE typebottom()
{
	if(stackcounter>0)
	return stackdata[0];
	else
	return NULL;
}
void typeclearstack()
{
	int i=0;
	for(i=0; i<stackcounter; i++)
	{
		stackdata[i]=(MEM_SIZE)NULL;
	}
	stackcounter=0;
}

int idtypes[50];
int ctype=-1;
bool firstfor=TRUE;

void CODE_TREE(TERNARY_TREE pt)
{	
	static char * carryOverId;
	static int outlistCount=0;
	static int lookAheadOnly=0;

	static int indent =0;
	if(pt==NULL) return;
	
	switch(pt->nodeIdentifier)
	{
		case PROGRAM_NT:			
			printf("int main() /*Program %s*/\n{\n", symTab[pt->item]->identifier);
			CODE_TREE(pt->first);
			printf("}/*End of Program*/\n");
			break;
		case BLOCK_NT:			
			indentController(1, &indent); //incriment
			if(pt->second == NULL)
			{ /*code only*/
				printf("%*s/*CODE*/\n",indent, " ");
				CODE_TREE(pt->first);
			}
			else
			{
				printf("%*s/*DECLARCATION_BLOCK*/\n",indent, " "); 
				CODE_TREE(pt->first);
				printf("%*s/*CODE_BLOCK*/\n",indent, " "); 
				CODE_TREE(pt->second);
			}
			indentController(-1, &indent); //decriment
			break;
		case DECLARATION_BLOCK_NT:
			if(pt->first !=NULL)
			{	
				printf("%*s", indent, "    ");
				CODE_TREE(pt->second);
				printf(" ");
				CODE_TREE(pt->first); 
				printf(";\n");
			}
			ctype=-1;
			CODE_TREE(pt->third); //are there more?
			break;
		case IDENTIFIER_LIST_NT:
			CODE_TREE(pt->first);
			idtypes[pt->item] = ctype;
			printf("%s%s", ", ", symTab[pt->item]->identifier);
			break;
		case IDENTIFIER_LIST_SINGLE_NT:
			printf("%s",symTab[pt->item]->identifier);
			idtypes[pt->item] = ctype;
			break;
		case TYPEchar_NT:
			ctype = TYPEchar_NT;
			printf("char");
			break;
		case TYPEint_NT:
			ctype = TYPEint_NT;
			printf("int");
			break;
		case TYPEreal_NT:
			ctype = TYPEreal_NT;
			printf("float");
			break;
		case STATEMENT_LIST_NT:
			CODE_TREE(pt->first); //statement list
			CODE_TREE(pt->second); //statement
			break;
		case STATEMENT_NT:
			//indentController(1, &indent); //incriment
			printf("%*s", indent, "    ");
			CODE_TREE(pt->first);
			//indentController(-1, &indent); //decriment
			printf("\n");
			break;
		case ASSIGNMENT_STATEMENT_NT:
			printf("%s",symTab[pt->item]->identifier);
			printf(" = ");
			do_optimisations(pt->first, &(pt->first));
			CODE_TREE(pt->first);
			printf(";");
			break;
		case IF_STATEMENT_NT:	
			printf("if(");
			CODE_TREE(pt->first);
			printf(")\n%*s{\n",indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			if(pt->third!=NULL)
			{
				printf("%*s}\n%*selse\n%*s{\n", indent, "    ", indent, "    ", indent, "    ");
				indentController(1, &indent); //incriment
				CODE_TREE(pt->third);
				indentController(-1, &indent); //decriment
			}
			printf("%*s}", indent, "    ");
			break;	
		case DO_STATEMENT_NT:
			printf("do\n%*s{\n", indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->first);
			indentController(-1, &indent); //decriment
			printf("%*s} while (",indent, " ");
			CODE_TREE(pt->second);
			printf(");");
			break;
		case WHILE_STATEMENT_NT:
			printf("while (");	
			CODE_TREE(pt->first);
			printf(")\n%*s{\n", indent, " ");	
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			printf("%*s}", indent, " ");
			break;	
		case FOR_STATEMENT_NT:
			if(firstfor)
			{
				printf("/*for control vars*/\n");
				printf("%*sregister int _by;\n",indent, " ");
 				printf("%*sstatic int _true=(1==1);\n",indent, " ");
				printf("%*s", indent, " ");
				firstfor = FALSE;
			}
			
			carryOverId=symTab[pt->item]->identifier;
			printf("for (%s = ",symTab[pt->item]->identifier);
			CODE_TREE(pt->first);
			printf(")\n%*s{\n",indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			printf("%*s}", indent, " ");
			carryOverId=NULL;
			break;	
		case FOR_ITERATOR_NT:
			do_optimisations(pt->first, &(pt->first));
			do_optimisations(pt->third, &(pt->third));
			do_optimisations(pt->second, &(pt->second));
			// for (i=is; _by=by, (i-to)*((_by > 0) - (_by < 0)/_true) <= 0 ; i += _by) magic...
			printf("(");
			CODE_TREE(pt->first);	
			printf("); _by =  (");
			CODE_TREE(pt->second);
			printf("), (%s - (", carryOverId);
			CODE_TREE(pt->third);
			printf("))*(_by >0) - (_by<0/_true) <=0; %s += _by", carryOverId);
			break;	
			//first is IS. Second is BY. Third is TO. i is CarryOverId
		case WRITE_STATEMENT_NT:
			printf("printf(");
			if(pt->first==NULL)
			{
				printf("%s\\n%s);","\"","\"");
			}
			else
			{	
				lookAheadOnly = 1;
				printf("\"");
				CODE_TREE(pt->first); //for the output list...
				int copystack = stackcounter;
				int i;
				for(i=0; i<copystack; i++)
				{
					TERNARY_TREE t = (TERNARY_TREE)typebottom();
					if(t->nodeIdentifier == FLOAT_CONSTANT_NT)
					{
						printf("%%f");
					}
					else if (t->nodeIdentifier == INTEGER_CONSTANT_NT)
					{
						printf("%%i");
					}
					else if (t->nodeIdentifier == CONSTANTchl_NT)
					{
						printf("%%c");
					}
					else 
					{
						if(idtypes[t->item] == TYPEchar_NT)
						{
							printf("%%c");
						}
						else if(idtypes[t->item] == TYPEint_NT)
						{
							printf("%%i");
						}
						else if(idtypes[t->item] == TYPEreal_NT)
						{
							printf("%%f");
						}
						
					}
					
					typequeue();
				}
				typeclearstack();
				lookAheadOnly = 0;
				printf("\", ");	
				CODE_TREE(pt->first);
				printf(");");
				typeclearstack();
			}
			break;
		case READ_STATEMENT_NT:
			printf("scanf(");
			printf("\"%%%c\", ", (idtypes[pt->item] == TYPEreal_NT)? 'f' : ((idtypes[pt->item] == TYPEchar_NT)? 'c' : 'i'));
			printf("&%s",symTab[pt->item]->identifier);
			printf(");");
			break;
		case OUTPUT_LIST_NT:
			
			if(pt->second==NULL)
			{
				do_optimisations(pt->first, &(pt->first));
				maketypelist(pt->first);
				CODE_TREE(pt->first);
			}
			else
			{
				CODE_TREE(pt->first);
				if(lookAheadOnly!=1) printf(", ");
				do_optimisations(pt->second, &(pt->second));
				maketypelist(pt->second);
				CODE_TREE(pt->second);
			}
			break;
		case CONDITIONAL_NT:	
			CODE_TREE(pt->first);
			break;
		case CONDITIONALand_NT:		
			CODE_TREE(pt->first);
			printf(" && ");
			CODE_TREE(pt->second);
			break;
		case CONDITIONALor_NT:
			CODE_TREE(pt->first);
			printf(" || ");
			CODE_TREE(pt->second);
			break;
		case CONDITIONALnot_NT:
			printf("! (");
			CODE_TREE(pt->first);
			printf(")");
			break;
		case CONDITIONAL_INNER_NT:
			do_optimisations(pt->first, &(pt->first));
			CODE_TREE(pt->first);
			do_optimisations(pt->second, &(pt->second));
			CODE_TREE(pt->second);
			do_optimisations(pt->third, &(pt->third));
			CODE_TREE(pt->third);
			break;
		case COMPARATORet_NT:
			printf(" == ");
			break;
		case COMPARATORnet_NT:
			printf(" != ");
			break;
		case COMPARATORlt_NT:
			printf(" < ");
			break;
		case COMPARATORgt_NT:
			printf(" > ");
			break;
		case COMPARATORltet_NT:	
			printf(" <= ");
			break;
		case COMPARATORgtet_NT:
			printf(" >= ");
			break;
		case EXPRESSION_NT:
			CODE_TREE(pt->first);
			break;
		case EXPRESSIONadd_NT:
			CODE_TREE(pt->first);	
			printf(" + ");
			CODE_TREE(pt->second);
			break;
		case EXPRESSIONminus_NT:
			CODE_TREE(pt->first);
			printf(" - ");
			CODE_TREE(pt->second);
			break;
		case TERM_NT:
			CODE_TREE(pt->first);
			break;
		case TERMm_NT:
			CODE_TREE(pt->first);
			printf(" * ");
			CODE_TREE(pt->second);
			break;
		case TERMd_NT:
			CODE_TREE(pt->first);
			printf(" / ");
			CODE_TREE(pt->second);
			break;
		case VALUE_ID_NT:	
			//printf("identifier");
			if(lookAheadOnly==1){outlistCount++; return;};
			printf("%s",symTab[pt->item]->identifier);
			break;
		case VALUE_CL_NT:
			if(lookAheadOnly==1){outlistCount++; return;};
			CODE_TREE(pt->first);
			break;
		case VALUE_EX_NT:
			if(lookAheadOnly==1){outlistCount++; return;};
			printf("(");
			CODE_TREE(pt->first);
			printf(") ");
			break;
		case CONSTANT_NT:
			CODE_TREE(pt->first);
			break;
		case CONSTANTchl_NT:
			printf("'%s'",symTab[pt->item]->identifier);
			//printf("char");
			break;
		case INTEGER_CONSTANT_NT:
			if(lookAheadOnly==1) return;
			printf("%i", pt->item);
			break;
		case FLOAT_CONSTANT_NT:
			if(lookAheadOnly==1) return;
			double * value = (double*)((MEM_SIZE)pt->item);
			printf("%f", *value);
			break;
	}
}


enum STACKTYPE {st_CMD, st_DATA};
enum operations {o_add, o_sub, o_div, o_mul};
int CommandStack[100];

struct cmdStack
{
	MEM_SIZE stk[128];
	int count;
	
}commandStack;

struct Stack
{
	TERNARY_TREE stk[512];
	int count;
	
}nodeStack;

void wipestack(int operationalmode)
{
	if(operationalmode == st_DATA)
	{
		nodeStack.count=0;
		int i;
		for(i=0; i<nodeStack.count; i++)
		{
			nodeStack.stk[i] = NULL;
		}
	}
	else
	{
		commandStack.count=0;
		int i;
		for(i=0; i<commandStack.count; i++)
		{
			commandStack.stk[i] = (MEM_SIZE)NULL;
		}
	}
}
void push(int operationalmode, MEM_SIZE node)
{
	if(operationalmode == st_DATA)
	{
		nodeStack.stk[nodeStack.count++]=(TERNARY_TREE)node;
	}
	else
	{
		commandStack.stk[commandStack.count++]=(MEM_SIZE)node; //yes, I know...
	}
}
void pop(int operationalmode)
{
	if(operationalmode == st_DATA)
	{
		if(nodeStack.count>0)
		{
			nodeStack.stk[nodeStack.count-1];
			nodeStack.count--;
		}
	}
	else
	{
		if(commandStack.count>0)
		{
			commandStack.stk[commandStack.count-1];
			commandStack.count--;
		}
	}
}
TERNARY_TREE top(int operationalmode)
{	
	if(operationalmode == st_DATA)
	{
		if(nodeStack.count >0)
		return nodeStack.stk[nodeStack.count-1];
	}
	else
	{	
		if(commandStack.count >0)
		return commandStack.stk[commandStack.count-1];
	}
}


void do_optimisations(TERNARY_TREE pt, TERNARY_TREE * feedback)
{
	wipestack(st_DATA); wipestack(st_CMD);
	simplify(pt, feedback);
}

void simplify(TERNARY_TREE pt, TERNARY_TREE * replacetree)
{	
	//printf("%i\n", pt->nodeIdentifier);
	if (pt==NULL) return;
	switch(pt->nodeIdentifier)
	{
		case EXPRESSION_NT:
			simplify(pt->first, replacetree);
			break;
		case EXPRESSIONadd_NT:
			//printf("\n-------------------STACK:ADD\n");
			push(st_CMD,(MEM_SIZE)o_add);
			cast(pt, replacetree);
			//printf("ADD EXIT\n");
			break;
		case EXPRESSIONminus_NT:
			//printf("\n-------------------STACK:SUBTRACT\n");
			push(st_CMD,(MEM_SIZE)o_sub);
			cast(pt, replacetree);
			//printf("SUB EXIT\n");
			break;
		case TERM_NT:
			simplify(pt->first, replacetree);
			break;
		case TERMm_NT:
			//printf("\n-------------------STACK:MULTIPLY\n");
			push(st_CMD,(MEM_SIZE)o_mul);
			cast(pt, replacetree);
			//printf("MUL EXIT\n");
			break;
		case TERMd_NT:
			//printf("\n-------------------STACK:DIVIDE\n");
			push(st_CMD,(MEM_SIZE)o_div);
			cast(pt, replacetree);
			break;
		case VALUE_ID_NT:
			push(st_DATA, (MEM_SIZE)pt);
			//printf("\n-------------------STACK:IDENTIFIER\n");
			break;
		case VALUE_CL_NT:
			simplify(pt->first, replacetree);
			break;
		case VALUE_EX_NT:
			simplify(pt->first, replacetree);
			break;
		case CONSTANT_NT:
			simplify(pt->first, replacetree);
			break;
		case CONSTANTchl_NT:
			push(st_DATA,(MEM_SIZE)pt);
			//printf("\n-------------------STACK:CHAR:%c\n", pt->item);
			break;
		case INTEGER_CONSTANT_NT:
			//printf("\n-------------------STACK:INT:%i\n", pt->item);
			push(st_DATA, (MEM_SIZE)pt);
			break;
		case FLOAT_CONSTANT_NT:
			//printf("\n-------------------STACK:FLOAT:%f\n", *((double*)pt->item));
			push(st_DATA, (MEM_SIZE)pt);
			break;
	}
}

void evalDuplicares(MEM_SIZE cpy1, MEM_SIZE cpy2)
{
			bool isFloat1=FALSE, isFloat2=FALSE, isInt1=FALSE, isInt2=FALSE, isChr1=FALSE, isChr2 = FALSE, isID1 = FALSE, isID2 = FALSE;
			switch(((TERNARY_TREE)cpy1)->nodeIdentifier)
			{
				case FLOAT_CONSTANT_NT:
					isFloat1 = TRUE;
					break;
				case INTEGER_CONSTANT_NT:
					isInt1 = TRUE;
					break;
				case CONSTANTchl_NT:
					isChr1 = TRUE;
					break;
				case VALUE_ID_NT:
					isID1 = TRUE;
					break;
			}
			switch(((TERNARY_TREE)cpy2)->nodeIdentifier)
			{
				case FLOAT_CONSTANT_NT:
					isFloat2 = TRUE;
					break;
				case INTEGER_CONSTANT_NT:
					isInt2 = TRUE;
					break;
				case CONSTANTchl_NT:
					isChr2 = TRUE;
					break;
				case VALUE_ID_NT:
					isID2 = TRUE;
					break;
			}
			//if id...
			if(isID1 == TRUE)
			{
				switch(idtypes[((TERNARY_TREE)cpy1)->item])
				{
					case TYPEchar_NT:
						isChr1 = TRUE;
						break;
					case TYPEint_NT:
						isInt1 = TRUE;
						break;
					case TYPEreal_NT:
						isFloat1 = TRUE;
						break;
				}
			}
			if(isID2 == TRUE)
			{
				switch(idtypes[((TERNARY_TREE)cpy2)->item])
				{
					case TYPEchar_NT:
						isChr2 = TRUE;
						break;
					case TYPEint_NT:
						isInt2 = TRUE;
						break;
					case TYPEreal_NT:
						isFloat2 = TRUE;
						break;
				}
			}
			typepop();
			typepop();
			//ghandles float...
			if(isFloat1)
			{
				typepush(cpy1);
			}
			else if(isFloat2)
			{
				typepush(cpy2);
			}
			if(isChr1 && isChr2)
			{
				typepush(cpy1);
			}
			if(isInt1 && isInt2)
			{
				typepush(cpy1);
			}
			
			if(isChr1 && isInt2)
			{
				typepush(cpy2);
			}
			else if(isChr2 && isInt1)
			{
				typepush(cpy1);
			}
}

void maketypelist(TERNARY_TREE pt)
{	
	MEM_SIZE cpy1 = NULL;
	MEM_SIZE cpy2 = NULL;
	//printf("%i\n", pt->nodeIdentifier);
	if (pt==NULL) return;
	switch(pt->nodeIdentifier)
	{
		case EXPRESSION_NT:
			maketypelist(pt->first);
			break;
		case EXPRESSIONadd_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case EXPRESSIONminus_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case TERM_NT:
			maketypelist(pt->first);
			break;
		case TERMm_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case TERMd_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case VALUE_ID_NT:
			typepush((MEM_SIZE)pt);
			break;
		case VALUE_CL_NT:
			maketypelist(pt->first);
			break;
		case VALUE_EX_NT:
			maketypelist(pt->first);
			break;
		case CONSTANT_NT:
			maketypelist(pt->first);
			break;
		case CONSTANTchl_NT:
			typepush((MEM_SIZE)pt);
			break;
		case INTEGER_CONSTANT_NT:
			typepush((MEM_SIZE)pt);
			break;
		case FLOAT_CONSTANT_NT:
			typepush((MEM_SIZE)pt);
			break;
	}
}

int generateTypedTable(TERNARY_TREE pt, int thingof)
{
	if(pt==NULL) return thingof;
	
	switch(pt->nodeIdentifier)
	{
		case PROGRAM_NT:			
			generateTypedTable(pt->first,thingof);
			break;
		case BLOCK_NT:			
			generateTypedTable(pt->first,thingof);
			break;
		case DECLARATION_BLOCK_NT:
			if(pt->first !=NULL)
			{	
				generateTypedTable(pt->first,generateTypedTable(pt->second,thingof));
			}
			generateTypedTable(pt->third,thingof); //are there more?
			break;
		case IDENTIFIER_LIST_NT:
			generateTypedTable(pt->first,thingof);
			return thingof;
		case IDENTIFIER_LIST_SINGLE_NT:
			//printf("id...\n");
			identityTable[pt->item] = thingof;
			return thingof;
		case TYPEchar_NT:
			//printf("char\n");
			return TYPEchar_NT;
		case TYPEint_NT:
			//printf("int\n");
			return TYPEint_NT;
		case TYPEreal_NT:	
			//printf("real\n");
			return TYPEreal_NT;
	}
	return -1;
}

void cast(TERNARY_TREE pt, TERNARY_TREE * from)
{
	//printf("cast\n");
	if(pt==NULL) return;
	
	//search subtrees
	simplify(pt->first, &(pt->first));
	simplify(pt->second, &(pt->second));
	//printf("\n-------------------data:%i. cmd:%i\n", nodeStack.count, commandStack.count);
	if(nodeStack.count >= 2 && commandStack.count>=1)
	{	/*optimise*/
		TERNARY_TREE newsubtree=NULL;
		TERNARY_TREE node1 = top(st_DATA); pop(st_DATA);
		//printf("%i\n", node1->item);
		TERNARY_TREE node2 = top(st_DATA); pop(st_DATA);
		int action = (MEM_SIZE)top(st_CMD); pop(st_CMD);
		//printf("%i\n", action);
		//printf("%i\n", node2->item);	
		//fasle false 
		if(!(node1->nodeIdentifier == VALUE_ID_NT) && !(node2->nodeIdentifier == VALUE_ID_NT))
		{
			//printf("optimise\n");	

			//create vars
			double d_operand1=0.0, d_operand2=0.0;
			int i_operand1=0, i_operand2=0;
			bool isSet_DO1=FALSE, isSet_DO2=FALSE, isSet_IO1=FALSE, isSet_IO2=FALSE;

			//do type check evaluation.
			if(node1->nodeIdentifier==FLOAT_CONSTANT_NT)
			{
				d_operand1 = *((double*)((MEM_SIZE)node1->item));
				isSet_DO1 = TRUE;
				if(node2->nodeIdentifier == FLOAT_CONSTANT_NT)
				{
					d_operand2 = *((double*)((MEM_SIZE)node2->item));
					isSet_DO2 = TRUE;
				}
				else
				{
					i_operand1 = node2->item;
					isSet_IO1 = TRUE;
				}	
			}
			else
			{
				i_operand1 = node1->item;
				isSet_IO1 = TRUE;
				if(node2->nodeIdentifier==FLOAT_CONSTANT_NT)
				{
					d_operand1 = *((double*)((MEM_SIZE)node2->item));
					isSet_DO1 = TRUE;	
				}
				else
				{
					i_operand2 = node2->item;
					isSet_IO2 = TRUE;
				}
			}
			//printf("------------------------%i%i\n", isSet_IO1, isSet_IO2);
			//make result spaces.
			double * d_result = malloc(sizeof(double)); 
			int i_result=0;
			bool result_is_double = FALSE;
			//final type eval. Then calculate using operator.
			if(isSet_DO1 && isSet_DO2) //double double calc.
			{
				//printf("do float calc\n");
				switch(action)
				{
					case o_add:
						*d_result = d_operand2 + d_operand1;
						break;
					case o_sub:
						*d_result =  d_operand2 - d_operand1;
						break;
					case o_mul:
						*d_result =  d_operand2 * d_operand1;
						break;
					case o_div:
						*d_result =  d_operand2 / d_operand1;
						break;
				}
				result_is_double = TRUE;
				//printf("%f\n", *d_result);
			}
			else if(isSet_IO1 && isSet_IO2) //int int calc.
			{
				//printf("do int calc\n");
				switch(action)
				{
					case o_add:
						i_result = i_operand2 + i_operand1;
						break;
					case o_sub:
						i_result =  i_operand2 - i_operand1;
						break;
					case o_mul:
						i_result =  i_operand2 * i_operand1;
						break;
					case o_div:
						i_result =  i_operand2 / i_operand1;
						break;
				}
				//printf("%i\n", i_result);		
			}
			else if(((bool)(isSet_DO1 + isSet_DO2)) && ((bool)(isSet_IO1 + isSet_IO2))) //hyrid calculations...
			{
				//compress...
				d_operand1= d_operand1 + d_operand2;
				i_operand1= i_operand1 + i_operand2;
				if(isSet_DO1) // float is Op_2.
				{
					switch(action)
					{
						case o_add:
							*d_result = d_operand1 + (double)i_operand1;
							break;
						case o_sub:
							*d_result = d_operand1 - (double)i_operand1;
							break;
						case o_mul:
							*d_result = d_operand1 * (double)i_operand1;
							break;
						case o_div:
							*d_result = d_operand1 / (double)i_operand1;
							break;
					}	
				}
				else // int is Op_2.
				{
					switch(action)
					{
						case o_add:
							*d_result = (double)i_operand1 + d_operand1;
							break;
						case o_sub:
							*d_result = (double)i_operand1 - d_operand1;
							break;
						case o_mul:
							*d_result = (double)i_operand1 * d_operand1;
							break;
						case o_div:
							*d_result = (double)i_operand1 / d_operand1;
							break;
					}
				}

				result_is_double = TRUE;
				//printf("%f\n", *d_result);
			}


			//destroy old subtree.
			destroy_nodes_from(*from); pt=NULL;
			//make new subtree, then add it in place of the old.
			newsubtree = create_node(NOTHING, EXPRESSION_NT, NULL, NULL, NULL);
			newsubtree->first = create_node(NOTHING, TERM_NT, NULL, NULL, NULL);
			newsubtree->first->first = create_node(NOTHING, VALUE_CL_NT, NULL, NULL, NULL);
			newsubtree->first->first->first = create_node(NOTHING, CONSTANT_NT, NULL, NULL, NULL);
			if(result_is_double)
				newsubtree->first->first->first->first = create_node((MEM_SIZE)d_result, FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			else
				newsubtree->first->first->first->first = create_node(i_result, INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			*from=newsubtree;
			push(st_DATA,(MEM_SIZE)newsubtree->first->first->first->first);	
		}	
	}
}

void destroy_nodes_from(TERNARY_TREE pt)
{
	if(pt==NULL) return;
	destroy_nodes_from(pt->first);
	destroy_nodes_from(pt->second);
	destroy_nodes_from(pt->third);
	//printf("destroy %i\n", pt);

	if(pt->nodeIdentifier == FLOAT_CONSTANT_NT)
	{
		double * freeme = (double*)((MEM_SIZE)pt->item);
		free(freeme);
	}
	//printf("record deleted");
	free(pt);
	pt=NULL;
}





/* Put other auxiliary functions here */

#include "lex.yy.c"


