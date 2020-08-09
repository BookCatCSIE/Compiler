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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    //#include <io.h> //hw3
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

    typedef struct { //*//hw3
        int idata;
        float fdata;
        char* sdata;
        bool bdata;
    }Data; //*//hw3

    typedef struct {
        int index;
        char* name;
        char* type;
        int address;
        int line_number;
        char* array_element_type;
        Data data; //*//hw3
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

    /* Global variables */
    bool HAS_ERROR = false;

    FILE* file;

    int label1 = 1; //odd    //*//hw3_in02
    int label2 = 0; //even   //*//hw3_in02
 
    int label3 = 300; //  // For_label_name  //hw3_in09
    int label7 = 301; //  // For_label_name  //hw3_in13

    int label5 = 101; //odd  // If_else_label_name  //hw3_in07 in11
    int label6 = 100; //even  // If_else_label_name  //hw3_in07 in11

    int label9 = 201; //  // For_;_;_label_name  //hw3_in12
    int label8 = 200; //  // For_;_;_label_name  //hw3_in12

    fpos_t file_pos1;
    fpos_t file_pos2;

    int at_bottom_for2 =0;

#line 159 "y.tab.c" /* yacc.c:339  */

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
#line 100 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char* s_val;
    /* ... */
    //char* id_val;
    //all_type type;

#line 272 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 289 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
       0,   157,   157,   161,   162,   166,   167,   168,   169,   170,
     171,   172,   176,   246,   280,   281,   282,   283,   287,   292,
     296,   297,   301,   308,   312,   319,   323,   373,   423,   426,
     453,   480,   507,   511,   643,   736,   740,   877,   968,  1021,
    1025,  1029,  1056,  1060,  1064,  1068,  1069,  1070,  1074,  1075,
    1112,  1158,  1161,  1164,  1167,  1170,  1173,  1209,  1216,  1294,
    1324,  1355,  1386,  1417,  1434,  1435,  1465,  1498,  1498,  1507,
    1529,  1539,  1543,  1550,  1600,  1609,  1623,  1623,  1635,  1643,
    1647,  1647,  1661,  1667,  1669,  1667,  1688,  1692,  1696,  1792,
    1902
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
  "Operand", "SimpleStmt", "Block", "$@1", "IfStmt1", "IfStmt2", "IfStmt",
  "ForOperand", "ForStmt2", "ForStmt3", "$@2", "ForStmt", "ForStmt5",
  "$@3", "ForStmt6", "ForStmt7", "$@4", "$@5", "ForStmt9", "ForStmt10",
  "ForStmt8", "PrintStmt", YY_NULLPTR
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

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -76

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,   -28,   -57,   -57,   -57,   -57,   -18,   -57,   -57,   -57,
     159,   159,   -57,   -57,     2,    27,   159,   -57,   -57,   -57,
     -57,   -57,   -57,    35,   112,   -57,    41,   -57,    61,     4,
      62,    38,    26,    10,   124,   -57,   -57,   159,   -57,    63,
     -57,    68,    74,    66,    59,    90,   159,    96,   105,    93,
     159,   107,   -57,   109,     8,   138,   -25,     5,   112,   159,
     159,   120,   -57,   -57,   -57,   159,   159,   -57,   -57,   -57,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   -57,
      63,   159,   -57,   -57,   -57,   -19,   -57,     3,   -57,   -57,
     -57,   -57,   120,   159,   136,   -57,   -57,   133,   -57,   -57,
     -57,    64,    -8,    46,    50,    19,   120,   120,   120,   120,
     120,   120,    38,    26,    10,    10,    10,    10,    10,    10,
     124,   124,   -57,   -57,   -57,    25,   -57,   -57,   134,   112,
     120,   126,   -57,   159,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   112,   -57,   120,   112,   112,   137,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,    15,    17,    16,     0,    45,    46,    47,
       0,     0,    67,    11,     0,     0,     0,    74,    53,    54,
      51,    52,    56,     0,     2,     4,     0,    19,     0,     0,
      64,    23,    25,    32,    35,    39,    40,     0,    44,    42,
      48,     0,     0,     0,    71,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     1,     3,     5,     0,     0,    18,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      41,     0,     6,     7,    70,     0,     8,    64,    80,    76,
      78,     9,    82,     0,     0,    86,    10,    12,    55,    57,
      21,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    22,    24,    26,    27,    28,    29,    30,    31,
      33,    34,    36,    37,    38,     0,    72,    73,     0,     0,
      87,     0,    88,     0,    68,    89,    90,    50,    20,    49,
      81,    77,    83,    13,     0,    84,     0,    85
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -56,   -21,   -57,   141,   118,   -57,   -10,    98,
      99,    45,   -33,    52,   -57,   -57,   140,   142,   -57,   129,
     -38,   -57,   -57,   -57,    83,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    58,    43,    44,    45,    46,    47,    48,   139,    49,
      50,   138,    51,   142,   154,   156,    52,   104,   105,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    57,   111,    63,    76,    94,    61,   109,     2,     3,
       4,     5,     2,     3,     4,     5,    12,    68,    69,    84,
      85,    76,    54,    16,   145,    70,    71,    72,    73,    74,
      75,    55,    76,    59,    76,    62,    97,    66,   -75,   110,
     102,    11,    78,    79,    80,    81,    82,    83,    76,   112,
     113,   130,   131,   148,    76,   114,   115,   136,    60,   149,
     116,   117,   118,   119,   120,   121,    77,     1,     2,     3,
       4,     5,     6,     7,     8,    76,    68,    69,   146,    76,
      64,   135,   147,   151,    70,    71,    72,    73,    74,    75,
      63,    76,    65,   140,     9,    10,    91,    11,   155,    12,
     144,    12,    95,    13,    14,    15,    16,    92,    17,    18,
      19,    20,    21,    93,    22,     1,     2,     3,     4,     5,
       6,     7,     8,   124,   125,   126,   127,   128,   129,    96,
      63,    99,   101,   153,    63,    86,    87,    88,   132,   133,
     134,   100,     9,    10,   103,    11,   108,    12,   106,    76,
     141,    13,    14,    15,    16,   143,    17,    18,    19,    20,
      21,   152,    22,     2,     3,     4,     5,     6,     7,     8,
      67,   150,   107,   157,   122,    98,   123,    89,   137,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,     0,    22
};

