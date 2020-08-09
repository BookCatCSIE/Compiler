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
#line 2 "compiler_hw2.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(int);
    static void insert_symbol(char*,int);
    static void lookup_symbol();
    static void dump_symbol(int);
/*
    typedef union _all_type{
        int itype;
        float ftype;
        char* strtype;
        bool btype;
    }all_type;
*/

/*
    typedef struct {
        int unique_value;
        struct Address* prev;
        struct Address* next;
    }Address;
*/

    typedef struct {
        int index;
        char* name;
        char* type;
        int address;
        int line_number;
        char* array_element_type;
    }Table_element;

    typedef struct {
        int element_num;
        Table_element te[100];
        struct Symbol_Table* prev;
        struct Symbol_Table* next;
    }Symbol_Table;

    int now_scope_level = 0;

    Symbol_Table my_table[50];
    
    int total_address = 0;

    int into_block =0; //in09
    int scope_dif =0; //in09

#line 128 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    INC = 263,
    DEC = 264,
    GEQ = 265,
    LEQ = 266,
    EQL = 267,
    NEQ = 268,
    ADD_ASSIGN = 269,
    SUB_ASSIGN = 270,
    MUL_ASSIGN = 271,
    QUO_ASSIGN = 272,
    REM_ASSIGN = 273,
    LAND = 274,
    LOR = 275,
    NEWLINE = 276,
    PRINT = 277,
    PRINTLN = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    TRUE = 282,
    FALSE = 283,
    INT_LIT = 284,
    FLOAT_LIT = 285,
    STRING_LIT = 286,
    IDENT = 287
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define INC 263
#define DEC 264
#define GEQ 265
#define LEQ 266
#define EQL 267
#define NEQ 268
#define ADD_ASSIGN 269
#define SUB_ASSIGN 270
#define MUL_ASSIGN 271
#define QUO_ASSIGN 272
#define REM_ASSIGN 273
#define LAND 274
#define LOR 275
#define NEWLINE 276
#define PRINT 277
#define PRINTLN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define TRUE 282
#define FALSE 283
#define INT_LIT 284
#define FLOAT_LIT 285
#define STRING_LIT 286
#define IDENT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char* s_val;
    /* ... */
    //char* id_val;
    //all_type type;

