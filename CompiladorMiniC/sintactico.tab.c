/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"

/*flag para error léxico o semántico.*/
extern int hayError;

/*Lista de símbolos*/
Lista tablaSimb;
int contCadenas = 1;	/*Para no repetir identificadores de cadenas*/
Tipo tipo;

int esConst(char *simb);
void anadeEntrada(char *simb, Tipo t);
int perteneceTabla(char *simb);
void imprimirTabla();

/* Generación de código*/
int registros[8] = {0};
int contador_etiq = 1;	/*Para no repetir nombres de etiquetas*/
char * selectRegistro();
void liberaRegistro(char * r);
void imprimirCodigo(ListaC codigo);
char * nuevaEtiqueta() ;


void yyerror();
extern int yylex();
extern int yylineno;

#line 104 "sintactico.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 35 "sintactico.y"

#include "listaCodigo.h"

#line 151 "sintactico.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    CONST = 259,
    WHILE = 260,
    DO = 261,
    FOR = 262,
    TO = 263,
    IF = 264,
    ELSE = 265,
    PRINT = 266,
    READ = 267,
    PARI = 268,
    PARD = 269,
    LLAVI = 270,
    LLAVD = 271,
    PYCO = 272,
    COMA = 273,
    ASIG = 274,
    IDEN = 275,
    ENTERO = 276,
    CAD = 277,
    SUMA = 278,
    REST = 279,
    MULT = 280,
    DIVI = 281,
    UMINUS = 282,
    OR = 283,
    AND = 284,
    LE = 285,
    LT = 286,
    GE = 287,
    GT = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "sintactico.y"

char *lexema;
ListaC codigo;

#line 201 "sintactico.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  44
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    65,    85,    85,    91,    91,    98,   104,
     108,   117,   128,   148,   155,   161,   179,   183,   209,   225,
     250,   272,   331,   335,   342,   346,   355,   366,   386,   409,
     434,   443,   452,   461,   471,   478,   482,   498,   507,   517,
     536,   545,   564,   574,   584
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "CONST", "WHILE", "DO", "FOR",
  "TO", "IF", "ELSE", "PRINT", "READ", "PARI", "PARD", "LLAVI", "LLAVD",
  "PYCO", "COMA", "ASIG", "IDEN", "ENTERO", "CAD", "SUMA", "REST", "MULT",
  "DIVI", "UMINUS", "OR", "AND", "LE", "LT", "GE", "GT", "$accept",
  "program", "$@1", "declarations", "$@2", "$@3", "identifier_list",
  "identifier", "statement_list", "statement", "print_list", "print_item",
  "read_list", "expression", "relational", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -62,     6,    -5,   -62,    15,    45,    57,   -62,    44,   -62,
     -62,    59,    56,    56,    73,    18,    75,    86,    99,   115,
     -62,   -62,    95,   -62,   114,    60,   -62,    64,    30,   129,
     116,    30,   -10,   117,    78,    30,    30,   -62,    56,   -62,
      30,   -62,   -62,    30,    32,   122,   119,    77,   -62,    35,
     -62,   101,   -62,    55,   -62,    96,   101,   -62,    81,   -62,
      18,    30,    30,    30,    30,    30,    30,    18,   123,   -10,
     124,   125,   -62,   -62,   -62,    71,    71,   -62,   -62,    85,
      -7,    -6,   132,   -62,   -62,   -62,   -62,    30,    30,    30,
      30,   126,    30,    30,    30,    18,   101,   101,   101,   101,
     -62,   -62,   -62,   106,   -62,    30,    12,    18,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     8,    14,     4,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     3,     0,    13,    11,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     7,
       0,    36,    37,     0,     0,     0,     0,     0,    27,     0,
      24,    26,    28,     0,    16,     0,    12,    10,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    35,    19,    30,    31,    32,    33,    44,
       0,     0,    18,    22,    25,    23,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    40,    39,    38,
      20,    43,    42,     0,    17,     0,     0,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -62,   -62,   131,   108,   127,   -15,
     -62,    70,   -62,   -27,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,    12,    13,    25,    26,    11,    23,
      49,    50,    53,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    44,    94,    40,    47,    51,     3,    91,    55,    56,
      41,    42,    48,    58,    43,     4,    59,    61,    62,    63,
      64,    92,    93,    14,    15,    16,   107,    17,     5,    18,
      19,   101,   102,    20,    75,    76,    77,    78,    22,    81,
      92,    93,    51,    40,   106,    74,    60,     9,    10,    68,
      41,    42,    82,    69,    43,    61,    62,    63,    64,     6,
      96,    97,    98,    99,    14,    15,    16,   103,    17,    70,
      18,    19,     7,    71,    20,    21,    24,    37,    38,    22,
     104,    39,    38,    14,    15,    16,    28,    17,    30,    18,
      19,    67,   108,    20,    54,    73,    63,    64,    22,    31,
      61,    62,    63,    64,    61,    62,    63,    64,    61,    62,
      63,    64,    32,    72,    35,    87,    88,    89,    90,    61,
      62,    63,    64,   105,    61,    62,    63,    64,    33,    61,
      62,    63,    64,    36,    45,    65,    46,    52,    66,    84,
      83,    85,    95,   100,    27,    86,    57,    34
};