static const yytype_int16 yycheck[] =
{
      10,    11,    58,    24,    29,    43,    16,    32,     4,     5,
       6,     7,     4,     5,     6,     7,    35,    14,    15,     9,
      10,    29,    50,    42,    32,    22,    23,    24,    25,    26,
      27,    49,    29,    31,    29,     0,    46,    33,    35,    34,
      50,    33,    16,    17,    18,    19,    20,    21,    29,    59,
      60,    84,    85,    34,    29,    65,    66,    95,    31,    34,
      70,    71,    72,    73,    74,    75,    28,     3,     4,     5,
       6,     7,     8,     9,    10,    29,    14,    15,    32,    29,
      39,    91,    32,   139,    22,    23,    24,    25,    26,    27,
     111,    29,    31,   103,    30,    31,    33,    33,   154,    35,
      36,    35,    43,    39,    40,    41,    42,    39,    44,    45,
      46,    47,    48,    39,    50,     3,     4,     5,     6,     7,
       8,     9,    10,    78,    79,    80,    81,    82,    83,    39,
     151,    35,    39,   143,   155,    11,    12,    13,    86,    87,
      88,    36,    30,    31,    37,    33,     8,    35,    39,    29,
      14,    39,    40,    41,    42,    22,    44,    45,    46,    47,
      48,    35,    50,     4,     5,     6,     7,     8,     9,    10,
      29,    37,    54,    36,    76,    46,    77,    37,    95,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    30,
      31,    33,    35,    39,    40,    41,    42,    44,    45,    46,
      47,    48,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    73,    74,    75,    76,    77,    78,    80,
      81,    83,    87,    90,    50,    49,    59,    59,    72,    31,
      31,    59,     0,    54,    39,    31,    33,    56,    14,    15,
      22,    23,    24,    25,    26,    27,    29,    28,    16,    17,
      18,    19,    20,    21,     9,    10,    11,    12,    13,    67,
      68,    33,    39,    39,    71,    43,    39,    59,    70,    35,
      36,    39,    59,    37,    88,    89,    39,    57,     8,    32,
      34,    53,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    59,    71,    75,    82,    79,
      59,    14,    84,    22,    36,    32,    32,    32,    34,    34,
      37,    53,    35,    59,    85,    53,    86,    36
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
      70,    70,    70,    70,    70,    70,    70,    72,    71,    73,
      74,    75,    75,    75,    76,    77,    79,    78,    80,    80,
      82,    81,    83,    85,    86,    84,    87,    88,    89,    90,
      90
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
       3,     3,     3,     3,     1,     2,     2,     0,     4,     2,
       2,     1,     3,     3,     1,     2,     0,     4,     2,     1,
       0,     4,     2,     0,     0,     6,     2,     2,     2,     4,
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
#line 176 "compiler_hw3.y" /* yacc.c:1646  */
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
                               //hw3_in04
                               fprintf(file,"\tnewarray int\n");
                               fprintf(file,"\tastore %d\n",total_address);
                               //hw3_in04
                           }
                           else if(strcmp((yyvsp[0].s_val),"array float32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "float32";
                               //hw3_in04
                               fprintf(file,"\tnewarray float\n");
                               fprintf(file,"\tastore %d\n",total_address);
                               //hw3_in04
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

                           //*//hw3_03
                           int store_register = my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address;

                           if(strcmp((yyvsp[0].s_val),"int32")==0){
                               fprintf(file,"\tldc 0\n");
                               fprintf(file,"\tistore %d\n",store_register);
                           }
                           else if(strcmp((yyvsp[0].s_val),"float32")==0){
                               fprintf(file,"\tldc 0.0\n");
                               fprintf(file,"\tfstore %d\n",store_register);
                           } //*//hw3_03
                           else if(strcmp((yyvsp[0].s_val),"string")==0){ //hw3_in05
                               fprintf(file,"\tldc \"\"\n");
                               fprintf(file,"\tastore %d\n",store_register);
                           } //hw3_in05
                           
                       }
                     }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 246 "compiler_hw3.y" /* yacc.c:1646  */
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
                                      
                                      //*//hw3_01
                                      int store_register = my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address;

                                      if(strcmp((yyvsp[-2].s_val),"int32")==0){
                                          fprintf(file,"\tistore %d\n",store_register);
                                      }
                                      else if(strcmp((yyvsp[-2].s_val),"float32")==0){
                                          fprintf(file,"\tfstore %d\n",store_register);
                                      }
                                      else if(strcmp((yyvsp[-2].s_val),"string")==0){ //hw3_03
                                          fprintf(file,"\tastore %d\n",store_register);
                                      }
                                      else if(strcmp((yyvsp[-2].s_val),"bool")==0){
                                          fprintf(file,"\tistore %d\n",store_register);
                                      } //hw3_03

                                      //*//hw3_01

                                    }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "int32"; }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 281 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "float32"; }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 282 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "string"; }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 283 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "bool"; }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 287 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[0].s_val),"int32")==0){ (yyval.s_val) = "array int32"; }
                       else if(strcmp((yyvsp[0].s_val),"float32")==0){ (yyval.s_val) = "array float32"; }
                       else if(strcmp((yyvsp[0].s_val),"string")==0){ (yyval.s_val) = "array string"; }
                       else if(strcmp((yyvsp[0].s_val),"bool")==0){ (yyval.s_val) = "array bool"; }
                     }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 301 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 || strcmp((yyvsp[0].s_val),"int32")==0){
                                       yyerror("invalid operation: (operator LOR not defined on int32)");
                                   }
                                   printf("LOR\n");    (yyval.s_val) = "bool"; 
                            
                                   fprintf(file,"\tior\n"); //*//hw3_in02
                                 }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 312 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 || strcmp((yyvsp[0].s_val),"int32")==0){
                                         yyerror("invalid operation: (operator LAND not defined on int32)");
                                     }                                    
                                     printf("LAND\n");   (yyval.s_val) = "bool";

                                     fprintf(file,"\tiand\n"); //*//hw3_in02
                                   }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 323 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GTR\n");  (yyval.s_val) = "bool"; 
                                    //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3

                                    if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfcmpl\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } //hw3_in02
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in08

                                        int address1 =0;     int ii =0;   
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in08

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LSS\n");  (yyval.s_val) = "bool"; 
                                    //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3

                                    if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1++;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2++;
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfcmpl\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1++;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2++;
                                    } //hw3_in02
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in13

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in13

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 423 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GEQ\n");  (yyval.s_val) = "bool";
                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 426 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LEQ\n");  (yyval.s_val) = "bool";

                                    if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in11

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifle L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in11

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("EQL\n");  (yyval.s_val) = "bool"; 

                                    if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in07

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifeq L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in07

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 480 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NEQ\n");  (yyval.s_val) = "bool"; 

                                    if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in13

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifne L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in13

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                                  }
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 511 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                        HAS_ERROR = true; //hw3_in09
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){
                                        yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tiadd\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfadd\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in02   
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
                                        else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tiadd\n");
                                        } //*//hw3_01
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfadd\n");
                                        } //*//hw3_01


                                    }
                                    //else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //in09 LOR error
                                    //    $$ = "int32";
                                    //}
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //in09 for condition error  //hw3_in06
                                        int i=0;  char* c1 = "";   int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0){
                                            (yyval.s_val) = "int32";   

                                            fprintf(file,"\tiload %d\n",load_address);
                                            fprintf(file,"\tiadd\n");
                                        }
                                    }  //hw3_in06
                                    else if(strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"string")!=0 && strcmp((yyvsp[0].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"float32")==0){  //hw3_in06
                                        int i=0;  char* c1 = "";  int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            (yyval.s_val) = "float32";

                                            fprintf(file,"\tfload %d\n",load_address);
                                            fprintf(file,"\tfadd\n");
                                        }
                                    } //hw3_in06
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){  //hw3_in13
                                        int i=0;  char* c1 = "";  int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            (yyval.s_val) = "float32";

                                            fprintf(file,"\tfload %d\n",load_address);
                                            fprintf(file,"\tfadd\n");
                                        }
                                    } //hw3_in13

                                    printf("ADD\n"); 
                                  }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 643 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){
                                        yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfsub\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in02 
                                    else if(strcmp((yyvsp[-2].s_val),"array int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\tisub\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"array float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n"); 
                                        fprintf(file,"\tfload 99\n");
                                        fprintf(file,"\tfsub\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in04
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
                                        else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tisub\n");
                                        } //*//hw3_01
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfsub\n");
                                        } //*//hw3_01

                                    }
                                    printf("SUB\n"); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 740 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\timul\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfmul\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in02
                                    else if(strcmp((yyvsp[-2].s_val),"array int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\timul\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"array float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tfload 99\n"); 
                                        fprintf(file,"\tfmul\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in04 
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"string")!=0 && strcmp((yyvsp[0].s_val),"bool")!=0){ //*//hw3_01
                                        
                                        //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }

                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        int address1 = 0; int address2 = 0;  int declare1 = 0;  int declare2 = 0; 

                                        for(i=0;i<my_table[now_scope_level].element_num;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                address1 = my_table[now_scope_level].te[i].address ;
                                                declare1 = 1;
                                                break;
                                            }
                                        }
                                        if(declare1 == 0){ //in13
                                            if(into_block >0){
                                                int k1 =0;   int k2 =0;
                                                for(k1=0;k1<50;k1++){
                                                    for(k2=0;k2<my_table[k1].element_num;k2++){
                                                        if(strcmp((yyvsp[-2].s_val),my_table[k1].te[k2].name)==0){
                                                            c1 = my_table[k1].te[k2].type;
                                                            address1 = my_table[k1].te[k2].address ;

                                                            //scope_dif = now_scope_level - j;
                                                            //now_scope_level -= scope_dif;
                                                            break;
                                                        }
                                                    }
                                                } 
                                            }
                                        } //in13

                                        for(j=0;j<my_table[now_scope_level].element_num;j++){
                                            if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                address2 = my_table[now_scope_level].te[j].address ;
                                                declare2 = 1;
                                                break;
                                            }
                                        }
                                        if(declare2 == 0){ //in13
                                            if(into_block >0){
                                                int k1 =0;   int k2 =0;
                                                for(k1=0;k1<50;k1++){
                                                    for(k2=0;k2<my_table[k1].element_num;k2++){
                                                        if(strcmp((yyvsp[0].s_val),my_table[k1].te[k2].name)==0){
                                                            c2 = my_table[k1].te[k2].type;
                                                            address2 = my_table[k1].te[k2].address ;

                                                            //scope_dif = now_scope_level - j;
                                                            //now_scope_level -= scope_dif;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        } //in13 

                                        /*if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation:  (mismatched types int32 and float32)");
                                            HAS_ERROR = true;
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation:  (mismatched types float32 and int32)");
                                            HAS_ERROR = true;
                                        }*/
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){
                                           /*
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }
                                           */

                                           (yyval.s_val) = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\timul\n");
                                        }
                                        if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfmul\n");
                                        }
                                    } //*//hw3_01

                                    printf("MUL\n");
                                  }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 877 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tidiv\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfdiv\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in02 
                                    else if(strcmp((yyvsp[-2].s_val),"array int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\tidiv\n");
                                        (yyval.s_val) = "int32";
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"array float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n"); 
                                        fprintf(file,"\tfload 99\n");
                                        fprintf(file,"\tfdiv\n");
                                        (yyval.s_val) = "float32";
                                    } //hw3_in04
                                    else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"string")!=0 && strcmp((yyvsp[0].s_val),"bool")!=0){ //*//hw3_01
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<my_table[now_scope_level].element_num;i++){
                                            if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<my_table[now_scope_level].element_num;j++){
                                            if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                break;
                                            }
                                        }
                                        /*if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation:  (mismatched types int32 and float32)");
                                            HAS_ERROR = true;
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation:  (mismatched types float32 and int32)");
                                            HAS_ERROR = true;
                                        }*/
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tidiv\n");
                                        }
                                        if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           (yyval.s_val) = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfdiv\n");
                                        } 

                                    } //*//hw3_01

                                    printf("QUO\n"); 
                                  }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 968 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"float32")==0 || strcmp((yyvsp[0].s_val),"float32")==0){
                                      yyerror("invalid operation: (operator REM not defined on float32)");
                                    }
                                    else if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in02
                                        fprintf(file,"\tirem\n");
                                        (yyval.s_val) = "int32";
                                    } //hw3_in02  	  
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
                                            else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                                int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                                for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                    if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                        address1 = my_table[now_scope_level].te[ii].address;
                                                        break;
                                                    }
                                                }
                                                for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                                    if(strcmp((yyvsp[0].s_val),my_table[now_scope_level].te[jj].name)==0){
                                                        address2 = my_table[now_scope_level].te[jj].address;
                                                        break;
                                                    }
                                                }

                                                (yyval.s_val) = "int32";
                                                fprintf(file,"\tiload %d\n",address1);
                                                fprintf(file,"\tiload %d\n",address2);
                                                fprintf(file,"\tirem\n");
                                            } //*//hw3_01

                                        }                                      
                                    }                                   
                                    printf("REM\n"); }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1029 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("%s\n",(yyvsp[-1].s_val));  
                               (yyval.s_val) = (yyvsp[0].s_val);/*in09 -> in02*/ 
                               
                               if(strcmp((yyvsp[-1].s_val),"NEG")==0){ //hw3_in02
                                   if(strcmp((yyvsp[0].s_val),"int32")==0){
                                       fprintf(file,"\tineg\n"); 
                                   }
                                   else if(strcmp((yyvsp[0].s_val),"float32")==0){
                                       fprintf(file,"\tfneg\n");
                                   }
                               }

                               if(strcmp((yyvsp[-1].s_val),"NOT\nNOT")==0){

                               }
                               else if(strcmp((yyvsp[-1].s_val),"NOT")==0){
                                   fprintf(file,"\ticonst_1\n");
                                   fprintf(file,"\tixor\n");
                                   /*if(strcmp($2,"bool")==0){
                                       fprintf(file,"\ticonst_1\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tixor\n");
                                   }*/
                               } //hw3_in02 
                               
 
                             }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1060 "compiler_hw3.y" /* yacc.c:1646  */
    { char* s = malloc(sizeof(char)*(strlen((yyvsp[-1].s_val))+strlen((yyvsp[0].s_val))+2));
                            strcpy(s,(yyvsp[0].s_val)); strcat(s,"\n"); strcat(s,(yyvsp[-1].s_val));
                            (yyval.s_val) = s;
                          }
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1068 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "POS"; }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1069 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NEG"; }
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1070 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = "NOT"; }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1075 "compiler_hw3.y" /* yacc.c:1646  */
    { int i =0;
                                       /*for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                               $$ = my_table[now_scope_level].te[i].array_element_type ;
                                               // in04, need IDENT $$ = id
                                               break;
                                           }
                                       }*/

                                       //hw3_in04
                                       int load_address = 0;   char* c = "";

                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp((yyvsp[-3].s_val),my_table[now_scope_level].te[i].name)==0){
                                               load_address = my_table[now_scope_level].te[i].address ;
                                               c = my_table[now_scope_level].te[i].array_element_type ;
                                               break;
                                           }
                                       }

                                       fprintf(file,"\taload %d\n",load_address);
                                       fprintf(file,"\tswap\n");
                                       /*if(strcmp(c,"int32")==0){
                                           fprintf(file,"\tiaload\n");
                                       }
                                       else if(strcmp(c,"float32")==0){
                                           fprintf(file,"\tfaload\n");
                                       }*/
                                       //hw3_in04
                      
                                       if(strcmp(c,"int32")==0){
                                           (yyval.s_val) = "array int32";
                                       }
                                       else if(strcmp(c,"float32")==0){
                                           (yyval.s_val) = "array float32";
                                       }
                                     }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1112 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 && strcmp((yyvsp[-3].s_val),"float32")==0){ 
                                    printf("I to F\n"); 
                                    fprintf(file,"\ti2f\n"); //hw3_in06
                                    (yyval.s_val) = "float32";
                                }
                                else if(strcmp((yyvsp[-1].s_val),"float32")==0 && strcmp((yyvsp[-3].s_val),"int32")==0){ 
                                    printf("F to I\n");
                                    fprintf(file,"\tf2i\n"); //hw3_in06
                                    (yyval.s_val) = "int32";
                                }
                                else if(strcmp((yyvsp[-1].s_val),"array float32")==0 && strcmp((yyvsp[-3].s_val),"int32")==0){ //hw3_in13
                                    printf("F to I\n");
                                    fprintf(file,"\tfaload\n");
                                    fprintf(file,"\tf2i\n");
                                    (yyval.s_val) = "int32";
                                } //hw3_in13
                                else{
                                    int i =0;  char* c = "";
                                    int load_address = 0 ; //hw3_in06
                                    for(i=0;i<my_table[now_scope_level].element_num;i++){
                                        if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                            c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                            load_address = my_table[now_scope_level].te[i].address ; //hw3_in06
                                            break;
                                        }
                                    }

                                    if(strcmp(c,"int32")==0 && strcmp((yyvsp[-3].s_val),"float32")==0){ 
                                        printf("I to F\n"); 
                                
                                        fprintf(file,"\tiload %d\n",load_address); //hw3_in06
                                        fprintf(file,"\ti2f\n"); //hw3_in06
                                        (yyval.s_val) = "float32";
                                    }
                                    else if(strcmp(c,"float32")==0 && strcmp((yyvsp[-3].s_val),"int32")==0){ 
                                        printf("F to I\n"); 

                                        fprintf(file,"\tfload %d\n",load_address); //hw3_in06
                                        fprintf(file,"\tf2i\n"); //hw3_in06
                                        (yyval.s_val) = "int32";
                                    }
                                }
			      }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1158 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\n",(yyvsp[0].i_val));  (yyval.s_val)="int32";
                fprintf(file,"\tldc %d\n",(yyvsp[0].i_val)); //*//hw3_in01
              }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1161 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %.6f\n",(yyvsp[0].f_val));  (yyval.s_val)="float32";
                  fprintf(file,"\tldc %f\n",(yyvsp[0].f_val)); //*//hw3_in01
                }
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1164 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("TRUE\n");   (yyval.s_val)="bool";
             fprintf(file,"\ticonst_1\n"); //*//hw3_in02
           }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1167 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FALSE\n");   (yyval.s_val)="bool";
              fprintf(file,"\ticonst_0\n"); //*//hw3_in02
            }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1170 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n",(yyvsp[-1].s_val));   (yyval.s_val)="string";
                           fprintf(file,"\tldc \"%s\"\n",(yyvsp[-1].s_val)); //*//hw3_in
                         }
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1173 "compiler_hw3.y" /* yacc.c:1646  */
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
                      for(j=0;j<50;j++){ // j<now_scope_level
                          for(k=0;k<my_table[j].element_num;k++){
                              if(strcmp((yyvsp[0].s_val),my_table[j].te[k].name)==0){
                                  if(now_scope_level > j){ // hw3_in13
                                      scope_dif = now_scope_level - j;
                                      now_scope_level -= scope_dif;
                                  }
                                  else if(now_scope_level < j){
                                      scope_dif = j - now_scope_level ;
                                      now_scope_level += scope_dif;
                                  } // hw3_in13
                                  printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),my_table[j].te[k].address);
                                  break;
                              }
                          }
                      }//in09
                  }
                  else{
                      printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[0].s_val));//in10

                      HAS_ERROR = true; //hw3_in10
                  }
              }
            }
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1209 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[-1].s_val); //hw3_in02
                         }
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1216 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                      yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                  }       							 
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")!=0 && strcmp((yyvsp[0].s_val),"float32")!=0 && strcmp((yyvsp[0].s_val),"string")!=0 && strcmp((yyvsp[0].s_val),"bool")!=0 && strcmp((yyvsp[0].s_val),"array int32")!=0 && strcmp((yyvsp[0].s_val),"array float32")!=0){
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
                                  else if(strcmp((yyvsp[-2].s_val),"array int32")==0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in04
                                  // this condition only can be assigning int to array element of int type
                                      fprintf(file,"\tiastore\n");
                                      //fprintf(file,"\tpop\n");
                                  }
                                  else if(strcmp((yyvsp[-2].s_val),"array float32")==0 && strcmp((yyvsp[0].s_val),"float32")==0){
                                  // this condition only can be assigning float to array element of float type
                                      fprintf(file,"\tfastore\n");
                                      //fprintf(file,"\tpop\n");
                                  } //hw3_in04
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;   
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }
                                                
                                      fprintf(file,"\tistore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tfstore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"string")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tastore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"bool")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tistore %d\n",address1);
                                  }//hw3_in05

                                  printf("ASSIGN\n"); 
                                }
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1294 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")==0){ yyerror("cannot assign to int32"); }
                                         else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tiadd\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }
               
                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tfadd\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("ADD_ASSIGN\n"); 
                                       }
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1324 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tisub\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfsub\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05
                               
                                         printf("SUB_ASSIGN\n"); 
                                       }
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1355 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             //fprintf(file,"\tswap\n");
                                             fprintf(file,"\timul\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             //fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfmul\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("MUL_ASSIGN\n"); 
                                       }
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1386 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tidiv\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfdiv\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("QUO_ASSIGN\n"); 
                                       }
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1417 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-2].s_val),"int32")!=0 && strcmp((yyvsp[-2].s_val),"float32")!=0 && strcmp((yyvsp[-2].s_val),"string")!=0 && strcmp((yyvsp[-2].s_val),"bool")!=0 && strcmp((yyvsp[-2].s_val),"array int32")!=0 && strcmp((yyvsp[-2].s_val),"array float32")!=0 && strcmp((yyvsp[0].s_val),"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp((yyvsp[-2].s_val),my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tirem\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05 

                                         printf("REM_ASSIGN\n"); 
                                       }
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1435 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INC\n"); 
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       if(strcmp((yyvsp[-1].s_val),"int32")!=0 && strcmp((yyvsp[-1].s_val),"float32")!=0 && strcmp((yyvsp[-1].s_val),"string")!=0 && strcmp((yyvsp[-1].s_val),"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tiadd\n");
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tfadd\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                     }
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1465 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("DEC\n"); 
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
          
                       if(strcmp((yyvsp[-1].s_val),"int32")!=0 && strcmp((yyvsp[-1].s_val),"float32")!=0 && strcmp((yyvsp[-1].s_val),"string")!=0 && strcmp((yyvsp[-1].s_val),"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tisub\n");  // 2nd top - 1st top
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfsub\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                     }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1498 "compiler_hw3.y" /* yacc.c:1646  */
    { now_scope_level += 1; 
           into_block +=1;/* in09 */ }
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1499 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level); 
                                                          create_symbol(now_scope_level);
                                                          now_scope_level -= 1; 
                                                          into_block -=1;/* in09 */ }