#line 241 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     8,     2,     2,    13,     2,     2,
      31,    32,    11,     9,    38,    10,     2,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      17,    22,    16,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
       5,     6,     7,    14,    15,    18,    19,    20,    21,    23,
      24,    25,    26,    27,    28,    29,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   130,   131,   135,   136,   137,   138,   139,
     140,   141,   145,   190,   206,   207,   208,   209,   213,   218,
     222,   223,   227,   231,   235,   239,   243,   244,   245,   246,
     247,   248,   251,   255,   299,   327,   331,   332,   333,   361,
     365,   369,   371,   375,   379,   383,   384,   385,   389,   390,
     399,   416,   417,   418,   419,   420,   421,   449,   455,   480,
     482,   483,   484,   485,   486,   487,   488,   494,   494,   502,
     502,   521,   522,   531,   532,   536,   536,   549,   566,   570,
     584
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "'\"'", "'+'", "'-'", "'*'", "'/'", "'%'", "INC", "DEC", "'>'", "'<'",
  "GEQ", "LEQ", "EQL", "NEQ", "'='", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "'!'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "';'", "','", "NEWLINE", "PRINT",
  "PRINTLN", "IF", "ELSE", "FOR", "TRUE", "FALSE", "INT_LIT", "FLOAT_LIT",
  "STRING_LIT", "IDENT", "$accept", "Program", "StatementList",
  "Statement", "DeclarationStmt", "TypeName", "Type", "TypeX",
  "Expression", "Expression2", "Expression3", "Expression5", "Expression6",
  "Expression7", "UnaryExpr", "UnaryExprX", "unary_op", "PrimaryExpr",
  "Operand", "SimpleStmt", "Block", "$@1", "IfStmt", "$@2", "IfStmt2",
  "IfStmt3", "ForStmt", "$@3", "ForClause", "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    34,    43,
      45,    42,    47,    37,   263,   264,    62,    60,   265,   266,
     267,   268,    61,   269,   270,   271,   272,   273,   274,   275,
      33,    40,    41,    91,    93,   123,   125,    59,    44,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     217,   -44,   -95,   -95,   -95,   -95,   -23,   -95,   -95,   -95,
     264,   264,   -95,   -95,     8,    15,   264,   264,   -95,   -95,
     -95,   -95,   -95,    24,   217,   -95,    16,   -95,    43,     7,
     118,    48,    62,   110,    25,   -95,   -95,   264,   -95,    57,
     -95,    56,    67,    76,    95,    96,    12,    93,    -7,   -25,
     217,   264,   264,   107,     6,   100,   103,   -95,   -95,   -95,
     264,   264,   -95,   -95,   -95,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   -95,    57,   264,   -95,   -95,   -95,
     -95,   -95,   117,   -95,   -95,   -95,    63,    18,    68,   111,
     -95,   264,   217,    85,    19,   107,   107,   107,   107,   107,
     107,    48,    62,   110,   110,   110,   110,   110,   110,    25,
      25,   -95,   -95,   -95,    20,   264,   -95,   -95,   -95,   105,
     -95,   217,   -14,   121,   -95,   -95,   -95,   107,    -8,   169,
     264,   -95,   -95,   -95,   -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,    15,    17,    16,     0,    45,    46,    47,
       0,     0,    67,    11,     0,     0,     0,     0,    53,    54,
      51,    52,    56,     0,     2,     4,     0,    19,     0,     0,
      64,    23,    25,    32,    35,    39,    40,     0,    44,    42,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    64,     0,     0,     1,     3,     5,
       0,     0,    18,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    41,     0,     6,     7,     8,
       9,    10,    12,    55,    57,    21,     0,     0,     0,     0,
      75,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63,    22,    24,    26,    27,    28,    29,    30,    31,    33,
      34,    36,    37,    38,     0,     0,    68,    79,    80,    71,
      70,     0,     0,     0,    50,    20,    49,    13,     0,     0,
       0,    77,    74,    73,    72,    76,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -40,   -21,   -95,   120,   104,   -95,    -9,    82,
      83,    11,    42,   -18,   -95,   -95,   122,   127,   -95,   -17,
     -94,   -95,    32,   -95,   -95,   -95,   -95,   -95,   -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    50,    43,    99,   130,   144,    44,   131,    56,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    48,    49,    58,    71,   129,    46,    53,    54,    95,
      96,     2,     3,     4,     5,    71,     2,     3,     4,     5,
      63,    64,    71,   140,    57,    94,    47,    12,    65,    66,
      67,    68,    69,    70,    16,    71,    81,    82,    83,    51,
      61,   100,    97,    98,   142,    11,    52,    71,    71,    71,
     127,   103,   104,   135,   136,    59,   105,   106,   107,   108,
     109,   110,   133,   121,   122,   123,     1,     2,     3,     4,
       5,     6,     7,     8,    60,    58,    72,   124,    73,    74,
      75,    76,    77,    78,   113,   114,   115,   116,   117,   118,
      86,   139,   132,     9,    10,    87,    11,    71,    12,   126,
     128,    93,    13,    14,    15,    16,    88,    17,    18,    19,
      20,    21,    58,    22,    71,    89,   137,   134,    58,    79,
      80,   119,   120,   146,     1,     2,     3,     4,     5,     6,
       7,     8,    63,    64,    90,    91,    71,   101,   102,   125,
      65,    66,    67,    68,    69,    70,    12,    71,   138,    62,
      92,     9,    10,   111,    11,   112,    12,   141,     0,    84,
      13,    14,    15,    16,    85,    17,    18,    19,    20,    21,
     143,    22,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,    11,     0,    12,   145,     0,     0,    13,    14,
      15,    16,     0,    17,    18,    19,    20,    21,     0,    22,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
      11,     0,    12,     0,     0,     0,    13,    14,    15,    16,
       0,    17,    18,    19,    20,    21,     0,    22,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    20,    21,     0,    22
};