static const yytype_int8 yycheck[] =
{
      15,    28,     8,    13,    31,    32,     0,    14,    35,    36,
      20,    21,    22,    40,    24,    20,    43,    23,    24,    25,
      26,    28,    29,     5,     6,     7,    14,     9,    13,    11,
      12,    92,    93,    15,    61,    62,    63,    64,    20,    66,
      28,    29,    69,    13,   105,    60,    14,     3,     4,    14,
      20,    21,    67,    18,    24,    23,    24,    25,    26,    14,
      87,    88,    89,    90,     5,     6,     7,    94,     9,    14,
      11,    12,    15,    18,    15,    16,    20,    17,    18,    20,
      95,    17,    18,     5,     6,     7,    13,     9,    13,    11,
      12,    14,   107,    15,    16,    14,    25,    26,    20,    13,
      23,    24,    25,    26,    23,    24,    25,    26,    23,    24,
      25,    26,    13,    17,    19,    30,    31,    32,    33,    23,
      24,    25,    26,    17,    23,    24,    25,    26,    13,    23,
      24,    25,    26,    19,     5,    13,    20,    20,    19,    69,
      17,    17,    10,    17,    13,    20,    38,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    36,     0,    20,    13,    14,    15,    37,     3,
       4,    42,    38,    39,     5,     6,     7,     9,    11,    12,
      15,    16,    20,    43,    20,    40,    41,    40,    13,    43,
      13,    13,    13,    13,    42,    19,    19,    17,    18,    17,
      13,    20,    21,    24,    47,     5,    20,    47,    22,    44,
      45,    47,    20,    46,    16,    47,    47,    41,    47,    47,
      14,    23,    24,    25,    26,    13,    19,    14,    14,    18,
      14,    18,    17,    14,    43,    47,    47,    47,    47,    47,
      48,    47,    43,    17,    45,    17,    20,    30,    31,    32,
      33,    14,    28,    29,     8,    10,    47,    47,    47,    47,
      17,    48,    48,    47,    43,    17,    48,    14,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    35,    38,    37,    39,    37,    37,    40,
      40,    41,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    48,    48
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     0,     5,     0,     1,
       3,     1,     3,     2,     0,     4,     3,     7,     5,     5,
       7,    11,     5,     5,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 65 "sintactico.y"
       {
              tablaSimb=creaLS();
       }
#line 1448 "sintactico.tab.c"
    break;

  case 3:
#line 69 "sintactico.y"
       {

              concatenaLC((yyvsp[-2].codigo), (yyvsp[-1].codigo));
              if (hayError) {
                     printf("Se han producido errores.\n");
              }
              else {
                     imprimirTabla();
                     imprimirCodigo((yyvsp[-2].codigo));
              }
              liberaLS(tablaSimb);
              liberaLC((yyvsp[-2].codigo));
       }
#line 1466 "sintactico.tab.c"
    break;

  case 4:
#line 85 "sintactico.y"
                                {tipo = VARIABLE;}
#line 1472 "sintactico.tab.c"
    break;

  case 5:
#line 86 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-4].codigo);
              concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
              liberaLC((yyvsp[-1].codigo));
       }