#line 2971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1507 "compiler_hw3.y" /* yacc.c:1646  */
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

                      fprintf(file,"\tifeq L_if_false_%d\n",label5); //hw3_in07
                      //label5 = label5 +2 ;
                    }
#line 2995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1529 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file,"\tgoto L_if_exit_%d\n",label6); //hw3_in07
                      //label6 = label6 +2 ;

                      //label5 = label5 -2 ;
                      fprintf(file,"L_if_false_%d :\n",label5); //hw3_in07
                      label5 = label5 +2 ; ///
                    }
#line 3007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1539 "compiler_hw3.y" /* yacc.c:1646  */
    { //label6 = label6 -2 ;
                fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in07
                label6 = label6 +2 ; ///
              }
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1543 "compiler_hw3.y" /* yacc.c:1646  */
    { //fprintf(file,"L_if_exit_%d :\n",label2); //hw3_in07
                           //label2 ++;

                           //label6 = label6 -2 ;
                           fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in07
                           label6 = label6 +2 ; ///
                         }
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1550 "compiler_hw3.y" /* yacc.c:1646  */
    { //label6 = label6 -2 ;
                            fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in11
                            label6 = label6 +2 ; ///
                          }
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1600 "compiler_hw3.y" /* yacc.c:1646  */
    { fgetpos(file, &file_pos1); //hw3_in13

            fprintf(file,"L_for_begin_%d :\n",label3); //hw3_in08
            label3 = label3 +2;  //hw3_in13
          }
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1609 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file,"\tifeq L_for_exit_%d\n",label7); /*hw3_in08*/
                              if(strcmp((yyvsp[0].s_val),"float32")==0){
                                  printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition");
                              }
                              else if(strcmp((yyvsp[0].s_val),"int32")==0){
                                  printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition");
                              }

                              //label3 ++;
                              label7 = label7 +2;  //hw3_in13
                            }
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1623 "compiler_hw3.y" /* yacc.c:1646  */
    { now_scope_level += 1;  into_block +=1;  /*in11*/
                   }
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1624 "compiler_hw3.y" /* yacc.c:1646  */
    { //label3 --;
                                     label3 = label3 -2;  //hw3_in13
                                     label7 = label7 -2;  //hw3_in13

                                     fprintf(file,"\tgoto L_for_begin_%d\n",label3); //hw3_in08
                                     fprintf(file,"L_for_exit_%d :\n",label7); //hw3_in08
                                     //label3 ++; //hw3_in09
                                   }