static const yytype_int16 yycheck[] =
{
      17,    10,    11,    24,    29,    99,    50,    16,    17,    34,
      50,     4,     5,     6,     7,    29,     4,     5,     6,     7,
      14,    15,    29,    37,     0,    32,    49,    35,    22,    23,
      24,    25,    26,    27,    42,    29,    11,    12,    13,    31,
      33,    35,    51,    52,   138,    33,    31,    29,    29,    29,
      32,    60,    61,    34,    34,    39,    65,    66,    67,    68,
      69,    70,   102,    81,    82,    83,     3,     4,     5,     6,
       7,     8,     9,    10,    31,    96,    28,    86,    16,    17,
      18,    19,    20,    21,    73,    74,    75,    76,    77,    78,
      33,   131,   101,    30,    31,    39,    33,    29,    35,    36,
      32,     8,    39,    40,    41,    42,    39,    44,    45,    46,
      47,    48,   133,    50,    29,    39,   125,    32,   139,     9,
      10,    79,    80,   140,     3,     4,     5,     6,     7,     8,
       9,    10,    14,    15,    39,    39,    29,    37,    35,    22,
      22,    23,    24,    25,    26,    27,    35,    29,    43,    29,
      46,    30,    31,    71,    33,    72,    35,    36,    -1,    37,
      39,    40,    41,    42,    37,    44,    45,    46,    47,    48,
     138,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    -1,    39,    40,
      41,    42,    -1,    44,    45,    46,    47,    48,    -1,    50,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    -1,    50,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    30,
      31,    33,    35,    39,    40,    41,    42,    44,    45,    46,
      47,    48,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    73,    77,    80,    50,    49,    59,    59,
      72,    31,    31,    59,    59,    70,    79,     0,    54,    39,
      31,    33,    56,    14,    15,    22,    23,    24,    25,    26,
      27,    29,    28,    16,    17,    18,    19,    20,    21,     9,
      10,    11,    12,    13,    67,    68,    33,    39,    39,    39,
      39,    39,    57,     8,    32,    34,    53,    59,    59,    74,
      35,    37,    35,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    64,    59,    22,    36,    32,    32,    71,
      75,    78,    59,    53,    32,    34,    34,    59,    43,    53,
      37,    36,    71,    73,    76,    36,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    72,    71,    74,
      73,    75,    75,    76,    76,    78,    77,    77,    79,    80,
      80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     3,     5,     1,     1,     1,     1,     2,     1,
       4,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     2,     0,     4,     0,
       4,     1,     3,     1,     1,     0,     6,     5,     5,     4,
       4
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
        case 12:
#line 145 "compiler_hw2.y" /* yacc.c:1646  */
    { int i=0;   int redeclared =0;   int line =0;             //in10 
                       for(i=0;i<my_table[now_scope_level].element_num;i++){  /* i<100 --> segmentation fault */
                           if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                               redeclared =1;
                               line = my_table[now_scope_level].te[i].line_number;		 
                               break;
                           }
                       }
             
                       if(redeclared == 1){
                           printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,(yyvsp[-1].s_val),line);
                       }                                     //in10
                       else{

                           insert_symbol((yyvsp[-1].s_val), now_scope_level);

                           my_table[now_scope_level].element_num += 1;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].name = (yyvsp[-1].s_val);
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].index = my_table[now_scope_level].element_num-1;
                           if(strcmp((yyvsp[0].s_val),"array int32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "int32";
                           }
                           else if(strcmp((yyvsp[0].s_val),"array float32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "float32";
                           }
                           else if(strcmp((yyvsp[0].s_val),"array string")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "string";
                           }
                           else if(strcmp((yyvsp[0].s_val),"array bool")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "bool";
                           }
                           else{ my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = (yyvsp[0].s_val); }

                           // my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = $3;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address = total_address++;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].line_number = yylineno;
                           if(strcmp(my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type,"array")!=0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "-";
                           }
                       }
                     }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-3].s_val), now_scope_level);

                                      my_table[now_scope_level].element_num += 1;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].name = (yyvsp[-3].s_val);
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].index = my_table[now_scope_level].element_num-1;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = (yyvsp[-2].s_val);
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address = total_address++;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].line_number = yylineno;
                                      if(strcmp(my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type,"array")!=0){
                                          my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "-";
                                      }

                                    }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "int32"; }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "float32"; }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 208 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "string"; }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 213 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[0].s_val),"int32")==0){ (yyval.s_val) = "array int32"; }
                       else if(strcmp((yyvsp[0].s_val),"float32")==0){ (yyval.s_val) = "array float32"; }
                       else if(strcmp((yyvsp[0].s_val),"string")==0){ (yyval.s_val) = "array string"; }
                       else if(strcmp((yyvsp[0].s_val),"bool")==0){ (yyval.s_val) = "array bool"; }
                     }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 227 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 || strcmp((yyvsp[0].s_val),"int32")==0){
                                       yyerror("invalid operation: (operator LOR not defined on int32)");
                                   }
                                   printf("LOR\n"); (yyval.s_val) = "bool"; }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 || strcmp((yyvsp[0].s_val),"int32")==0){
                                         yyerror("invalid operation: (operator LAND not defined on int32)");
                                     }                                    
                                     printf("LAND\n"); }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("GTR\n");  (yyval.s_val) = "bool"; }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 244 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("LSS\n");  (yyval.s_val) = "bool"; }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 245 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("GEQ\n");  (yyval.s_val) = "bool"; }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 246 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("LEQ\n");  (yyval.s_val) = "bool"; }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 247 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("EQL\n");  (yyval.s_val) = "bool"; }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("NEQ\n");  (yyval.s_val) = "bool"; 
                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                                  }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 255 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){
                                        yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0){
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<100;j++){
                                            if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;  
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                        }
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //in09 LOR error
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //in09 for condition error
                                        int i=0;  char* c1 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0){
                                            (yyval.s_val) = "int32";   
                                        }
                                    }
                                    printf("ADD\n"); 
                                  }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 299 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){
                                        yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0){
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<100;j++){
                                            if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                        }
                                    }
                                    printf("SUB\n"); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 331 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("MUL\n"); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 332 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("QUO\n"); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 333 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"float32")==0 || strcmp((yyvsp[0].s_val),"float32")==0){
                                      yyerror("invalid operation: (operator REM not defined on float32)");
                                    }                                  
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0){
                                        int i=0;  char* c1 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            yyerror("invalid operation: (operator REM not defined on float32)");
                                        }
                                        else if(strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0){
                                            int j=0;  char* c2 = "";
                                            for(j=0;j<100;j++){
                                                if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                                    c2 = my_table[now_scope_level].te[j].type;
                                                    break;
                                                }
                                            }
                                            if(strcmp(c2,"float32")==0){
                                                yyerror("invalid operation: (operator REM not defined on float32)");
                                            }
                                        }                                      
                                    }                                   
                                    printf("REM\n"); }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 369 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].s_val));  
                               (yyval.s_val) = (yyvsp[0].s_val);/*in09 -> in02*/ }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 375 "compiler_hw2.y" /* yacc.c:1646  */
    { char* s = malloc(sizeof(char)*(strlen((yyvsp[-1].s_val))+strlen((yyvsp[0].s_val))+2));
                            strcpy(s,(yyvsp[0].s_val)); strcat(s,"\n"); strcat(s,(yyvsp[-1].s_val));
                            (yyval.s_val) = s;
                          }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 383 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "POS"; }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 384 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NEG"; }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 385 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NOT"; }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 390 "compiler_hw2.y" /* yacc.c:1646  */
    { int i =0;
                                       for(i=0;i<100;i++){
                                           if(strcmp((yyvsp[-3].s_val),my_table[now_scope_level].te[i].name)==0){
                                               (yyval.s_val) = my_table[now_scope_level].te[i].array_element_type ;
                                               // in04, need IDENT $$ = id
                                               break;
                                           }
                                       }
                                     }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 399 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 && strcmp((yyvsp[-3].s_val),"float32")==0){ printf("I to F\n"); }
                                else if(strcmp((yyvsp[-1].s_val),"float32")==0 && strcmp((yyvsp[-3].s_val),"int32")==0){ printf("F to I\n"); }
                                else{
                                    int i =0;  char* c = "";
                                    for(i=0;i<100;i++){
                                        if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                            c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                            break;
                                        }
                                    }
                                    if(strcmp(c,"int32")==0 && strcmp((yyvsp[-3].s_val),"float32")==0){ printf("I to F\n"); }
                                    else if(strcmp(c,"float32")==0 && strcmp((yyvsp[-3].s_val),"int32")==0){ printf("F to I\n"); }
                                }
			      }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 416 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\n",(yyvsp[0].i_val));  (yyval.s_val)="int32"; }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 417 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %.6f\n",(yyvsp[0].f_val));  (yyval.s_val)="float32"; }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 418 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("TRUE\n");   (yyval.s_val)="bool";}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 419 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FALSE\n");   (yyval.s_val)="bool";}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 420 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n",(yyvsp[-1].s_val));   (yyval.s_val)="string";}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 421 "compiler_hw2.y" /* yacc.c:1646  */
    { int i =0;           int declare =0;//in10
              for(i=0;i<my_table[now_scope_level].element_num;i++){ /* i<100 --> segmentation fault */
                  if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[i].name)==0){
                      printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),my_table[now_scope_level].te[i].address);
                      // $$ = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                      declare =1;//in10
                      break;
                  }
              }
              if(declare == 0){ 
                  if(into_block >0){//in09
                      int j =0;   int k =0;
                      for(j=0;j<now_scope_level;j++){
                          for(k=0;k<my_table[j].element_num;k++){
                              if(strcmp((yyvsp[0].s_val),my_table[j].te[k].name)==0){
                                  scope_dif = now_scope_level - j;
                                  now_scope_level -= scope_dif;
                                  printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),my_table[j].te[k].address);
                                  break;
                              }
                          }
                      }//in09
                  }
                  else{
                      printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[0].s_val));//in10
                  }
              }
            }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 455 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                      yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                  }
                                  else if(strcmp((yyvsp[0].s_val),"string")==0 || strcmp((yyvsp[0].s_val),"bool")==0){
                                  }				 
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0){
                                      int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                      for(i=0;i<100;i++){
                                          if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                              c1 = my_table[now_scope_level].te[i].type;
                                              break;
                                          }
                                      }
                                      for(j=0;j<100;j++){
                                          if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                              c2 = my_table[now_scope_level].te[j].type;
                                              break;
                                          }
                                      }
                                      if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                          yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                      }
                                  }
                                  printf("ASSIGN\n"); 
                                }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 480 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0){ yyerror("cannot assign to int32"); }
                                         printf("ADD_ASSIGN\n"); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 482 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("SUB_ASSIGN\n"); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 483 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("MUL_ASSIGN\n"); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 484 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("QUO_ASSIGN\n"); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 485 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("REM_ASSIGN\n"); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("INC\n"); }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 488 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("DEC\n"); 
                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                     }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 494 "compiler_hw2.y" /* yacc.c:1646  */
    { now_scope_level += 1; 
           into_block +=1;/* in09 */ }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 495 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level); 
                                                          create_symbol(now_scope_level);
                                                          now_scope_level -= 1; 
                                                          into_block -=1;/* in09 */ }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 502 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[0].s_val),"float32")==0){
                         printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition");
                      }
                      else if(strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"string")!=0 && strcmp((yyvsp[0].s_val),"bool")!=0){
                          int i=0;  char* c1 = "";
                          for(i=0;i<100;i++){
                              if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[i].name)==0){
                                  c1 = my_table[now_scope_level].te[i].type;
                                  break;
                              }
                          }
                          if(strcmp(c1,"int32")==0){
                              printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition");   
                          }
                      }
                    }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 536 "compiler_hw2.y" /* yacc.c:1646  */
    { now_scope_level += 1;  into_block +=1;  // in11

                           if(strcmp((yyvsp[-1].s_val),"float32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition"); 
                           }
                           else if(strcmp((yyvsp[-1].s_val),"int32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition"); 
                           }  
                         }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 544 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level);  
                                               create_symbol(now_scope_level); 
                                               now_scope_level -= 1; // in11
                                               into_block -=1; // in11
                                             }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 549 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 570 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 || strcmp((yyvsp[-1].s_val),"float32")==0 || strcmp((yyvsp[-1].s_val),"string")==0 || strcmp((yyvsp[-1].s_val),"bool")==0 ){
                                     printf("PRINT %s\n",(yyvsp[-1].s_val));
                                 }
                                 else{
                                     int i =0;  char* c = "";
                                     for(i=0;i<100;i++){
                                         if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                             c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                             break;
                                         }
                                     }
                                     printf("PRINT %s\n",c);
                                 }
                               }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 584 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 || strcmp((yyvsp[-1].s_val),"float32")==0 || strcmp((yyvsp[-1].s_val),"string")==0 || strcmp((yyvsp[-1].s_val),"bool")==0 ){
                                       printf("PRINTLN %s\n",(yyvsp[-1].s_val));
                                   }
                                   else{
                                       int i =0;  char* c = "";
                                       for(i=0;i<100;i++){
                                           if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                               c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                               break;
                                           }
                                       }
                                       printf("PRINTLN %s\n",c);
                                       
                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }
                                 }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2068 "y.tab.c" /* yacc.c:1646  */
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
#line 602 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /*---*/
    //int now_scope_level = 0;

    //Symbol_Table my_table[50];
    int i=0;
    for(i=0;i<50;i++){
        my_table[i].element_num = 0;
    }
    /*---*/

    yylineno = 0;
    yyparse();

    dump_symbol(now_scope_level);  lookup_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int now_scope_level) {
    my_table[now_scope_level].element_num = 0;
    
}

static void insert_symbol(char* str, int num) {
    printf("> Insert {%s} into symbol table (scope level: %d)\n", str, num);
    
}

static void lookup_symbol() {
}

static void dump_symbol(int now_scope_level) {
    printf("> Dump symbol table (scope level: %d)\n", now_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");

    int i = 0;
    for(i=0;i<my_table[now_scope_level].element_num;i++){
        printf("%-10d%-10s%-10s%-10d%-10d%s\n",
        my_table[now_scope_level].te[i].index, my_table[now_scope_level].te[i].name, 
        my_table[now_scope_level].te[i].type, my_table[now_scope_level].te[i].address, 
        my_table[now_scope_level].te[i].line_number, my_table[now_scope_level].te[i].array_element_type);
    }
   
}