#line 1482 "sintactico.tab.c"
    break;

  case 6:
#line 91 "sintactico.y"
                            {tipo = CONSTANTE;}
#line 1488 "sintactico.tab.c"
    break;

  case 7:
#line 92 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-4].codigo);
              concatenaLC((yyval.codigo), (yyvsp[-1].codigo));
              liberaLC((yyvsp[-1].codigo));
       }
#line 1498 "sintactico.tab.c"
    break;

  case 8:
#line 98 "sintactico.y"
       {
              (yyval.codigo) = creaLC();
       }
#line 1506 "sintactico.tab.c"
    break;

  case 9:
#line 105 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[0].codigo);
       }
#line 1514 "sintactico.tab.c"
    break;

  case 10:
#line 109 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              liberaLC((yyvsp[0].codigo));
       }
#line 1524 "sintactico.tab.c"
    break;

  case 11:
#line 118 "sintactico.y"
       {
              if(!perteneceTabla((yyvsp[0].lexema))) {
                     anadeEntrada((yyvsp[0].lexema),tipo);
              }
              else {	/*No se puede declarar una variable ya declarada*/
                     printf("Error semántico: Variable %s ya declarada. Linea: %d\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }
              (yyval.codigo) = creaLC();
       }
#line 1539 "sintactico.tab.c"
    break;

  case 12:
#line 129 "sintactico.y"
       {
              if(!perteneceTabla((yyvsp[-2].lexema))) {
                     anadeEntrada((yyvsp[-2].lexema),tipo);
              }
              else {	/*No se puede declarar una variable ya declarada*/
                     printf("Error semántico: Variable %s ya declarada. Linea: %d.\n", (yyvsp[-2].lexema), yylineno);
                     hayError = 1;
              }
              (yyval.codigo) = (yyvsp[0].codigo);
              char * id = (char *) malloc(strlen((yyvsp[-2].lexema))+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"sw", recuperaResLC((yyvsp[0].codigo)), strdup(strcat(id, (yyvsp[-2].lexema))), NULL};
              free(id);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaRegistro(oper.res);
       }
#line 1560 "sintactico.tab.c"
    break;

  case 13:
#line 149 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-1].codigo);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              liberaLC((yyvsp[0].codigo));
       }
#line 1570 "sintactico.tab.c"
    break;

  case 14:
#line 155 "sintactico.y"
       {
              (yyval.codigo) = creaLC();
       }
#line 1578 "sintactico.tab.c"
    break;

  case 15:
#line 162 "sintactico.y"
       {
              if(!perteneceTabla((yyvsp[-3].lexema))) {
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", (yyvsp[-3].lexema), yylineno);
                     hayError = 1;
              }
              else if (esConst((yyvsp[-3].lexema))) {
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", (yyvsp[-3].lexema), yylineno);
                     hayError = 1;
              }
              (yyval.codigo) = (yyvsp[-1].codigo);
              char * id = (char *) malloc(strlen((yyvsp[-3].lexema))+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"sw", recuperaResLC((yyvsp[-1].codigo)), strdup(strcat(id, (yyvsp[-3].lexema))), NULL};
              free(id);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaRegistro(oper.res);
       }
#line 1600 "sintactico.tab.c"
    break;

  case 16:
#line 180 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-1].codigo);
       }
#line 1608 "sintactico.tab.c"
    break;

  case 17:
#line 184 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-4].codigo);
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();

              // beqz $ti, $lj1
              Operacion oper1 = (Operacion) {"beqz", recuperaResLC((yyvsp[-4].codigo)), etiq1, NULL};
              // b $lj2
              Operacion oper2 = (Operacion) {"b", etiq2, NULL, NULL};
              // etiq1:
              Operacion oper3 = (Operacion) {"etiq", etiq1, NULL, NULL};
              // etiq2:
              Operacion oper4 = (Operacion) {"etiq", etiq2, NULL, NULL};

              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);

              liberaRegistro(recuperaResLC((yyvsp[-4].codigo)));
              liberaLC((yyvsp[-2].codigo));
              liberaLC((yyvsp[0].codigo));
       }