#line 3083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1635 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level);
                     create_symbol(now_scope_level);
                     now_scope_level -= 1; // in11
                     into_block -=1; // in11 

                     label3 = label3 +10;  //hw3_in13
                     label7 = label7 +10;  //hw3_in13
                   }
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1647 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file,"L_for_begin_%d :\n",label8); //hw3_in12 
                              label8 = label8 +2; ///in12_in13///

                              fgetpos(file, &file_pos2); //hw3_in13

                              fsetpos(file, &file_pos1); //hw3_in13
                              fprintf(file,"L_for_conflict_0 :\n");
                              label3 = label3 -2; //hw3_in13

                              fsetpos(file, &file_pos2); //hw3_in13
                            }
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1661 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(file,"\tifeq L_for_exit_%d\n",label9);
                            label9 = label9 +2; ///in12_in13///
                          }
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1667 "compiler_hw3.y" /* yacc.c:1646  */
    { at_bottom_for2 ++; ///in12_in13///

              }
#line 3128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1669 "compiler_hw3.y" /* yacc.c:1646  */
    { //label8 = label8 -2;
                              //fprintf(file,"\tgoto L_for_begin_%d\n",label8); //hw3_in12
                                ////label8 = label8 +2;
                              //label9 = label9 -2;         
                              //fprintf(file,"L_for_exit_%d :\n",label9); //hw3_in12
                                ////label9 = label9 +2;

      }
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1676 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1);  
              at_bottom_for2 --; ///in12_in13///
            }