#line 1638 "sintactico.tab.c"
    break;

  case 18:
#line 210 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              char * etiq = nuevaEtiqueta();
              // beqz $ti, etiq
              Operacion oper1 = (Operacion) {"beqz", recuperaResLC((yyvsp[-2].codigo)), etiq, NULL};
              // etiq:
              Operacion oper2 = (Operacion) {"etiq", etiq, NULL, NULL};
              
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);

              liberaRegistro(recuperaResLC((yyvsp[-2].codigo)));
              liberaLC((yyvsp[0].codigo));
       }
#line 1658 "sintactico.tab.c"
    break;

  case 19:
#line 226 "sintactico.y"
       {
              (yyval.codigo) = creaLC();
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();
              // etiq1:
              Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
              // beqz $ti, etiq2
              Operacion oper2 = (Operacion) {"beqz", recuperaResLC((yyvsp[-2].codigo)), etiq2, NULL};
              // b etiq 1
              Operacion oper3 = (Operacion) {"b", etiq1, NULL, NULL};
              // etiq2:
              Operacion oper4 = (Operacion) {"etiq", etiq2, NULL, NULL};
              
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);
              
              liberaRegistro(recuperaResLC((yyvsp[-2].codigo)));
              liberaLC((yyvsp[-2].codigo));
              liberaLC((yyvsp[0].codigo));
       }
#line 1687 "sintactico.tab.c"
    break;

  case 20:
#line 251 "sintactico.y"
       {
	      (yyval.codigo) = creaLC();
              char * etiq1 = nuevaEtiqueta();
	      /* etiq1 */
	      Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
	      /* beqz $ti, etiq2 (saltar al inicio del bucle si se cumple la condicion del bucle) */
              Operacion oper2 = (Operacion) {"beqz", recuperaResLC((yyvsp[-2].codigo)), etiq1, NULL};

	      /* etiqueta de inicio del bucle */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
	      /* sentencias */
	      concatenaLC((yyval.codigo), (yyvsp[-5].codigo));
	      /* condicion del bucle */
	      concatenaLC((yyval.codigo), (yyvsp[-2].codigo));
	      /* comprobación de la condicion */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
	      
	      liberaRegistro(recuperaResLC((yyvsp[-2].codigo)));
	      liberaLC((yyvsp[-5].codigo));
	      liberaLC((yyvsp[-2].codigo));
       }
#line 1713 "sintactico.tab.c"
    break;

  case 21:
#line 273 "sintactico.y"
       {
              if(!perteneceTabla((yyvsp[-8].lexema))) {
		     /* Si la variable no ha sido declarada no se le puede asignar un valor */
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", (yyvsp[-8].lexema), yylineno);
                     hayError = 1;
              }
              else if (esConst((yyvsp[-8].lexema))) {
		     /* No se puede usar una constante como iterador por que su valor no puede cambiar */
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", (yyvsp[-8].lexema), yylineno);
                     hayError = 1;
              }

	      (yyval.codigo) = creaLC();
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
              char * id = (char *) malloc(strlen((yyvsp[-8].lexema))+1);
              strcpy(id, "_");
              Operacion oper2 = (Operacion) {"sw", recuperaResLC((yyvsp[-6].codigo)), strdup(strcat(id, (yyvsp[-8].lexema))), NULL};
	      free(id);
	      Operacion oper3 = (Operacion) {"bgt", recuperaResLC((yyvsp[-6].codigo)), recuperaResLC((yyvsp[-4].codigo)), etiq2};
  	      Operacion oper4 = (Operacion) {"beqz", recuperaResLC((yyvsp[-2].codigo)), etiq2, NULL};
	      Operacion oper5 = (Operacion) {"addi", recuperaResLC((yyvsp[-6].codigo)), recuperaResLC((yyvsp[-6].codigo)), "1"};
	      Operacion oper6 = (Operacion) {"b", etiq1, NULL, NULL};
	      Operacion oper7 = (Operacion) {"etiq", etiq2, NULL, NULL};

	      /* etiqueta inicio del bucle */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);

	      /* cargar en la variable el valor del iterador */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);

	      /* comprobar que el iterador no ha excedido su valor máximo */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);

	      /* comprbación de la condicion de finalización */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);
	
	      /* bloque de sentencuas del bucle for */
	      concatenaLC((yyval.codigo), (yyvsp[0].codigo));

	      /* incrementar el iterador en 1 */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper5);

	      /* saltar al inicio del bucle */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper6);

	      /* etiqueta del final del bucle */
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper7);

	      liberaRegistro(recuperaResLC((yyvsp[-6].codigo)));
	      liberaRegistro(recuperaResLC((yyvsp[-4].codigo)));
	      liberaRegistro(recuperaResLC((yyvsp[-6].codigo)));
	      liberaLC((yyvsp[-6].codigo));
	      liberaLC((yyvsp[-4].codigo));
	      liberaLC((yyvsp[-2].codigo));
	      liberaLC((yyvsp[0].codigo));
       }
#line 1776 "sintactico.tab.c"
    break;

  case 22:
#line 332 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
       }
#line 1784 "sintactico.tab.c"
    break;

  case 23:
#line 336 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
       }
#line 1792 "sintactico.tab.c"
    break;

  case 24:
#line 343 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[0].codigo);
       }
#line 1800 "sintactico.tab.c"
    break;

  case 25:
#line 347 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo), (yyvsp[0].codigo));
              liberaLC((yyvsp[0].codigo));
       }
#line 1810 "sintactico.tab.c"
    break;

  case 26:
#line 356 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[0].codigo);
              Operacion oper1 = (Operacion) {"li", "$v0", "1", NULL};
              Operacion oper2 = (Operacion) {"move", "$a0", recuperaResLC((yyvsp[0].codigo)), NULL};
              Operacion oper3 = (Operacion) {"syscall", NULL, NULL, NULL};
              insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo),finalLC((yyval.codigo)), oper3);
              liberaRegistro(recuperaResLC((yyvsp[0].codigo)));
       }
#line 1825 "sintactico.tab.c"
    break;

  case 27:
#line 367 "sintactico.y"
       {
              anadeEntrada((yyvsp[0].lexema), CADENA);

              (yyval.codigo) = creaLC();
              Operacion oper1 = (Operacion) {"li", "$v0", "4", NULL};
              char * str = (char *) malloc(10);
              sprintf(str, "%s%d", "$str", contCadenas);                              
              Operacion oper2 = (Operacion) {"la", "$a0", strdup(str), NULL};
              free(str);
              Operacion oper3 = (Operacion) {"syscall", NULL, NULL, NULL};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);

              contCadenas++;
       }
#line 1846 "sintactico.tab.c"
    break;

  case 28:
#line 387 "sintactico.y"
       {
              if (!perteneceTabla((yyvsp[0].lexema))) {	//Si la variable no ha sido declarada no se le puede asignar un valor
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }					//Si es una constante su valor no se puede cambiar
              else if (esConst((yyvsp[0].lexema))) {
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }
              
              (yyval.codigo) = creaLC();
              Operacion oper1 = (Operacion) {"li", "$v0", "5", NULL};
              Operacion oper2 = (Operacion) {"syscall", NULL, NULL, NULL};
              char * id = (char *) malloc(strlen((yyvsp[0].lexema)) + 1);
              strcpy(id, "_");
              Operacion oper3 = (Operacion) {"sw", "$v0", strdup(strcat(id, (yyvsp[0].lexema))), NULL};
              free(id);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);

       }
#line 1873 "sintactico.tab.c"
    break;

  case 29:
#line 410 "sintactico.y"
       {
              if (!perteneceTabla((yyvsp[0].lexema))) {	//Si la variable no ha sido declarada no se le puede asignar un valor
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }
              else if (esConst((yyvsp[0].lexema))) {		//Si es una constante su valor no se puede cambiar
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }
              
              (yyval.codigo) = (yyvsp[-2].codigo);
              Operacion oper1 = (Operacion) {"li", "$v0", "5", NULL};
              Operacion oper2 = (Operacion) {"syscall", NULL, NULL, NULL};
              char * id = (char *) malloc(strlen((yyvsp[0].lexema)) + 1);
              strcpy(id, "_");
              Operacion oper3 = (Operacion) {"sw", "$v0", strdup(strcat(id, (yyvsp[0].lexema))), NULL};
              free(id);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
       }