#line 3149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1692 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.s_val) = (yyvsp[0].s_val); }
#line 3155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1696 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INC\n");
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       if(strcmp((yyvsp[-1].s_val),"int32")!=0 && strcmp((yyvsp[-1].s_val),"float32")!=0 && strcmp((yyvsp[-1].s_val),"string")!=0 && strcmp((yyvsp[-1].s_val),"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tiadd\n");
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tfadd\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       // ForStmt7
                       label8 = label8 -2; ///in12_in13///
                       fprintf(file,"\tgoto L_for_begin_%d\n",label8); //hw3_in12
                   
                       label9 = label9 -2; ///in12_in13///
                       fprintf(file,"L_for_exit_%d :\n",label9); //hw3_in12

                       //label8 = label8 +10; //hw3_in13  ///in12_in13/// 
                       //label9 = label9 +10; //hw3_in13  ///in12_in13/// 

                       if(at_bottom_for2 == 0){ ///in12_in13///
                           label8 = label8 +10;
                           label9 = label9 +10;
                       } ///in12_in13///
                     }
#line 3205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1792 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 || strcmp((yyvsp[-1].s_val),"float32")==0 || strcmp((yyvsp[-1].s_val),"string")==0 || strcmp((yyvsp[-1].s_val),"bool")==0 ){
                                     printf("PRINT %s\n",(yyvsp[-1].s_val));
                                 }
                                 else if(strcmp((yyvsp[-1].s_val),"array int32")==0){ // hw3_in04
                                     printf("PRINT int32\n");
                                 }
                                 else if(strcmp((yyvsp[-1].s_val),"array float32")==0){
                                     printf("PRINT float32\n");
                                 } // hw3_in04
                                 else{
                                     int i =0;  char* c = "";
                                     for(i=0;i<100;i++){
                                         if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                             c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                             break;
                                         }
                                     }
                                     printf("PRINT %s\n",c);

                                     //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//hw3_in13
                                 }

                                 //*//hw3_01
                                   if(strcmp((yyvsp[-1].s_val),"int32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"float32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array int32")==0){ //hw3_in04
                                       fprintf(file,"\tiaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array float32")==0){
                                       fprintf(file,"\tfaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                   } //hw3_in04
                                   else if(strcmp((yyvsp[-1].s_val),"string")==0){ // hw3_in
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                   } // hw3_in
                                   else if(strcmp((yyvsp[-1].s_val),"bool")==0){ // hw3_in02
                                       fprintf(file,"\tifne L_cmp_%d\n",label1);
                                       fprintf(file,"\tldc \"%s\"\n","false");
                                       fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                       fprintf(file,"L_cmp_%d:\n",label1);
                                       label1 = label1 +2 ;
                                       fprintf(file,"\tldc \"%s\"\n","true");
                                       fprintf(file,"L_cmp_%d:\n",label2);
                                       label2 = label2 +2 ;                            
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                   } // hw3_in02  
                                   else if(strcmp((yyvsp[-1].s_val),"int32")!=0 && strcmp((yyvsp[-1].s_val),"float32")!=0 && strcmp((yyvsp[-1].s_val),"string")!=0 && strcmp((yyvsp[-1].s_val),"bool")!=0 ){
                                       int i=0;   char* c1 = "";   int address1 =0;
                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                               c1 = my_table[now_scope_level].te[i].type;
                                               address1 = my_table[now_scope_level].te[i].address;
                                               break;
                                           }
                                       }

                                       if(strcmp(c1,"int32")==0 ){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                       }
                                       else if(strcmp(c1,"float32")==0 ){
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                       }
                                       else if(strcmp(c1,"string")==0){ // hw3_in03
                                           fprintf(file,"\taload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                       }
                                       else if(strcmp(c1,"bool")==0){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tifne L_cmp_%d\n",label1);
                                           fprintf(file,"\tldc \"%s\"\n","false");
                                           fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                           fprintf(file,"L_cmp_%d:\n",label1);
                                           label1 = label1 +2 ;
                                           fprintf(file,"\tldc \"%s\"\n","true");
                                           fprintf(file,"L_cmp_%d:\n",label2);
                                           label2 = label2 +2 ;
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                       }  // hw3_in03

                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//hw3_in13
                                   }
                                   //*//hw3_01
                               }
#line 3320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1902 "compiler_hw3.y" /* yacc.c:1646  */
    { if(strcmp((yyvsp[-1].s_val),"int32")==0 || strcmp((yyvsp[-1].s_val),"float32")==0 || strcmp((yyvsp[-1].s_val),"string")==0 || strcmp((yyvsp[-1].s_val),"bool")==0 ){
                                       printf("PRINTLN %s\n",(yyvsp[-1].s_val));
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array int32")==0){ // hw3_in04
                                       printf("PRINTLN int32\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array float32")==0){
                                       printf("PRINTLN float32\n");
                                   } // hw3_in04
                                   else{
                                       int i =0;  char* c = "";
                                       for(i=0;i<100;i++){
                                           if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                               c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                               break;
                                           }
                                       }
                                       printf("PRINTLN %s\n",c);
                                       
                                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }

                                   //*//hw3_01
                                   if(strcmp((yyvsp[-1].s_val),"int32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"float32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array int32")==0){ //hw3_in04
                                       fprintf(file,"\tiaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                   }
                                   else if(strcmp((yyvsp[-1].s_val),"array float32")==0){
                                       fprintf(file,"\tfaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                   } //hw3_in04
                                   else if(strcmp((yyvsp[-1].s_val),"string")==0){ // hw3_in
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                   } // hw3_in
                                   else if(strcmp((yyvsp[-1].s_val),"bool")==0){ // hw3_in02
                                       fprintf(file,"\tifne L_cmp_%d\n",label1);
                                       fprintf(file,"\tldc \"%s\"\n","false");
                                       fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                       fprintf(file,"L_cmp_%d:\n",label1);
                                       label1 = label1 +2 ;
                                       fprintf(file,"\tldc \"%s\"\n","true");
                                       fprintf(file,"L_cmp_%d:\n",label2);
                                       label2 = label2 +2 ;
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                   } // hw3_in02 
                                   else if(strcmp((yyvsp[-1].s_val),"int32")!=0 && strcmp((yyvsp[-1].s_val),"float32")!=0 && strcmp((yyvsp[-1].s_val),"string")!=0 && strcmp((yyvsp[-1].s_val),"bool")!=0 ){
                                       int i=0;   char* c1 = "";   int address1 =0;
                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp((yyvsp[-1].s_val),my_table[now_scope_level].te[i].name)==0){
                                               c1 = my_table[now_scope_level].te[i].type;
                                               address1 = my_table[now_scope_level].te[i].address;
                                               break;
                                           }
                                       }

                                       if(strcmp(c1,"int32")==0 ){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                       }
                                       else if(strcmp(c1,"float32")==0 ){
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                       }
                                       else if(strcmp(c1,"string")==0){ // hw3_in03
                                           fprintf(file,"\taload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                       } 
                                       else if(strcmp(c1,"bool")==0){ 
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tifne L_cmp_%d\n",label1);
                                           fprintf(file,"\tldc \"%s\"\n","false");
                                           fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                           fprintf(file,"L_cmp_%d:\n",label1);
                                           label1 = label1 +2 ;
                                           fprintf(file,"\tldc \"%s\"\n","true");
                                           fprintf(file,"L_cmp_%d:\n",label2);
                                           label2 = label2 +2 ;
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                       } // hw3_in03

                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }
                                   //*//hw3_01
                                 }
#line 3435 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3439 "y.tab.c" /* yacc.c:1646  */
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
#line 2014 "compiler_hw3.y" /* yacc.c:1906  */


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

    HAS_ERROR = false;
    /*---*/

    /*---*/
    /*if(access("hw3.j",0)==0){
        remove("hw3.j");
    }*/

    file = fopen("hw3.j","w");

    fprintf(file,".source hw3.j\n.class public Main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100  ; Define your storage size.\n.limit locals 100 ; Define your local space number.\n");

    /*---*/

    yylineno = 0;
    yyparse();

    dump_symbol(now_scope_level);  lookup_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    /*---*/
    fprintf(file,"\treturn\n.end method\n");
    fclose(file);
    /*---*/

    if (HAS_ERROR) {
        remove("hw3.j");
    }

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