#line 1899 "sintactico.tab.c"
    break;

  case 30:
#line 435 "sintactico.y"
       {	
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"add", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 1912 "sintactico.tab.c"
    break;

  case 31:
#line 444 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"sub", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 1925 "sintactico.tab.c"
    break;

  case 32:
#line 453 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"mul", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 1938 "sintactico.tab.c"
    break;

  case 33:
#line 462 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"div", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 1951 "sintactico.tab.c"
    break;

  case 34:
#line 472 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[0].codigo);
              char * reg = recuperaResLC((yyvsp[0].codigo));
              Operacion oper = (Operacion) {"neg", reg, reg};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
       }
#line 1962 "sintactico.tab.c"
    break;

  case 35:
#line 479 "sintactico.y"
       {
              (yyval.codigo) = (yyvsp[-1].codigo);
       }
#line 1970 "sintactico.tab.c"
    break;

  case 36:
#line 483 "sintactico.y"
       {
              if (!perteneceTabla((yyvsp[0].lexema))) {	//Si el identificador no ha sido declarado no se puede operar con el
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", (yyvsp[0].lexema), yylineno);
                     hayError = 1;
              }

              (yyval.codigo) = creaLC();
              char * reg = selectRegistro();
              char * id = (char *) malloc(strlen((yyvsp[0].lexema))+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"lw", reg, strdup(strcat(id, (yyvsp[0].lexema))), NULL};
              free(id);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              guardaResLC((yyval.codigo), reg);
       }
#line 1990 "sintactico.tab.c"
    break;

  case 37:
#line 499 "sintactico.y"
       {
              (yyval.codigo) = creaLC();
              char * reg = selectRegistro();
              Operacion oper = (Operacion) {"li", reg, (yyvsp[0].lexema), NULL};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              guardaResLC((yyval.codigo), reg);
       }
#line 2002 "sintactico.tab.c"
    break;

  case 38:
#line 508 "sintactico.y"
       {
       
       	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"glt", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
              }
#line 2016 "sintactico.tab.c"
    break;

  case 39:
#line 518 "sintactico.y"
       {
	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
	      char * auxiliar = selectRegistro();
	      char * etiq1 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"li", auxiliar, "0", NULL};		/* Poner valor a 0 */
	      Operacion oper2 = (Operacion) {"blt", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)), etiq1}; /* Saltar sin poner el resultado a 1 */
	      Operacion oper3 = (Operacion) {"li", auxiliar, "1", NULL};		/* Poner valor a 1 */
  	      Operacion oper4 = (Operacion) {"etiq", etiq1, NULL, NULL};	
              Operacion oper5 = (Operacion) {"move", recuperaResLC((yyvsp[-2].codigo)), auxiliar, NULL}; /* Cargar resultado */
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
  	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper5);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(auxiliar);
       }
#line 2039 "sintactico.tab.c"
    break;

  case 40:
#line 537 "sintactico.y"
       {
	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"slt", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 2052 "sintactico.tab.c"
    break;

  case 41:
#line 546 "sintactico.y"
       {
	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
	      char * auxiliar = selectRegistro();
	      char * etiq1 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"li", auxiliar, "0", NULL};		/* Poner valor a 0 */
	      Operacion oper2 = (Operacion) {"bgt", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo)), etiq1}; /* Saltar sin poner el resultado a 1 */
	      Operacion oper3 = (Operacion) {"li", recuperaResLC((yyvsp[-2].codigo)), "1", NULL};	/* Poner valor a 1 */
	      Operacion oper4 = (Operacion) {"etiq", etiq1, NULL, NULL};
              Operacion oper5 = (Operacion) {"move", recuperaResLC((yyvsp[-2].codigo)), auxiliar, NULL}; /* Cargar resultado */
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper1);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper2);
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper3);
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper4);
	      insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper5);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper3.arg2);
       }
#line 2075 "sintactico.tab.c"
    break;

  case 42:
#line 565 "sintactico.y"
       {

	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"and", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 2089 "sintactico.tab.c"
    break;

  case 43:
#line 575 "sintactico.y"
       {

	      (yyval.codigo) = (yyvsp[-2].codigo);
              concatenaLC((yyval.codigo),(yyvsp[0].codigo));
              Operacion oper = (Operacion) {"or", recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[-2].codigo)), recuperaResLC((yyvsp[0].codigo))};
              insertaLC((yyval.codigo), finalLC((yyval.codigo)), oper);
              liberaLC((yyvsp[0].codigo));
              liberaRegistro(oper.arg2);
       }
#line 2103 "sintactico.tab.c"
    break;

  case 44:
#line 585 "sintactico.y"
       {      	
	      (yyval.codigo) = (yyvsp[0].codigo);
       }
#line 2111 "sintactico.tab.c"
    break;


#line 2115 "sintactico.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 591 "sintactico.y"


void yyerror()
{
printf("Se ha producido un error sintactico en esta expresion.\n");
}

/*Función que imprime el segmento de datos del programa*/
void imprimirTabla() {

       printf("####################\n");
       printf("# Seccion de datos\n");
       printf("\t.data\n\n");
       PosicionLista p = inicioLS(tablaSimb);
       while (p != finalLS(tablaSimb)) {
              Simbolo aux = recuperaLS(tablaSimb, p);

              switch(aux.tipo) {
                     case VARIABLE:
                     case CONSTANTE:
                            printf("_%s:\n\t.word 0\n", aux.nombre);
                            break;
                     case CADENA:
                            printf("$str%d:\n\t.asciiz %s\n", aux.valor, aux.nombre);
                            break;
                     default:
                            printf("Tipo no reconocido\n");
                            break;
              }
              p = siguienteLS(tablaSimb, p);
       }

}

/*Función que comprueba si un identificador esta definido en la tabla de simbolos*/
int perteneceTabla(char *simb){

       PosicionLista p = buscaLS(tablaSimb, simb);
       return p != finalLS(tablaSimb); 
}

/*Función que añade un identificador en la tabla de simbolos*/
void anadeEntrada(char *simb, Tipo t){

       Simbolo aux;
       aux.nombre = simb;
       aux.tipo = t;
       aux.valor = contCadenas;
       insertaLS(tablaSimb, finalLS(tablaSimb), aux);
}

/*Función que comprueba si el identificador corresponde con una constante*/
int esConst(char *simb){

       PosicionLista p = buscaLS(tablaSimb, simb);
       Simbolo aux = recuperaLS(tablaSimb, p);
       return aux.tipo == CONSTANTE;
}

/*Funcion que busca el primer registro libre. En su defecto causa un error*/
char * selectRegistro(){

       int i = 0;
       while (i < 8 && registros[i]) i++;
       if(i < 8) {
              char r[3];
              snprintf(r, 4, "$t%d", i);         
              registros[i] = 1;
              return strdup(r);
       }
       printf("* ERROR: Registros agotados. Programa abortado.\n");
       exit(1);
}

/*Función que marca como libre un registro*/
void liberaRegistro(char *r){

       int i = r[2] - '0';
       registros[i] = 0;
}

/*Función que imprime el segmento de codigo del programa*/
void imprimirCodigo(ListaC codigo){

       printf("\n####################\n");
       printf("# Seccion de codigo\n");
       printf("\t.text\n\t.globl main\nmain:\n");
       
       PosicionListaC p = inicioLC(codigo);
       Operacion oper;
       while (p != finalLC(codigo)) {
              oper = recuperaLC(codigo,p);
              if (!strcmp(oper.op, "etiq")) {
                     printf("%s:\n", oper.res);
                     p = siguienteLC(codigo,p);
                     continue;
              }
              printf("\t%s",oper.op);
              if (oper.res) printf(" %s",oper.res);
              if (oper.arg1) printf(",%s",oper.arg1);
              if (oper.arg2) printf(",%s",oper.arg2);
              printf("\n");
              p = siguienteLC(codigo,p);
       }
       printf("####################\n");
       printf("# Fin\n");
       printf("\tli $v0,10\n\tsyscall\n");
}
/*Función para generar una nueva etiqueta de salto*/
char * nuevaEtiqueta() {

       char aux[10];
       sprintf(aux, "$l%d", contador_etiq++);           
       return strdup(aux);
}
