/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "itsh.y"

#include <stdio.h>
#include <stdlib.h>
#include "merit_bat.h"
#include <time.h>

char cmd_line[BODY_LINE_MAX_LEN+1];

extern CMD_COM_PARAM	G_CMD_COM_PARAM;
extern char *itc_strdup(const char *);


#line 83 "itsh.tab.c"

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
    LT_DOUBLE = 258,
    LT_COMMA = 259,
    LT_ON = 260,
    LT_OFF = 261,
    LT_OKNG = 262,
    LT_POS_ERR = 263,
    LT_IP_ADDR = 264,
    LT_TEXT = 265,
    LT_HEX = 266,
    LT_INT2 = 267,
    LT_INT10 = 268,
    LT_INTEGER = 269,
    CMD_TOKEN_H = 270,
    CMD_TOKEN_SC = 271,
    CMD_TOKEN_SA = 272,
    CMD_TOKEN_BT = 273,
    CMD_TOKEN_A = 274,
    CMD_TOKEN_EG = 275,
    CMD_TOKEN_AM = 276,
    CMD_TOKEN_AMON = 277,
    CMD_TOKEN_AMOF = 278,
    CMD_TOKEN_CL = 279,
    CMD_TOKEN_CM0 = 280,
    CMD_TOKEN_CM1 = 281,
    CMD_TOKEN_D0 = 282,
    CMD_TOKEN_D1 = 283,
    CMD_TOKEN_D2 = 284,
    CMD_TOKEN_D3 = 285,
    CMD_TOKEN_M0 = 286,
    CMD_TOKEN_M1 = 287,
    CMD_TOKEN_M2 = 288,
    CMD_TOKEN_M3 = 289,
    CMD_TOKEN_M4 = 290,
    CMD_TOKEN_M5 = 291,
    CMD_TOKEN_M6 = 292,
    CMD_TOKEN_M7 = 293,
    CMD_TOKEN_M8 = 294,
    CMD_TOKEN_T = 295,
    CMD_TOKEN_P = 296,
    CMD_TOKEN_I = 297,
    CMD_TOKEN_R = 298,
    CMD_TOKEN_C = 299,
    CMD_TOKEN_N = 300,
    CMD_TOKEN_F = 301,
    CMD_TOKEN_W = 302,
    CMD_TOKEN_U = 303,
    CMD_TOKEN_J = 304,
    CMD_TOKEN_EC = 305,
    CMD_TOKEN_FC = 306,
    CMD_TOKEN_HC = 307,
    CMD_TOKEN_LC = 308,
    CMD_TOKEN_OV = 309,
    CMD_TOKEN_FT = 310,
    CMD_TOKEN_FS = 311,
    CMD_TOKEN_HS = 312,
    CMD_TOKEN_HE = 313,
    CMD_TOKEN_HF = 314,
    CMD_TOKEN_HH = 315,
    CMD_TOKEN_HL = 316,
    CMD_TOKEN_AH = 317,
    CMD_TOKEN_PN = 318,
    CMD_TOKEN_VR = 319,
    CMD_TOKEN_XX = 320,
    CMD_TOKEN_SD_1 = 321,
    CMD_TOKEN_SD_2 = 322,
    CMD_TOKEN_NENPI = 323,
    CMD_TOKEN_V = 324,
    CMD_TOKEN_EA = 325,
    CMD_TOKEN_PA = 326,
    CMD_TOKEN_PB = 327,
    CMD_TOKEN_PC = 328,
    CMD_TOKEN_UA = 329,
    CMD_TOKEN_UB = 330,
    CMD_TOKEN_SW = 331,
    CMD_TOKEN_ST = 332,
    CMD_TOKEN_MC = 333,
    CMD_TOKEN_MT = 334,
    CMD_TOKEN_DA = 335,
    CMD_TOKEN_SL = 336,
    CMD_TOKEN_TD = 337,
    CMD_TOKEN_AE = 338,
    CMD_TOKEN_AR = 339,
    CMD_TOKEN_X1 = 340,
    TOKEN_ERROR = 341,
    LT_HEADER_ONE_LINE = 342,
    LT_RETURN_HEADER = 343,
    LT_RETURN = 344,
    LT_RETURN_2 = 345,
    CMD_TOKEN_HA = 346,
    CMD_TOKEN_LK = 347,
    CMD_TOKEN_YD = 348,
    CMD_TOKEN_OT = 349,
    CMD_TOKEN_M = 350,
    CMD_TOKEN_JH = 351,
    CMD_TOKEN_JS = 352,
    CMD_TOKEN_JE = 353,
    CMD_TOKEN_AB = 354,
    CMD_TOKEN_SS = 355,
    CMD_TOKEN_SR = 356,
    CMD_TOKEN_SG = 357,
    CMD_TOKEN_SU = 358,
    CMD_TOKEN_HD = 359,
    CMD_TOKEN_HQ = 360,
    CMD_TOKEN_HP = 361,
    CMD_TOKEN_DG = 362,
    CMD_TOKEN_DU = 363,
    CMD_TOKEN_DC = 364,
    CMD_TOKEN_DR = 365,
    CMD_TOKEN_ASTRSK1 = 366,
    CMD_TOKEN_ASTRSK2 = 367,
    CMD_TOKEN_NUMSIGN = 368,
    CMD_TOKEN_FD = 369,
    CMD_TOKEN_FR = 370,
    CMD_TOKEN_FQ = 371,
    CMD_TOKEN_VE = 372,
    CMD_TOKEN_TC = 373,
    CMD_TOKEN_RR = 374,
    CMD_TOKEN_SSID = 375,
    CMD_TOKEN_KL = 376
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "itsh.y"

	int intval;
	double dblval;
	char *strval;

#line 260 "itsh.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  213
/* YYNRULES -- Number of rules.  */
#define YYNRULES  367
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1026

#define YYUNDEFTOK  2
#define YYMAXUTOK   376


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   207,   207,   211,   215,   219,   227,   234,   235,   239,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   298,   332,
     341,   353,   364,   375,   388,   396,   405,   415,   425,   433,
     441,   449,   462,   478,   486,   494,   502,   510,   518,   526,
     534,   542,   550,   558,   566,   576,   584,   593,   608,   615,
     623,   666,   680,   689,   698,   707,   716,   724,   733,   743,
     752,   760,   769,   777,   785,   793,   804,   805,   809,   812,
     813,   816,   817,   820,   821,   824,   825,   828,   829,   832,
     833,   836,   837,   840,   841,   844,   845,   848,   849,   852,
     853,   856,   857,   860,   861,   864,   865,   868,   869,   872,
     873,   876,   877,   880,   881,   884,   885,   888,   889,   892,
     893,   896,   897,   900,   901,   904,   905,   908,   909,   912,
     913,   916,   917,   920,   921,   928,   929,   930,   932,   937,
     939,   943,   945,   949,   951,   955,   957,   961,   963,   968,
     969,   974,   975,   980,   981,   986,   987,   988,   989,   991,
     997,   998,   999,  1000,  1002,  1007,  1008,  1013,  1014,  1019,
    1020,  1025,  1026,  1034,  1046,  1054,  1066,  1078,  1090,  1102,
    1114,  1127,  1134,  1146,  1156,  1166,  1179,  1187,  1195,  1203,
    1211,  1219,  1227,  1235,  1243,  1251,  1263,  1275,  1287,  1299,
    1311,  1323,  1335,  1347,  1359,  1371,  1383,  1395,  1407,  1419,
    1431,  1441,  1452,  1462,  1472,  1482,  1492,  1502,  1512,  1522,
    1532,  1538,  1548,  1558,  1568,  1578,  1588,  1598,  1608,  1618,
    1627,  1637,  1647,  1657,  1667,  1677,  1687,  1697,  1707,  1717,
    1727,  1737,  1747,  1757,  1764,  1782,  1789,  1804,  1814,  1824,
    1834,  1844,  1855,  1865,  1875,  1885,  1895,  1905,  1915,  1925,
    1935,  1945,  1952,  1962,  1969,  1979,  1989,  1999,  2009,  2016,
    2026,  2036,  2043,  2053,  2060,  2067,  2074,  2081,  2088,  2095,
    2102,  2109,  2116,  2123,  2130,  2140,  2150,  2160,  2170,  2180,
    2190,  2200,  2210,  2220,  2230,  2246,  2256,  2266,  2276,  2283,
    2290,  2297,  2304,  2314,  2321,  2328,  2335,  2342,  2352,  2363,
    2374,  2385,  2396,  2406,  2416,  2427,  2437,  2444,  2451,  2461,
    2471,  2481,  2494,  2503,  2515,  2529,  2543,  2557,  2571,  2585,
    2606,  2607,  2608,  2612,  2613,  2617,  2618,  2619
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LT_DOUBLE", "LT_COMMA", "LT_ON",
  "LT_OFF", "LT_OKNG", "LT_POS_ERR", "LT_IP_ADDR", "LT_TEXT", "LT_HEX",
  "LT_INT2", "LT_INT10", "LT_INTEGER", "CMD_TOKEN_H", "CMD_TOKEN_SC",
  "CMD_TOKEN_SA", "CMD_TOKEN_BT", "CMD_TOKEN_A", "CMD_TOKEN_EG",
  "CMD_TOKEN_AM", "CMD_TOKEN_AMON", "CMD_TOKEN_AMOF", "CMD_TOKEN_CL",
  "CMD_TOKEN_CM0", "CMD_TOKEN_CM1", "CMD_TOKEN_D0", "CMD_TOKEN_D1",
  "CMD_TOKEN_D2", "CMD_TOKEN_D3", "CMD_TOKEN_M0", "CMD_TOKEN_M1",
  "CMD_TOKEN_M2", "CMD_TOKEN_M3", "CMD_TOKEN_M4", "CMD_TOKEN_M5",
  "CMD_TOKEN_M6", "CMD_TOKEN_M7", "CMD_TOKEN_M8", "CMD_TOKEN_T",
  "CMD_TOKEN_P", "CMD_TOKEN_I", "CMD_TOKEN_R", "CMD_TOKEN_C",
  "CMD_TOKEN_N", "CMD_TOKEN_F", "CMD_TOKEN_W", "CMD_TOKEN_U",
  "CMD_TOKEN_J", "CMD_TOKEN_EC", "CMD_TOKEN_FC", "CMD_TOKEN_HC",
  "CMD_TOKEN_LC", "CMD_TOKEN_OV", "CMD_TOKEN_FT", "CMD_TOKEN_FS",
  "CMD_TOKEN_HS", "CMD_TOKEN_HE", "CMD_TOKEN_HF", "CMD_TOKEN_HH",
  "CMD_TOKEN_HL", "CMD_TOKEN_AH", "CMD_TOKEN_PN", "CMD_TOKEN_VR",
  "CMD_TOKEN_XX", "CMD_TOKEN_SD_1", "CMD_TOKEN_SD_2", "CMD_TOKEN_NENPI",
  "CMD_TOKEN_V", "CMD_TOKEN_EA", "CMD_TOKEN_PA", "CMD_TOKEN_PB",
  "CMD_TOKEN_PC", "CMD_TOKEN_UA", "CMD_TOKEN_UB", "CMD_TOKEN_SW",
  "CMD_TOKEN_ST", "CMD_TOKEN_MC", "CMD_TOKEN_MT", "CMD_TOKEN_DA",
  "CMD_TOKEN_SL", "CMD_TOKEN_TD", "CMD_TOKEN_AE", "CMD_TOKEN_AR",
  "CMD_TOKEN_X1", "TOKEN_ERROR", "LT_HEADER_ONE_LINE", "LT_RETURN_HEADER",
  "LT_RETURN", "LT_RETURN_2", "CMD_TOKEN_HA", "CMD_TOKEN_LK",
  "CMD_TOKEN_YD", "CMD_TOKEN_OT", "CMD_TOKEN_M", "CMD_TOKEN_JH",
  "CMD_TOKEN_JS", "CMD_TOKEN_JE", "CMD_TOKEN_AB", "CMD_TOKEN_SS",
  "CMD_TOKEN_SR", "CMD_TOKEN_SG", "CMD_TOKEN_SU", "CMD_TOKEN_HD",
  "CMD_TOKEN_HQ", "CMD_TOKEN_HP", "CMD_TOKEN_DG", "CMD_TOKEN_DU",
  "CMD_TOKEN_DC", "CMD_TOKEN_DR", "CMD_TOKEN_ASTRSK1", "CMD_TOKEN_ASTRSK2",
  "CMD_TOKEN_NUMSIGN", "CMD_TOKEN_FD", "CMD_TOKEN_FR", "CMD_TOKEN_FQ",
  "CMD_TOKEN_VE", "CMD_TOKEN_TC", "CMD_TOKEN_RR", "CMD_TOKEN_SSID",
  "CMD_TOKEN_KL", "$accept", "MAIL", "MAIL_HEADER", "MAIL_HEADER_LINES",
  "_MAIL_BODY", "MAIL_BODY", "MLTYPE_DAILY_NIGHT_OPE", "MLTYPE_ONLY_POS",
  "MLTYPE_DAILY_NIGHT_NON_OPE", "MLTYPE_DAILY_DAYTIME",
  "MLTYPE_DAILY_NIGHT_EXCEPTION", "MLTYPE_RESPONSE_RT", "MLTYPE_ALARM_SC",
  "MLTYPE_ALARM_SA", "MLTYPE_ALARM_BT", "MLTYPE_RESPONSE_AM",
  "MLTYPE_RESPONSE_CL", "MLTYPE_RESPONSE_CM0", "MLTYPE_RESPONSE_CM1",
  "MLTYPE_RESPONSE_CT0", "MLTYPE_RESPONSE_CT1", "MLTYPE_AMNG",
  "MLTYPE_HSOK", "MLTYPE_HSNG", "MLTYPE_HEOK", "MLTYPE_HENG",
  "MLTYPE_HFOK", "MLTYPE_HFNG", "MLTYPE_HHOK", "MLTYPE_HHNG",
  "MLTYPE_HLOK", "MLTYPE_HLNG", "MLTYPE_RESPONSE_AC", "MLTYPE_WARNING",
  "MLTYPE_SD", "MLTYPE_RM", "MLTYPE_XX_V7", "MLTYPE_TD",
  "MLTYPE_DAILY_OPE", "MLTYPE_DAILY_NOPE", "MLTYPE_ALARM_SS",
  "MLTYPE_ALARM_SR", "MLTYPE_ALARM_SG", "MLTYPE_ALARM_SU",
  "MLTYPE_RES_REMOTE_DL", "MLTYPE_ASTRSK", "MLTYPE_FDFD", "MLTYPE_HDHQHP",
  "MLTYPE_LKOK", "MLTYPE_AR", "MLTYPE_AE", "MLTYPE_RR", "MLTYPE_SSID",
  "MLTYPE_KL", "CMD_LINES_EGN_TP", "CMD_LINES_AH", "CMD_LINES_XX",
  "CMD_LINES_PN", "CMD_LINES_VR", "CMD_LINES_SD_2", "CMD_LINES_KADO_J",
  "CMD_LINES_AREA_NAIGAI_A", "CMD_LINES_ENGN_OIL_EC",
  "CMD_LINES_FUEL_FILTER_FC", "CMD_LINES_SADO_FILTER_HC",
  "CMD_LINES_SADO_CHANGE_LC", "CMD_LINES_OVER_OV",
  "CMD_LINES_FUEL_ONDO_FT", "CMD_LINES_FUEL_STATUS_FS", "CMD_LINES_NENPI",
  "CMD_LINES_IDOL_I", "CMD_LINES_RUN_R", "CMD_LINES_HIREACH_C",
  "CMD_LINES_NIBURA_N", "CMD_LINES_FUEL_F", "CMD_LINES_ENGN_W",
  "CMD_LINES_PUMP_U", "CMD_SET_TIER4A_V7", "CMD_LINES_SL", "CMD_LINES_TD",
  "CMD_LINES_X1", "CMD_LINES_NUMSIGN", "CMD_LINES_VE", "CMD_LINES_TC",
  "_CMD_LINES_EGN_TP", "_CMD_LINES_AH", "_CMD_LINES_XX", "_CMD_LINES_PN",
  "_CMD_LINES_VR", "_CMD_LINES_SD_2", "_CMD_LINES_X1",
  "_CMD_LINES_ASTRSK2", "_CMD_LINES_NUMSIGN", "_CMD_LINES_FDFQFR",
  "_CMD_LINES_HDHQHP", "_CMD_LINES_AE", "_CMD_LINES_AR", "_CMD_LINES_RR",
  "_CMD_LINES_KL", "_CMD_SET_TIER4A_V7", "CMD_LINE_POS",
  "CMD_LINE_HOUR_METER", "CMD_LINE_AREA_NAIGAI_A", "CMD_LINE_ALARM_SC",
  "CMD_LINE_ALARM_SA", "CMD_LINE_ALARM_BT", "CMD_LINE_EG",
  "CMD_LINE_AM_ON", "CMD_LINE_AM_OF", "CMD_LINE_AM", "CMD_LINE_CL",
  "CMD_LINE_CM0", "CMD_LINE_CM1", "CMD_LINE_D0", "CMD_LINE_D1",
  "CMD_LINE_D2", "CMD_LINE_D3", "CMD_LINE_M0", "CMD_LINE_M1",
  "CMD_LINE_M2", "CMD_LINE_M3", "CMD_LINE_M4", "CMD_LINE_M5",
  "CMD_LINE_M6", "CMD_LINE_M7", "CMD_LINE_M8", "CMD_LINE_EGN_T",
  "CMD_LINE_EGN_P", "CMD_LINE_IDOL_I", "CMD_LINE_RUN_R",
  "CMD_LINE_HIREACH_C", "CMD_LINE_NIBURA_N", "CMD_LINE_FUEL_F",
  "CMD_LINE_ENGN_W", "CMD_LINE_PUMP_U", "CMD_LINE_KADO_J",
  "CMD_LINE_ENGN_OIL_EC", "CMD_LINE_FUEL_FILTER_FC",
  "CMD_LINE_SADO_FILTER_HC", "CMD_LINE_SADO_CHANGE_LC", "CMD_LINE_OVER_OV",
  "CMD_LINE_FUEL_ONDO_FT", "CMD_LINE_FUEL_STATUS_FS", "CMD_LINE_AMNG",
  "CMD_LINE_HSOK", "CMD_LINE_HSNG", "CMD_LINE_HEOK", "CMD_LINE_HENG",
  "CMD_LINE_HFOK", "CMD_LINE_HFNG", "CMD_LINE_HHOK", "CMD_LINE_HHNG",
  "CMD_LINE_HLOK", "CMD_LINE_HLNG", "CMD_LINE_AH", "CMD_LINE_PN",
  "CMD_LINE_VR", "CMD_LINE_XX", "CMD_LINE_XX_V7", "CMD_LINE_SD_1",
  "CMD_LINE_SD_2", "CMD_LINE_SD_3", "CMD_LINE_NENPI", "CMD_LINE_V",
  "CMD_LINE_EA", "CMD_LINE_PA", "CMD_LINE_PB", "CMD_LINE_PC",
  "CMD_LINE_UA", "CMD_LINE_UB", "CMD_LINE_SW", "CMD_LINE_ST",
  "CMD_LINE_MC", "CMD_LINE_MT", "CMD_LINE_DA", "CMD_LINE_SL",
  "CMD_LINE_TD", "CMD_LINE_RES_TD", "CMD_LINE_AE", "CMD_LINE_AR",
  "CMD_LINE_X1", "CMD_LINE_HA", "CMD_LINE_LK", "CMD_LINE_YD",
  "CMD_LINE_OT", "CMD_LINE_M", "CMD_LINE_JH", "CMD_LINE_JS", "CMD_LINE_JE",
  "CMD_LINE_AB", "CMD_LINE_SS", "CMD_LINE_SR", "CMD_LINE_SG",
  "CMD_LINE_SU", "CMD_LINE_RES_REMOTE_DL", "CMD_LINE_ASTRSK1",
  "CMD_LINE_ASTRSK2", "CMD_LINE_NUMSIGN", "CMD_LINE_HD", "CMD_LINE_HP",
  "CMD_LINE_HQ", "CMD_LINE_FR", "CMD_LINE_FD", "CMD_LINE_FQ",
  "CMD_LINE_RR", "CMD_LINE_SSID", "CMD_LINE_LKOK", "CMD_LINE_VE",
  "CMD_LINE_TC", "CMD_LINE_KL", "LT_TEXT_EX", "LT_NUMERIC", "LT_INTVAL", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376
};
# endif

#define YYPACT_NINF (-486)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-160)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,  -486,  -486,    31,    11,    -3,  -486,  -486,   257,   257,
     257,    12,   257,   182,    40,    58,    37,    96,   168,   185,
     212,   215,   224,   232,   194,   241,   125,   227,   257,   257,
     257,   257,   257,   257,   257,    85,   194,   194,   139,   140,
     143,   202,   194,   194,   194,   194,   257,   151,    53,    90,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,     4,
      97,   106,   152,   -80,    94,    89,    72,    81,    61,  -486,
     159,   159,   195,  -486,  -486,  -486,   186,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,   163,
    -486,  -486,   166,  -486,  -486,  -486,   159,   159,   159,   159,
    -486,   108,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,   146,   160,   167,
     172,   245,   244,  -486,   253,  -486,   177,   183,   257,   275,
     276,   192,   277,   193,   278,   198,   281,   200,   283,   203,
     284,   289,  -486,  -486,   206,  -486,   290,   292,   293,   210,
     294,   296,   298,   297,   214,   216,   218,   219,   220,   221,
     222,   308,   309,   310,   311,   312,    16,   229,   230,   231,
     317,   318,   194,  -486,   259,     4,  -486,  -486,   250,  -486,
     194,  -486,   213,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,   257,   205,   321,   257,   257,   257,   194,
     285,   211,   213,    15,  -486,   286,   301,  -486,  -486,  -486,
     314,  -486,  -486,   257,   313,   326,   302,   194,   261,   194,
     271,   166,  -486,  -486,  -486,  -486,  -486,   328,   108,  -486,
    -486,  -486,  -486,  -486,   251,   336,   232,  -486,  -486,   252,
     339,   335,  -486,   256,  -486,   258,  -486,   260,  -486,   262,
    -486,   263,   232,  -486,   194,   194,   257,  -486,   264,   257,
     257,   265,  -486,  -486,  -486,  -486,  -486,  -486,  -486,   194,
     194,   194,   194,   194,   194,  -486,  -486,  -486,  -486,   194,
     257,   342,   194,  -486,   259,  -486,  -486,   344,   346,   266,
    -486,   267,   268,   269,   194,   270,   272,   279,   280,   257,
     322,  -486,   194,   282,  -486,  -486,  -486,  -486,  -486,   305,
     362,   338,   -52,   363,   257,  -486,   257,   367,   340,   287,
     194,   304,   288,   360,  -486,  -486,   291,  -486,  -486,   369,
     374,  -486,   377,   378,  -486,  -486,  -486,  -486,  -486,   379,
     380,   299,   381,   300,   303,  -486,   306,    17,  -486,   382,
     383,   386,   387,   389,    19,   307,   390,   315,   194,   316,
    -486,   257,   257,  -486,  -486,  -486,  -486,   319,  -486,  -486,
    -486,  -486,   320,   257,   353,  -486,   394,   257,   213,  -486,
     257,   343,  -486,   391,   398,   373,   257,   323,   282,   324,
     399,   325,   257,   403,   375,  -486,   329,   194,   345,  -486,
     404,  -486,   409,   232,   257,   257,   232,   402,  -486,   406,
    -486,  -486,  -486,   257,  -486,   257,   257,   257,   257,   257,
     194,  -486,  -486,   257,  -486,   416,  -486,   299,   300,  -486,
    -486,   332,   257,   384,  -486,   194,   333,  -486,   334,   257,
     106,  -486,   337,   257,   421,   286,   341,   257,   211,   323,
    -486,   347,  -486,   348,   257,   423,   392,  -486,   349,   194,
     359,   351,   431,   437,   354,   355,   438,   356,    20,   442,
     358,   361,   364,   365,   366,    34,   444,   176,  -486,   368,
     257,   434,  -486,   447,  -486,  -486,   370,  -486,   106,  -486,
     371,   257,  -486,  -486,   372,   213,   376,  -486,  -486,   385,
     257,   448,   419,  -486,   388,   194,   393,  -486,   455,   232,
    -486,  -486,   232,  -486,   194,  -486,   257,  -486,  -486,  -486,
    -486,  -486,   194,  -486,   257,   458,   460,   461,  -486,   395,
     257,   286,   194,  -486,  -486,   396,  -486,  -486,   232,   397,
    -486,   400,   257,   462,   430,  -486,   401,   194,   405,    76,
      79,   465,   407,   467,    35,   468,   194,   194,   194,  -486,
     408,   426,   471,  -486,   410,   257,   434,  -486,   411,   257,
     472,   439,  -486,   412,   194,   414,   413,    80,     7,   415,
      82,    51,   232,  -486,   257,   194,  -486,   257,   475,   478,
     479,  -486,   257,   440,  -486,   194,  -486,   417,   436,  -486,
     418,   257,   483,  -486,  -486,   422,   194,  -486,  -486,   424,
     486,   425,   487,  -486,   427,   488,   428,   491,   499,   501,
     432,   504,   153,   154,   239,   506,   257,   463,  -486,   433,
    -486,   257,   464,  -486,   435,   257,  -486,   443,  -486,   445,
    -486,   446,  -486,   449,  -486,   450,   232,   257,  -486,   257,
     515,   516,   519,   521,   523,   524,   257,   525,   141,   314,
    -486,  -486,   451,   257,   485,  -486,   452,  -486,  -486,  -486,
    -486,  -486,   527,   538,   539,   541,   537,   543,   540,   544,
     542,   545,   257,  -486,   466,   436,  -486,   469,   257,   500,
    -486,   232,   257,   257,   470,   474,   476,   477,   480,   481,
     257,   548,  -486,   464,  -486,  -486,   482,   257,   286,   550,
     552,   553,  -486,  -486,  -486,  -486,  -486,  -486,   560,   257,
     485,  -486,  -486,   484,   305,   232,   257,   257,   257,   563,
     500,  -486,  -486,   343,   564,   568,   570,   490,   257,   522,
    -486,   494,   232,   257,   257,  -486,   492,   257,   305,  -486,
     257,   285,   573,   576,    44,  -486,   493,   343,   495,   322,
     232,   257,   257,  -486,  -486,   517,  -486,   384,   579,   582,
     583,   257,   510,  -486,   353,   232,   257,   257,   586,   257,
     494,  -486,   512,   522,   588,   589,   505,   257,   591,   211,
    -486,   257,   520,   520,   232,   257,  -486,   508,   257,   282,
     594,   194,   526,   426,   596,   597,  -486,   598,   533,   257,
     530,   257,  -486,   440,   232,   257,   257,   194,   213,   533,
    -486,   604,  -486,   532,   526,   605,   607,    45,    46,  -486,
    -486,   257,  -486,   510,   232,   257,   257,  -486,   194,  -486,
      47,   512,   608,   626,   546,    49,   257,  -486,   535,   232,
     257,  -486,   194,  -486,   549,   257,   536,   628,   630,    50,
    -486,   551,   257,   547,   232,   257,   194,  -486,  -486,   554,
     257,   555,   557,   633,    55,  -486,   558,   257,   211,  -486,
     257,   194,  -486,  -486,   559,   531,   638,    56,  -486,   194,
     533,  -486,   257,   194,  -486,   640,   213,   646,    59,   194,
    -486,   257,   194,  -486,   647,   648,   649,   194,   257,   194,
     651,   652,    60,   194,   257,   194,  -486,   653,   654,   655,
     194,   257,   194,   656,   657,   658,   194,   257,   194,   659,
     660,    62,   194,   257,   194,  -486,   662,   663,    71,   194,
     257,   194,  -486,   664,   580,    74,   194,  -486,   194,  -486,
     666,   667,   194,   194,    75,   668,   194,  -486,   194,   669,
     670,   194,   194,   587,    78,  -486,   194,  -486,   671,   194,
     673,   194,   674,   194,   675,   194,   676,   194,   677,   194,
     678,   194,   679,   194,   599,  -486
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     3,     7,     0,     0,     0,     1,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    12,    11,    13,    10,    24,    17,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   111,
     108,    85,   159,   159,   102,   101,   103,   105,   106,    64,
       0,     0,     0,    68,    69,    70,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   170,     0,
     172,    88,   115,    89,   195,   197,     0,     0,     0,     0,
      96,     0,   190,   192,   191,   187,   185,   186,   199,   104,
     100,   201,     8,     6,   366,   367,   365,     0,     0,     0,
       0,     0,     0,   364,     0,   363,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   362,   360,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,   113,   112,   174,   169,     0,   171,
       0,    98,   160,   183,   189,   188,    99,   194,   193,   196,
     198,   200,   202,     0,     0,     0,     0,     0,     0,     0,
     137,   161,   159,   107,   120,   145,     0,   165,   166,   146,
       0,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,   116,   178,    92,    93,    94,    95,     0,    97,   181,
     208,   209,   210,   259,     0,     0,     0,   226,   227,     0,
       0,     0,   261,     0,   263,     0,   265,     0,   267,     0,
     269,     0,     0,   271,     0,     0,     0,   299,     0,     0,
       0,     0,   324,   325,   326,   327,   340,   342,   341,     0,
       0,     0,     0,     0,     0,   337,   344,   343,   345,     0,
       0,     0,     0,    84,   114,   176,   173,     0,     0,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   138,     0,   155,   162,    61,    62,   167,   168,   131,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    86,   177,     0,   182,   214,     0,
       0,   232,     0,     0,   260,   262,   264,   266,   268,     0,
       0,   363,     0,   363,     0,   298,     0,     0,   350,     0,
       0,     0,     0,     0,     0,     0,   363,     0,     0,     0,
     175,     0,     0,   339,   207,   211,   212,     0,   241,   242,
     247,   315,     0,     0,   141,   140,     0,     0,   159,   156,
       0,   133,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,   279,
       0,   338,     0,     0,     0,     0,     0,     0,   274,     0,
     273,   278,   300,     0,   302,     0,     0,     0,     0,     0,
       0,   336,   346,     0,   349,     0,   272,     0,     0,   228,
     243,     0,     0,   143,   142,     0,     0,    60,     0,     0,
     109,   134,     0,     0,     0,   145,     0,     0,   161,     0,
     213,     0,   233,     0,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,   144,     0,   297,   257,     0,    63,   110,   229,
       0,     0,    71,   316,     0,   159,     0,   215,   234,     0,
       0,     0,     0,   284,     0,     0,     0,   280,     0,     0,
     204,   205,     0,   276,     0,   275,     0,   328,   329,   330,
     331,   332,     0,   335,     0,     0,     0,     0,   245,     0,
       0,   145,     0,   258,   230,     0,   317,    91,     0,     0,
     235,     0,     0,     0,     0,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
       0,   147,     0,   231,     0,     0,     0,   236,     0,     0,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,   334,     0,     0,     0,
       0,   206,     0,   149,   148,     0,   318,     0,     0,   237,
       0,     0,     0,    72,   287,     0,     0,    87,   217,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   150,     0,
     319,     0,     0,   238,     0,     0,   288,     0,   221,     0,
     219,     0,   220,     0,   218,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     118,   351,     0,     0,     0,   239,     0,   290,   225,   223,
     224,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,   121,   252,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,   123,   122,   253,     0,     0,     0,     0,
       0,     0,   354,   357,   356,   359,   355,   358,     0,     0,
     125,   124,   254,     0,     0,     0,     0,     0,     0,     0,
     127,   126,   255,     0,     0,     0,     0,     0,     0,   129,
     128,     0,     0,     0,     0,   248,     0,     0,   131,   130,
       0,     0,     0,     0,     0,   249,     0,   133,     0,     0,
       0,     0,     0,   348,   256,   135,   296,     0,     0,     0,
       0,     0,   151,   136,     0,     0,     0,     0,     0,     0,
     153,   152,     0,     0,     0,     0,     0,     0,     0,   161,
     154,     0,     0,     0,     0,     0,   347,     0,     0,   155,
       0,     0,     0,     0,     0,     0,   281,     0,   157,     0,
       0,     0,   203,     0,     0,     0,     0,     0,   159,   158,
     179,     0,   289,     0,     0,     0,     0,     0,     0,    58,
     180,     0,   295,     0,     0,     0,     0,   291,     0,   303,
       0,     0,     0,     0,     0,     0,     0,   293,     0,     0,
       0,   292,     0,   310,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,   305,   320,     0,
       0,     0,     0,     0,     0,   321,     0,     0,   161,   270,
       0,     0,   304,   322,     0,   163,     0,     0,   323,     0,
     157,   164,     0,     0,   306,     0,   159,     0,     0,     0,
      90,     0,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   312,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,   301,     0,   308,
       0,     0,     0,     0,     0,     0,     0,   352,     0,     0,
       0,     0,     0,     0,     0,   353,     0,   311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,   -15,  -486,  -486,  -486,  -486,  -486,  -103,  -111,  -486,
    -486,  -486,  -486,  -486,  -235,  -486,  -486,  -486,  -486,  -152,
    -241,  -101,  -485,  -486,  -486,  -486,   217,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
     -93,    84,   441,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,   453,   456,   -99,  -106,
    -120,  -112,   -50,  -143,  -151,  -486,   -24,   -40,   -56,   -65,
    -117,   -57,   -63,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,   611,   -86,   420,   -97,  -486,  -486,
     454,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,  -486,
    -125,  -486,  -161,  -168,  -150,  -104,  -330,  -486,   613,   614,
    -141,  -486,  -486,   233,  -486,  -486,  -486,  -486,  -486,  -486,
    -486,  -486,  -486,  -486,  -486,  -486,   457,   498,  -486,   618,
     620,   622,  -486,   624,   621,  -486,  -486,  -486,  -486,   623,
     -36,    87,   595
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   240,    99,   527,   214,   323,   260,
     699,   241,   743,   760,   770,   779,   788,   421,   480,   812,
     340,   414,   473,   521,   242,   633,   667,   820,   829,   418,
     858,   221,   343,   930,   243,   100,   101,   215,   324,   261,
     859,   268,   222,   102,   103,   104,   105,   106,   107,   821,
     108,   571,   244,   109,   110,   111,   245,   254,   112,   355,
     113,   114,   115,   246,   351,   425,   485,   116,   256,   358,
     434,   496,   542,   584,   611,   643,   247,   248,   341,   415,
     474,   522,   249,   634,   668,   700,   672,   704,   729,   748,
     789,   422,   481,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   325,   130,   131,   132,
     262,   364,   813,   258,   361,   438,   500,   546,   588,   615,
     842,   647,   822,   832,   852,   791,   419,   133,   134,   135,
     860,   250,   428,   488,   579,   606,   896,   903,   911,   918,
     136,   137,   138,   139,   140,   141,   269,   223,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   344,   931,   151,
     184,   185,   165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     199,   200,   226,   535,   219,   205,   206,   207,   208,   209,
     349,     1,     7,   216,   651,  -159,  -159,   251,   252,   160,
     314,   453,   427,   460,   554,    36,    37,     8,     9,    10,
     417,     6,    11,   220,    12,    13,    14,    15,   562,   625,
     426,   168,    16,   263,   264,   265,   266,   166,   802,   876,
     878,   886,    17,   892,   906,   236,   237,   212,   656,   921,
     933,   -59,   -59,   942,   955,   167,   974,    24,    18,    19,
      20,    21,    22,    23,    24,   981,    25,    26,   988,   996,
     233,   234,  1006,   616,   152,   153,   619,   649,   235,   654,
      -2,   213,   198,    27,    28,    29,   652,     2,   489,   169,
     164,   236,   237,    30,   170,   315,   454,   238,   461,   555,
     181,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   563,   626,    43,    44,    45,   220,   326,
      46,    47,    48,   803,   877,   879,   887,   188,   893,   907,
     657,   345,   346,  -119,   922,   934,   201,   202,   943,   956,
     203,   975,   239,   154,   155,   156,   690,   692,   211,    23,
     982,   691,   693,   989,   997,   617,   618,  1007,   620,   621,
     650,   218,   655,    29,  -119,   171,   321,    28,  -119,   565,
     154,   155,   156,   182,   329,   162,   183,   163,   154,   155,
     156,    46,   173,   163,   154,   155,   156,   154,   155,   156,
      17,   182,    48,   338,   183,   163,   154,   155,   156,   204,
     332,   333,   183,   163,   154,   155,   156,   253,   255,   175,
     267,   359,   177,   362,   154,   155,   156,   154,   155,   156,
     723,   179,   257,   259,   189,   270,   154,   155,   156,   154,
     155,   156,   694,   163,   154,   155,   156,   695,   275,   271,
     532,   186,   274,   154,   155,   156,   272,   276,   380,   382,
     327,   273,   154,   155,   156,   220,   277,    44,    45,   154,
     155,   156,   278,   389,   390,   391,   392,   393,   394,   280,
     281,   282,   284,   395,   283,   285,   399,   286,   287,   288,
     289,   291,   290,   292,   294,   293,   295,   296,   407,   297,
     299,   298,   300,   302,   301,   303,   416,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   477,   316,   317,
     318,   319,   320,   322,   436,   334,   220,   339,   342,   350,
     356,   360,   238,   233,   354,   357,   601,   363,   366,   369,
     368,   371,   372,   373,   839,   374,   398,   375,   401,   376,
     402,   377,   378,   385,   388,   403,   404,   405,   406,   408,
     420,   409,   465,   370,   417,   413,   423,   424,   410,   411,
     429,   432,   440,   442,   433,   437,   435,   439,   443,   379,
     441,   444,   445,   446,   447,   449,   455,   456,   448,   450,
     457,   458,   451,   459,   463,   452,   462,   472,   475,   479,
     482,   498,   483,   484,   464,   466,   491,   494,   469,   470,
     495,   501,   502,   490,   492,   507,   487,   499,   497,   508,
     517,   518,   524,   525,   515,   531,   529,   540,   541,   520,
     533,   219,   545,   925,   577,   548,   537,   538,   543,   523,
     547,   549,   552,   550,   551,   553,   556,   557,   564,   570,
     558,   572,   582,   559,   560,   561,   583,   568,   589,   573,
     574,   576,   596,   544,   597,   598,   609,   587,   610,   622,
     578,   624,   627,   632,   580,   635,   641,   585,   642,   662,
     614,   566,   663,   664,   599,   603,   671,   675,   666,   607,
     612,   646,   605,   679,   681,   683,   623,   631,   685,   636,
     639,   644,   648,   686,   653,   687,   670,   673,   689,   586,
     696,   676,   698,   678,   680,   703,   682,   684,   592,   715,
     716,   688,   701,   717,   705,   718,   594,   719,   720,   722,
     503,   731,   707,   506,   708,   709,   602,   728,   710,   711,
     726,   730,   732,   733,   734,   735,   736,   738,   737,   740,
     739,   613,   759,   747,   765,   742,   766,   767,   745,   752,
     628,   629,   630,   753,   768,   754,   755,   778,   782,   756,
     757,   762,   783,   772,   784,   790,   787,   800,   645,   785,
     801,   795,   804,   815,   806,   811,   816,   817,   819,   660,
     827,   831,   834,   835,   836,   838,   841,   846,   849,   669,
     854,   855,   856,   157,   158,   159,   851,   161,   871,   874,
     677,   875,   889,   172,   174,   176,   178,   180,   857,   862,
     187,   872,   190,   191,   192,   193,   194,   195,   196,   197,
     890,   895,   904,   902,   905,   891,   590,   920,   900,   591,
     908,   210,   932,   915,   939,   910,   919,   923,   928,   929,
     941,   947,   948,   949,   917,   953,   954,   960,   961,   962,
     966,   967,   968,   972,   973,   604,   979,   980,   986,   987,
     992,   993,   998,  1001,  1002,  1009,  1005,  1011,  1013,  1015,
    1017,  1019,  1021,  1023,   725,   797,   805,   848,  1025,   936,
     638,   352,   799,   807,   823,   814,   347,   528,   764,   348,
     853,   744,   864,   761,   771,   780,   833,   773,   843,   658,
     781,   217,   881,   888,   873,   365,   830,   229,   870,   230,
     330,   227,   536,   228,   224,   367,   225,   231,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   869,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   850,     0,     0,     0,     0,
       0,     0,     0,   328,     0,     0,     0,     0,   749,     0,
       0,   868,     0,     0,     0,     0,     0,     0,   331,     0,
       0,   335,   336,   337,     0,   940,     0,     0,     0,     0,
       0,     0,   885,     0,     0,     0,     0,     0,   353,     0,
       0,     0,   774,     0,     0,     0,   899,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   792,
     914,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   927,     0,   808,     0,   381,
     383,   384,     0,   935,   386,   387,     0,   938,     0,     0,
       0,     0,   824,   944,     0,     0,   946,     0,     0,     0,
       0,   950,     0,   952,   396,   397,     0,   957,     0,   959,
       0,   844,     0,     0,   963,     0,   965,     0,     0,     0,
     969,     0,   971,     0,   412,     0,   976,     0,   978,     0,
       0,   865,     0,   983,     0,   985,     0,     0,     0,   430,
     990,   431,   991,     0,     0,     0,   994,   995,     0,     0,
     999,   882,  1000,     0,     0,  1003,  1004,     0,     0,     0,
    1008,     0,     0,  1010,     0,  1012,   897,  1014,     0,  1016,
       0,  1018,     0,  1020,     0,  1022,     0,  1024,     0,     0,
       0,   912,     0,     0,     0,     0,   467,   468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,     0,   476,     0,     0,   478,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
     505,     0,     0,     0,     0,     0,     0,     0,   509,     0,
     510,   511,   512,   513,   514,     0,     0,     0,   516,     0,
       0,     0,     0,     0,     0,     0,     0,   519,     0,     0,
       0,     0,     0,     0,   526,     0,     0,     0,   530,     0,
       0,     0,   534,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   567,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,     0,     0,     0,
       0,     0,     0,     0,     0,   581,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   608,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,     0,     0,     0,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   659,
       0,     0,   661,     0,     0,     0,     0,   665,     0,     0,
       0,     0,     0,     0,     0,     0,   674,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   697,     0,     0,     0,     0,   702,     0,     0,     0,
     706,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   713,     0,   714,     0,     0,     0,     0,     0,
       0,   721,     0,   724,     0,     0,     0,     0,   727,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   741,     0,     0,
       0,     0,     0,   746,     0,     0,     0,   750,   751,     0,
       0,     0,     0,     0,     0,   758,     0,     0,     0,     0,
       0,     0,   763,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   769,     0,     0,     0,     0,     0,
       0,   775,   776,   777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   786,     0,     0,     0,     0,   793,   794,
       0,     0,   796,     0,     0,   798,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   809,   810,     0,     0,
       0,     0,     0,     0,     0,     0,   818,     0,     0,     0,
       0,   825,   826,     0,   828,     0,     0,     0,     0,     0,
       0,     0,   837,     0,     0,     0,   840,     0,     0,     0,
     845,     0,     0,   847,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   861,     0,   863,     0,     0,     0,
     866,   867,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   880,     0,     0,     0,
     883,   884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   894,     0,     0,     0,   898,     0,     0,     0,     0,
     901,     0,     0,     0,     0,     0,     0,   909,     0,     0,
     913,     0,     0,     0,     0,   916,     0,     0,     0,     0,
       0,     0,   924,     0,     0,   926,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   937,     0,     0,
       0,     0,     0,     0,     0,     0,   945,     0,     0,     0,
       0,     0,     0,   951,     0,     0,     0,     0,     0,   958,
       0,     0,     0,     0,     0,     0,   964,     0,     0,     0,
       0,     0,   970,     0,     0,     0,     0,     0,   977,     0,
       0,     0,     0,     0,     0,   984
};

static const yytype_int16 yycheck[] =
{
      36,    37,   103,   488,   101,    41,    42,    43,    44,    45,
     245,     1,     1,    99,     7,     0,     1,   110,   111,     7,
       4,     4,   352,     4,     4,   105,   106,    16,    17,    18,
      82,     0,    21,   113,    23,    24,    25,    26,     4,     4,
      92,     4,    31,   136,   137,   138,   139,     7,     4,     4,
       4,     4,    41,     4,     4,    40,    41,     4,     7,     4,
       4,     0,     1,     4,     4,     7,     4,    63,    57,    58,
      59,    60,    61,    62,    63,     4,    65,    66,     4,     4,
      19,    20,     4,     7,    87,    88,     7,     7,    27,     7,
       0,     1,     7,    82,    83,    84,    89,    87,   428,     3,
      13,    40,    41,    92,     8,    89,    89,    46,    89,    89,
      23,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    89,    89,   114,   115,   116,   113,   215,
     119,   120,   121,    89,    89,    89,    89,    12,    89,    89,
      89,   242,   243,    82,    89,    89,     7,     7,    89,    89,
       7,    89,    91,    12,    13,    14,     3,     3,     7,    62,
      89,     8,     8,    89,    89,    89,    90,    89,    89,    90,
      90,    65,    90,    84,   113,     7,   212,    83,   117,     3,
      12,    13,    14,     7,   220,     3,    10,    11,    12,    13,
      14,   119,     7,    11,    12,    13,    14,    12,    13,    14,
      41,     7,   121,   239,    10,    11,    12,    13,    14,     7,
       5,     6,    10,    11,    12,    13,    14,    22,    32,     7,
     112,   257,     7,   259,    12,    13,    14,    12,    13,    14,
      89,     7,    69,    67,     7,    89,    12,    13,    14,    12,
      13,    14,     3,    11,    12,    13,    14,     8,     4,    89,
     485,    10,     7,    12,    13,    14,    89,     4,   294,   295,
      10,    89,    12,    13,    14,   113,    89,   115,   116,    12,
      13,    14,    89,   309,   310,   311,   312,   313,   314,     4,
       4,    89,    89,   319,     7,     7,   322,    89,     7,    89,
       7,     7,    89,     4,     4,    89,     4,     4,   334,    89,
       4,     7,     4,    89,     7,    89,   342,    89,    89,    89,
      89,    89,     4,     4,     4,     4,     4,   418,    89,    89,
      89,     4,     4,    64,   360,     4,   113,    42,   117,    28,
       4,    70,    46,    19,    21,    33,   571,    66,    10,     3,
      89,    89,     3,     8,   829,    89,     4,    89,     4,    89,
       4,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      55,    89,   398,   276,    82,    43,     4,    29,    89,    89,
       7,     4,    12,     4,    34,    71,    89,    89,     4,   292,
      89,     4,     4,     4,     4,     4,     4,     4,    89,    89,
       4,     4,    89,     4,     4,    89,    89,    44,     4,    56,
       9,   437,     4,    30,    89,    89,     7,     4,    89,    89,
      35,     7,     3,    89,    89,    13,    93,    72,    89,    13,
       4,    89,    89,    89,   460,     4,    89,     4,    36,    45,
      89,   528,    73,   918,   535,     4,    89,    89,    89,   475,
      89,     4,     4,    89,    89,    89,     4,    89,     4,    15,
      89,     4,     4,    89,    89,    89,    37,    89,     3,    89,
      89,    89,     4,   499,     4,     4,     4,    74,    38,     4,
      94,     4,     4,    47,    89,     4,     4,    89,    39,     4,
      75,   517,     4,     4,    89,    89,    50,     4,    48,    89,
      89,    77,    95,     7,     7,     7,    89,    89,     7,    89,
      89,    89,    89,     4,    89,     4,    89,    89,     4,   545,
       4,    89,    49,    89,    89,    51,    89,    89,   554,     4,
       4,    89,    89,     4,    89,     4,   562,     4,     4,     4,
     443,     4,    89,   446,    89,    89,   572,    52,    89,    89,
      89,    89,     4,     4,     3,     8,     3,     3,     8,     4,
       8,   587,     4,    53,     4,    89,     4,     4,    89,    89,
     596,   597,   598,    89,     4,    89,    89,     4,     4,    89,
      89,    89,     4,    89,     4,    81,    54,     4,   614,    89,
       4,    89,    89,     4,    89,    68,     4,     4,    78,   625,
       4,    79,     4,     4,    89,     4,    76,    89,     4,   635,
       4,     4,     4,     8,     9,    10,    80,    12,     4,     4,
     646,     4,     4,    18,    19,    20,    21,    22,    85,    89,
      25,    89,    27,    28,    29,    30,    31,    32,    33,    34,
       4,    96,     4,    97,     4,    89,   549,     4,    89,   552,
      89,    46,     4,    89,     4,    98,    89,    89,    89,   118,
       4,     4,     4,     4,    99,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   578,     4,     4,     4,    89,
       4,     4,     4,     4,     4,     4,    89,     4,     4,     4,
       4,     4,     4,     4,   699,   788,   797,   839,    89,   930,
     606,   250,   791,   799,   814,   807,   243,   480,   748,   243,
     843,   725,   853,   743,   760,   770,   823,   764,   833,   622,
     773,   100,   873,   881,   864,   261,   820,   104,   859,   105,
     222,   103,   489,   103,   102,   268,   102,   106,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   686,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   841,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,   731,    -1,
      -1,   857,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,
      -1,   236,   237,   238,    -1,   936,    -1,    -1,    -1,    -1,
      -1,    -1,   878,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,   765,    -1,    -1,    -1,   892,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   782,
     906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   921,    -1,   800,    -1,   294,
     295,   296,    -1,   929,   299,   300,    -1,   933,    -1,    -1,
      -1,    -1,   815,   939,    -1,    -1,   942,    -1,    -1,    -1,
      -1,   947,    -1,   949,   319,   320,    -1,   953,    -1,   955,
      -1,   834,    -1,    -1,   960,    -1,   962,    -1,    -1,    -1,
     966,    -1,   968,    -1,   339,    -1,   972,    -1,   974,    -1,
      -1,   854,    -1,   979,    -1,   981,    -1,    -1,    -1,   354,
     986,   356,   988,    -1,    -1,    -1,   992,   993,    -1,    -1,
     996,   874,   998,    -1,    -1,  1001,  1002,    -1,    -1,    -1,
    1006,    -1,    -1,  1009,    -1,  1011,   889,  1013,    -1,  1015,
      -1,  1017,    -1,  1019,    -1,  1021,    -1,  1023,    -1,    -1,
      -1,   904,    -1,    -1,    -1,    -1,   401,   402,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,
      -1,    -1,   417,    -1,    -1,   420,    -1,    -1,    -1,    -1,
      -1,   426,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,
     455,   456,   457,   458,   459,    -1,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,   483,    -1,
      -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   517,    -1,    -1,   520,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
      -1,    -1,    -1,    -1,    -1,   570,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     605,    -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,   627,    -1,    -1,    -1,    -1,   632,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   666,    -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,
     675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   687,    -1,   689,    -1,    -1,    -1,    -1,    -1,
      -1,   696,    -1,   698,    -1,    -1,    -1,    -1,   703,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   722,    -1,    -1,
      -1,    -1,    -1,   728,    -1,    -1,    -1,   732,   733,    -1,
      -1,    -1,    -1,    -1,    -1,   740,    -1,    -1,    -1,    -1,
      -1,    -1,   747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,
      -1,   766,   767,   768,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   778,    -1,    -1,    -1,    -1,   783,   784,
      -1,    -1,   787,    -1,    -1,   790,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   801,   802,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   811,    -1,    -1,    -1,
      -1,   816,   817,    -1,   819,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   827,    -1,    -1,    -1,   831,    -1,    -1,    -1,
     835,    -1,    -1,   838,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   849,    -1,   851,    -1,    -1,    -1,
     855,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   871,    -1,    -1,    -1,
     875,   876,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   886,    -1,    -1,    -1,   890,    -1,    -1,    -1,    -1,
     895,    -1,    -1,    -1,    -1,    -1,    -1,   902,    -1,    -1,
     905,    -1,    -1,    -1,    -1,   910,    -1,    -1,    -1,    -1,
      -1,    -1,   917,    -1,    -1,   920,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   932,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   941,    -1,    -1,    -1,
      -1,    -1,    -1,   948,    -1,    -1,    -1,    -1,    -1,   954,
      -1,    -1,    -1,    -1,    -1,    -1,   961,    -1,    -1,    -1,
      -1,    -1,   967,    -1,    -1,    -1,    -1,    -1,   973,    -1,
      -1,    -1,    -1,    -1,    -1,   980
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    87,   123,   124,   125,     0,     1,    16,    17,
      18,    21,    23,    24,    25,    26,    31,    41,    57,    58,
      59,    60,    61,    62,    63,    65,    66,    82,    83,    84,
      92,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   114,   115,   116,   119,   120,   121,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   177,
     207,   208,   215,   216,   217,   218,   219,   220,   222,   225,
     226,   227,   230,   232,   233,   234,   239,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     279,   280,   281,   299,   300,   301,   312,   313,   314,   315,
     316,   317,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   331,    87,    88,    12,    13,    14,   334,   334,   334,
       7,   334,     3,    11,   333,   334,     7,     7,     4,     3,
       8,     7,   334,     7,   334,     7,   334,     7,   334,     7,
     334,   333,     7,    10,   332,   333,    10,   334,    12,     7,
     334,   334,   334,   334,   334,   334,   334,   334,     7,   332,
     332,     7,     7,     7,     7,   332,   332,   332,   332,   332,
     334,     7,     4,     1,   179,   209,   277,   276,    65,   279,
     113,   203,   214,   319,   323,   325,   203,   321,   322,   300,
     301,   326,   331,    19,    20,    27,    40,    41,    46,    91,
     176,   183,   196,   206,   224,   228,   235,   248,   249,   254,
     303,   222,   222,    22,   229,    32,   240,    69,   285,    67,
     181,   211,   282,   222,   222,   222,   222,   112,   213,   318,
      89,    89,    89,    89,     7,     4,     4,    89,    89,   334,
       4,     4,    89,     7,    89,     7,    89,     7,    89,     7,
      89,     7,     4,    89,     4,     4,     4,    89,     7,     4,
       4,     7,    89,    89,    89,    89,    89,    89,    89,     4,
       4,     4,     4,     4,     4,    89,    89,    89,    89,     4,
       4,   332,    64,   180,   210,   278,   277,    10,   334,   332,
     319,   334,     5,     6,     4,   334,   334,   334,   332,    42,
     192,   250,   117,   204,   329,   203,   203,   248,   249,   196,
      28,   236,   224,   334,    21,   231,     4,    33,   241,   332,
      70,   286,   332,    66,   283,   282,    10,   318,    89,     3,
     333,    89,     3,     8,    89,    89,    89,    89,    89,   333,
     332,   334,   332,   334,   334,    89,   334,   334,    89,   332,
     332,   332,   332,   332,   332,   332,   334,   334,     4,   332,
     278,     4,     4,    89,    89,    89,    89,   332,    89,    89,
      89,    89,   334,    43,   193,   251,   332,    82,   201,   298,
      55,   189,   263,     4,    29,   237,    92,   298,   304,     7,
     334,   334,     4,    34,   242,    89,   332,    71,   287,    89,
      12,    89,     4,     4,     4,     4,     4,     4,    89,     4,
      89,    89,    89,     4,    89,     4,     4,     4,     4,     4,
       4,    89,    89,     4,    89,   332,    89,   334,   334,    89,
      89,   334,    44,   194,   252,     4,   334,   203,   334,    56,
     190,   264,     9,     4,    30,   238,   334,    93,   305,   298,
      89,     7,    89,   334,     4,    35,   243,    89,   332,    72,
     288,     7,     3,   333,   334,   334,   333,    13,    13,   334,
     334,   334,   334,   334,   334,   332,   334,     4,    89,   334,
      45,   195,   253,   332,    89,    89,   334,   178,   208,    89,
     334,     4,   196,    89,   334,   204,   305,    89,    89,   334,
       4,    36,   244,    89,   332,    73,   289,    89,     4,     4,
      89,    89,     4,    89,     4,    89,     4,    89,    89,    89,
      89,    89,     4,    89,     4,     3,   332,   334,    89,   334,
      15,   223,     4,    89,    89,   334,    89,   203,    94,   306,
      89,   334,     4,    37,   245,    89,   332,    74,   290,     3,
     333,   333,   332,   334,   332,   334,     4,     4,     4,    89,
     334,   196,   332,    89,   333,    95,   307,    89,   334,     4,
      38,   246,    89,   332,    75,   291,     7,    89,    90,     7,
      89,    90,     4,    89,     4,     4,    89,     4,   332,   332,
     332,    89,    47,   197,   255,     4,    89,   334,   223,    89,
     334,     4,    39,   247,    89,   332,    77,   293,    89,     7,
      90,     7,    89,    89,     7,    90,     7,    89,   333,   334,
     332,   334,     4,     4,     4,   334,    48,   198,   256,   332,
      89,    50,   258,    89,   334,     4,    89,   332,    89,     7,
      89,     7,    89,     7,    89,     7,     4,     4,    89,     4,
       3,     8,     3,     8,     3,     8,     4,   334,    49,   182,
     257,    89,   334,    51,   259,    89,   334,    89,    89,    89,
      89,    89,   333,   334,   334,     4,     4,     4,     4,     4,
       4,   334,     4,    89,   334,   183,    89,   334,    52,   260,
      89,     4,     4,     4,     3,     8,     3,     8,     3,     8,
       4,   334,    89,   184,   258,    89,   334,    53,   261,   333,
     334,   334,    89,    89,    89,    89,    89,    89,   334,     4,
     185,   259,    89,   334,   254,     4,     4,     4,     4,   334,
     186,   260,    89,   263,   333,   334,   334,   334,     4,   187,
     261,   264,     4,     4,     4,    89,   334,    54,   188,   262,
      81,   297,   333,   334,   334,    89,   334,   189,   334,   250,
       4,     4,     4,    89,    89,   190,    89,   251,   333,   334,
     334,    68,   191,   284,   253,     4,     4,     4,   334,    78,
     199,   221,   294,   252,   333,   334,   334,     4,   334,   200,
     297,    79,   295,   262,     4,     4,    89,   334,     4,   204,
     334,    76,   292,   292,   333,   334,    89,   334,   201,     4,
     332,    80,   296,   255,     4,     4,     4,    85,   202,   212,
     302,   334,    89,   334,   256,   333,   334,   334,   332,   203,
     302,     4,    89,   296,     4,     4,     4,    89,     4,    89,
     334,   294,   333,   334,   334,   332,     4,    89,   295,     4,
       4,    89,     4,    89,   334,    96,   308,   333,   334,   332,
      89,   334,    97,   309,     4,     4,     4,    89,    89,   334,
      98,   310,   333,   334,   332,    89,   334,    99,   311,    89,
       4,     4,    89,    89,   334,   204,   334,   332,    89,   118,
     205,   330,     4,     4,    89,   332,   202,   334,   332,     4,
     203,     4,     4,    89,   332,   334,   332,     4,     4,     4,
     332,   334,   332,     4,     4,     4,    89,   332,   334,   332,
       4,     4,     4,   332,   334,   332,     4,     4,     4,   332,
     334,   332,     4,     4,     4,    89,   332,   334,   332,     4,
       4,     4,    89,   332,   334,   332,     4,    89,     4,    89,
     332,   332,     4,     4,   332,   332,     4,    89,     4,   332,
     332,     4,     4,   332,   332,    89,     4,    89,   332,     4,
     332,     4,   332,     4,   332,     4,   332,     4,   332,     4,
     332,     4,   332,     4,   332,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   122,   123,   123,   123,   123,   124,   125,   125,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   176,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   188,
     188,   189,   189,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   199,   199,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   206,   206,   207,
     207,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   214,   215,   215,   215,   215,   215,
     216,   216,   216,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   222,   222,   223,   224,   225,   226,
     227,   228,   228,   229,   230,   231,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   279,   280,   280,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   294,   295,   295,   296,   297,   298,   299,   299,
     300,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   316,
     316,   316,   316,   317,   317,   317,   317,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   326,   326,   327,
     328,   329,   330,   330,   331,   331,   331,   331,   331,   331,
     332,   332,   332,   333,   333,   334,   334,   334
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,    26,     1,
       5,     3,     3,     6,     1,     2,     2,     3,     1,     1,
       1,     6,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     9,     1,     1,
      36,     7,     2,     2,     2,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     1,     1,     2,     2,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     4,     7,     7,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,    10,    10,    11,    11,
      11,    11,    12,    12,    12,    12,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     3,     3,     3,     9,     9,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
      33,     3,     3,     5,     5,     7,     7,     9,     5,     3,
       4,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     9,     7,     9,     3,     3,     3,     4,     3,
       5,    51,     5,     3,     9,     7,    11,    25,    27,    53,
       5,    35,    23,    13,    17,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     7,     7,
       7,     7,     7,    11,     9,     7,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,    23,    19,     5,
       4,     9,    21,    25,    14,    14,    14,    14,    14,    14,
       1,     1,     1,     1,     1,     1,     1,     1
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
      int yyn = yypact[+*yyssp];
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
#line 208 "itsh.y"
        {
		_MAIL();
	}
#line 2305 "itsh.tab.c"
    break;

  case 3:
#line 212 "itsh.y"
        {
		_MLTYPE_XXXX(1);
	}
#line 2313 "itsh.tab.c"
    break;

  case 4:
#line 216 "itsh.y"
        {
		_MLTYPE_XXXX(2);
	}
#line 2321 "itsh.tab.c"
    break;

  case 5:
#line 220 "itsh.y"
        {
		_MLTYPE_XXXX(3);
	}
#line 2329 "itsh.tab.c"
    break;

  case 6:
#line 227 "itsh.y"
                                           {
		_MAIL_HEADER();
	}
#line 2337 "itsh.tab.c"
    break;

  case 58:
#line 324 "itsh.y"
        {
		_MLTYPE_DAILY_NIGHT_OPE();
	}
#line 2345 "itsh.tab.c"
    break;

  case 59:
#line 333 "itsh.y"
        {
		_MLTYPE_ONLY_POS();
	}
#line 2353 "itsh.tab.c"
    break;

  case 60:
#line 346 "itsh.y"
        {
		_MLTYPE_DAILY_NIGHT_NON_OPE();
	}
#line 2361 "itsh.tab.c"
    break;

  case 61:
#line 356 "itsh.y"
        {
		_MLTYPE_DAILY_DAYTIME();
	}
#line 2369 "itsh.tab.c"
    break;

  case 62:
#line 367 "itsh.y"
        {
		_MLTYPE_DAILY_NIGHT_EXCEPTION();
	}
#line 2377 "itsh.tab.c"
    break;

  case 63:
#line 381 "itsh.y"
        {
		_MLTYPE_RESPONSE_RT();
	}
#line 2385 "itsh.tab.c"
    break;

  case 64:
#line 389 "itsh.y"
        {
		_MLTYPE_ALARM_SC();
	}
#line 2393 "itsh.tab.c"
    break;

  case 65:
#line 398 "itsh.y"
        {
		_MLTYPE_ALARM_SA();
	}
#line 2401 "itsh.tab.c"
    break;

  case 66:
#line 407 "itsh.y"
        {
		_MLTYPE_ALARM_BT();
	}
#line 2409 "itsh.tab.c"
    break;

  case 67:
#line 418 "itsh.y"
        {
		_MLTYPE_RESPONSE_AM();
	}
#line 2417 "itsh.tab.c"
    break;

  case 68:
#line 426 "itsh.y"
        {
		_MLTYPE_RESPONSE_CL();
	}
#line 2425 "itsh.tab.c"
    break;

  case 69:
#line 434 "itsh.y"
        {
		_MLTYPE_RESPONSE_CM0();
	}
#line 2433 "itsh.tab.c"
    break;

  case 70:
#line 442 "itsh.y"
        {
		_MLTYPE_RESPONSE_CM1();
	}
#line 2441 "itsh.tab.c"
    break;

  case 71:
#line 455 "itsh.y"
        {
		_MLTYPE_RESPONSE_CT0();
	}
#line 2449 "itsh.tab.c"
    break;

  case 72:
#line 471 "itsh.y"
        {
		_MLTYPE_RESPONSE_CT1();
	}
#line 2457 "itsh.tab.c"
    break;

  case 73:
#line 479 "itsh.y"
        {
		_MLTYPE_AMNG();
	}
#line 2465 "itsh.tab.c"
    break;

  case 74:
#line 487 "itsh.y"
        {
		_MLTYPE_HSOK();
	}
#line 2473 "itsh.tab.c"
    break;

  case 75:
#line 495 "itsh.y"
        {
		_MLTYPE_HSNG();
	}
#line 2481 "itsh.tab.c"
    break;

  case 76:
#line 503 "itsh.y"
        {
		_MLTYPE_HEOK();
	}
#line 2489 "itsh.tab.c"
    break;

  case 77:
#line 511 "itsh.y"
        {
		_MLTYPE_HENG();
	}
#line 2497 "itsh.tab.c"
    break;

  case 78:
#line 519 "itsh.y"
        {
		_MLTYPE_HFOK();
	}
#line 2505 "itsh.tab.c"
    break;

  case 79:
#line 527 "itsh.y"
        {
		_MLTYPE_HFNG();
	}
#line 2513 "itsh.tab.c"
    break;

  case 80:
#line 535 "itsh.y"
        {
		_MLTYPE_HHOK();
	}
#line 2521 "itsh.tab.c"
    break;

  case 81:
#line 543 "itsh.y"
        {
		_MLTYPE_HHNG();
	}
#line 2529 "itsh.tab.c"
    break;

  case 82:
#line 551 "itsh.y"
        {
		_MLTYPE_HLOK();
	}
#line 2537 "itsh.tab.c"
    break;

  case 83:
#line 559 "itsh.y"
        {
		_MLTYPE_HLNG();
	}
#line 2545 "itsh.tab.c"
    break;

  case 84:
#line 569 "itsh.y"
        {
		_MLTYPE_RESPONSE_AC();
	}
#line 2553 "itsh.tab.c"
    break;

  case 85:
#line 577 "itsh.y"
        {
		_MLTYPE_XX();
	}
#line 2561 "itsh.tab.c"
    break;

  case 86:
#line 587 "itsh.y"
        {
		_MLTYPE_SD();
	}
#line 2569 "itsh.tab.c"
    break;

  case 87:
#line 602 "itsh.y"
        {
		_MLTYPE_RM();
	}
#line 2577 "itsh.tab.c"
    break;

  case 88:
#line 609 "itsh.y"
        {
		_MLTYPE_XX_V7();
	}
#line 2585 "itsh.tab.c"
    break;

  case 89:
#line 616 "itsh.y"
        {
		_MLTYPE_TD();
	}
#line 2593 "itsh.tab.c"
    break;

  case 90:
#line 659 "itsh.y"
        {
		_MLTYPE_DAILY_OPE();
	}
#line 2601 "itsh.tab.c"
    break;

  case 91:
#line 673 "itsh.y"
        {
		_MLTYPE_DAILY_NOPE();
	}
#line 2609 "itsh.tab.c"
    break;

  case 92:
#line 682 "itsh.y"
        {
		_MLTYPE_ALARM_SS();
	}
#line 2617 "itsh.tab.c"
    break;

  case 93:
#line 691 "itsh.y"
        {
		_MLTYPE_ALARM_SR();
	}
#line 2625 "itsh.tab.c"
    break;

  case 94:
#line 700 "itsh.y"
        {
		_MLTYPE_ALARM_SG();
	}
#line 2633 "itsh.tab.c"
    break;

  case 95:
#line 709 "itsh.y"
        {
		_MLTYPE_ALARM_SU();
	}
#line 2641 "itsh.tab.c"
    break;

  case 96:
#line 717 "itsh.y"
        {
		_MLTYPE_RES_REMOTE_DL();
	}
#line 2649 "itsh.tab.c"
    break;

  case 97:
#line 726 "itsh.y"
        {
		_MLTYPE_ASTRSK();
	}
#line 2657 "itsh.tab.c"
    break;

  case 98:
#line 735 "itsh.y"
        {
		_MLTYPE_FDFR();
	}
#line 2665 "itsh.tab.c"
    break;

  case 99:
#line 745 "itsh.y"
        {
		_MLTYPE_HDHQHP();
	}
#line 2673 "itsh.tab.c"
    break;

  case 100:
#line 753 "itsh.y"
        {
		_MLTYPE_LKOK();
	}
#line 2681 "itsh.tab.c"
    break;

  case 101:
#line 761 "itsh.y"
        {
		_MLTYPE_AR();
	}
#line 2689 "itsh.tab.c"
    break;

  case 102:
#line 770 "itsh.y"
        {
		_MLTYPE_AE();
	}
#line 2697 "itsh.tab.c"
    break;

  case 103:
#line 778 "itsh.y"
        {
		_MLTYPE_RR();
	}
#line 2705 "itsh.tab.c"
    break;

  case 104:
#line 786 "itsh.y"
        {
		_MLTYPE_SSID();
	}
#line 2713 "itsh.tab.c"
    break;

  case 105:
#line 794 "itsh.y"
        {
		_MLTYPE_KL();
	}
#line 2721 "itsh.tab.c"
    break;

  case 204:
#line 1047 "itsh.y"
        {
		_CMD_START("CMD_LINE_POS");
		cmd_pos(cmd_line, (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2732 "itsh.tab.c"
    break;

  case 205:
#line 1055 "itsh.y"
        {
		_CMD_START("CMD_LINE_POS");
		cmd_pos(cmd_line, GPS_ERROR_LATITUDE, GPS_ERROR_LONGITUDE, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2743 "itsh.tab.c"
    break;

  case 206:
#line 1067 "itsh.y"
        {
		_CMD_START("CMD_LINE_HOUR_METER");
		cmd_h(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2754 "itsh.tab.c"
    break;

  case 207:
#line 1079 "itsh.y"
        {
		_CMD_START("CMD_LINE_AREA_NAIGAI_A");
		cmd_a(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2765 "itsh.tab.c"
    break;

  case 208:
#line 1091 "itsh.y"
        {
		_CMD_START("CMD_LINE_ALARM_SC");
		cmd_sc(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2776 "itsh.tab.c"
    break;

  case 209:
#line 1103 "itsh.y"
        {
		_CMD_START("CMD_LINE_ALARM_SA");
		cmd_sa(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2787 "itsh.tab.c"
    break;

  case 210:
#line 1115 "itsh.y"
        {
		_CMD_START("CMD_LINE_ALARM_BT");
		cmd_bt(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2798 "itsh.tab.c"
    break;

  case 211:
#line 1128 "itsh.y"
        {
		_CMD_START("CMD_LINE_EG");
		cmd_eg(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2809 "itsh.tab.c"
    break;

  case 212:
#line 1135 "itsh.y"
        {
		_CMD_START("CMD_LINE_EG");
		cmd_eg(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2820 "itsh.tab.c"
    break;

  case 213:
#line 1147 "itsh.y"
        {
		_CMD_START("CMD_LINE_AM_ON");
		cmd_amon(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2831 "itsh.tab.c"
    break;

  case 214:
#line 1157 "itsh.y"
        {
		_CMD_START("CMD_LINE_AM_OF");
		cmd_amof(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2842 "itsh.tab.c"
    break;

  case 215:
#line 1167 "itsh.y"
        {
		_CMD_START("CMD_LINE_AM");
		cmd_am(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2853 "itsh.tab.c"
    break;

  case 216:
#line 1180 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL");
		cmd_cl(cmd_line, (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2864 "itsh.tab.c"
    break;

  case 217:
#line 1188 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL");
		cmd_cl(cmd_line, (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2875 "itsh.tab.c"
    break;

  case 218:
#line 1196 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(CR)");
		cmd_cl(cmd_line, (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2886 "itsh.tab.c"
    break;

  case 219:
#line 1204 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(CR)");
		cmd_cl(cmd_line, (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2897 "itsh.tab.c"
    break;

  case 220:
#line 1212 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(LF)");
		cmd_cl(cmd_line, (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2908 "itsh.tab.c"
    break;

  case 221:
#line 1220 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(LF)");
		cmd_cl(cmd_line, (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2919 "itsh.tab.c"
    break;

  case 222:
#line 1228 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(CRLF)");
		cmd_cl(cmd_line, (yyvsp[-10].strval), (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2930 "itsh.tab.c"
    break;

  case 223:
#line 1236 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(CRLF)");
		cmd_cl(cmd_line, (yyvsp[-10].strval), (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2941 "itsh.tab.c"
    break;

  case 224:
#line 1244 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(LFCR)");
		cmd_cl(cmd_line, (yyvsp[-10].strval), (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2952 "itsh.tab.c"
    break;

  case 225:
#line 1252 "itsh.y"
        {
		_CMD_START("CMD_LINE_CL(LFCR)");
		cmd_cl(cmd_line, (yyvsp[-10].strval), (yyvsp[-8].strval), (yyvsp[-6].strval), (yyvsp[-4].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2963 "itsh.tab.c"
    break;

  case 226:
#line 1264 "itsh.y"
        {
		_CMD_START("CMD_LINE_CM0");
		cmd_cm0(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2974 "itsh.tab.c"
    break;

  case 227:
#line 1276 "itsh.y"
        {
		_CMD_START("CMD_LINE_CM1");
		cmd_cm1(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2985 "itsh.tab.c"
    break;

  case 228:
#line 1288 "itsh.y"
        {
		_CMD_START("CMD_LINE_D0");
		cmd_d0(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 2996 "itsh.tab.c"
    break;

  case 229:
#line 1300 "itsh.y"
        {
		_CMD_START("CMD_LINE_D1");
		cmd_d1(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3007 "itsh.tab.c"
    break;

  case 230:
#line 1312 "itsh.y"
        {
		_CMD_START("CMD_LINE_D2");
		cmd_d2(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3018 "itsh.tab.c"
    break;

  case 231:
#line 1324 "itsh.y"
        {
		_CMD_START("CMD_LINE_D3");
		cmd_d3(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3029 "itsh.tab.c"
    break;

  case 232:
#line 1336 "itsh.y"
        {
		_CMD_START("CMD_LINE_M0");
		cmd_m0(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3040 "itsh.tab.c"
    break;

  case 233:
#line 1348 "itsh.y"
        {
		_CMD_START("CMD_LINE_M1");
		cmd_m1(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3051 "itsh.tab.c"
    break;

  case 234:
#line 1360 "itsh.y"
        {
		_CMD_START("CMD_LINE_M2");
		cmd_m2(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3062 "itsh.tab.c"
    break;

  case 235:
#line 1372 "itsh.y"
        {
		_CMD_START("CMD_LINE_M3");
		cmd_m3(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3073 "itsh.tab.c"
    break;

  case 236:
#line 1384 "itsh.y"
        {
		_CMD_START("CMD_LINE_M4");
		cmd_m4(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3084 "itsh.tab.c"
    break;

  case 237:
#line 1396 "itsh.y"
        {
		_CMD_START("CMD_LINE_M5");
		cmd_m5(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3095 "itsh.tab.c"
    break;

  case 238:
#line 1408 "itsh.y"
        {
		_CMD_START("CMD_LINE_M6");
		cmd_m6(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3106 "itsh.tab.c"
    break;

  case 239:
#line 1420 "itsh.y"
        {
		_CMD_START("CMD_LINE_M7");
		cmd_m7(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3117 "itsh.tab.c"
    break;

  case 240:
#line 1432 "itsh.y"
        {
		_CMD_START("CMD_LINE_M8");
		cmd_m8(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3128 "itsh.tab.c"
    break;

  case 241:
#line 1442 "itsh.y"
        {
		_CMD_START("CMD_LINE_EGN_T");
	
		cmd_t(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3140 "itsh.tab.c"
    break;

  case 242:
#line 1453 "itsh.y"
        {
		_CMD_START("CMD_LINE_EGN_P");
		cmd_p(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3151 "itsh.tab.c"
    break;

  case 243:
#line 1463 "itsh.y"
        {
		_CMD_START("CMD_LINE_IDOL_I");
		cmd_i(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3162 "itsh.tab.c"
    break;

  case 244:
#line 1473 "itsh.y"
        {
		_CMD_START("CMD_LINE_RUN_R");
		cmd_r(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3173 "itsh.tab.c"
    break;

  case 245:
#line 1483 "itsh.y"
        {
		_CMD_START("CMD_LINE_HIREACH_C");
		cmd_c(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3184 "itsh.tab.c"
    break;

  case 246:
#line 1493 "itsh.y"
        {
		_CMD_START("CMD_LINE_NIBURA_N");
		cmd_n(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3195 "itsh.tab.c"
    break;

  case 247:
#line 1503 "itsh.y"
        {
		_CMD_START("CMD_LINE_FUEL_F");
		cmd_f(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3206 "itsh.tab.c"
    break;

  case 248:
#line 1513 "itsh.y"
        {
		_CMD_START("CMD_LINE_ENGN_W");
		cmd_w(cmd_line, (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3217 "itsh.tab.c"
    break;

  case 249:
#line 1523 "itsh.y"
        {
		_CMD_START("CMD_LINE_PUMP_U");
		cmd_u(cmd_line, (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3228 "itsh.tab.c"
    break;

  case 250:
#line 1533 "itsh.y"
        {
	
		_CMD_START("CMD_LINE_KADO_J(No Values)");
		next_cmd();
	}
#line 3238 "itsh.tab.c"
    break;

  case 251:
#line 1539 "itsh.y"
        {
		_CMD_START("CMD_LINE_KADO_J");
		cmd_j(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3249 "itsh.tab.c"
    break;

  case 252:
#line 1549 "itsh.y"
        {
		_CMD_START("CMD_LINE_ENGN_OIL_EC");
		cmd_ec(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3260 "itsh.tab.c"
    break;

  case 253:
#line 1559 "itsh.y"
        {
		_CMD_START("CMD_LINE_FUEL_FILTER_FC");
		cmd_fc(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3271 "itsh.tab.c"
    break;

  case 254:
#line 1569 "itsh.y"
        {
		_CMD_START("CMD_LINE_SADO_FILTER_HC");
		cmd_hc(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3282 "itsh.tab.c"
    break;

  case 255:
#line 1579 "itsh.y"
        {
		_CMD_START("CMD_LINE_SADO_CHANGE_LC");
		cmd_lc(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3293 "itsh.tab.c"
    break;

  case 256:
#line 1589 "itsh.y"
        {
		_CMD_START("CMD_LINE_OVER_OV");
		cmd_ov(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3304 "itsh.tab.c"
    break;

  case 257:
#line 1599 "itsh.y"
        {
		_CMD_START("CMD_LINE_FUEL_ONDO_FT");
		cmd_ft(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3315 "itsh.tab.c"
    break;

  case 258:
#line 1609 "itsh.y"
        {
		_CMD_START("CMD_LINE_FUEL_STATUS_FS");
		cmd_fs(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3326 "itsh.tab.c"
    break;

  case 259:
#line 1619 "itsh.y"
        {
		_CMD_START("CMD_LINE_AMNG");
	
		next_cmd();
	}
#line 3336 "itsh.tab.c"
    break;

  case 260:
#line 1628 "itsh.y"
        {
		_CMD_START("CMD_LINE_HSOK");
		cmd_hs(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3347 "itsh.tab.c"
    break;

  case 261:
#line 1638 "itsh.y"
        {
		_CMD_START("CMD_LINE_HSNG");
		cmd_hs(cmd_line, "", (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3358 "itsh.tab.c"
    break;

  case 262:
#line 1648 "itsh.y"
        {
		_CMD_START("CMD_LINE_HEOK");
		cmd_he(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3369 "itsh.tab.c"
    break;

  case 263:
#line 1658 "itsh.y"
        {
		_CMD_START("CMD_LINE_HENG");
		cmd_he(cmd_line, "", (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3380 "itsh.tab.c"
    break;

  case 264:
#line 1668 "itsh.y"
        {
		_CMD_START("CMD_LINE_HFOK");
		cmd_hf(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3391 "itsh.tab.c"
    break;

  case 265:
#line 1678 "itsh.y"
        {
		_CMD_START("CMD_LINE_HFNG");
		cmd_hf(cmd_line, "", (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3402 "itsh.tab.c"
    break;

  case 266:
#line 1688 "itsh.y"
        {
		_CMD_START("CMD_LINE_HHOK");
		cmd_hh(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3413 "itsh.tab.c"
    break;

  case 267:
#line 1698 "itsh.y"
        {
		_CMD_START("CMD_LINE_HHNG");
		cmd_hh(cmd_line, "", (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3424 "itsh.tab.c"
    break;

  case 268:
#line 1708 "itsh.y"
        {
		_CMD_START("CMD_LINE_HLOK");
		cmd_hl(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3435 "itsh.tab.c"
    break;

  case 269:
#line 1718 "itsh.y"
        {
		_CMD_START("CMD_LINE_HLNG");
		cmd_hl(cmd_line, "", (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3446 "itsh.tab.c"
    break;

  case 270:
#line 1728 "itsh.y"
        {
		_CMD_START("CMD_LINE_AH");
		cmd_ah(cmd_line, (yyvsp[-31].strval), (yyvsp[-29].strval), (yyvsp[-27].strval), (yyvsp[-25].strval), (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3457 "itsh.tab.c"
    break;

  case 271:
#line 1738 "itsh.y"
        {
		_CMD_START("CMD_LINE_PN");
		cmd_pn(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3468 "itsh.tab.c"
    break;

  case 272:
#line 1748 "itsh.y"
        {
		_CMD_START("CMD_LINE_VR");
		cmd_vr(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3479 "itsh.tab.c"
    break;

  case 273:
#line 1758 "itsh.y"
        {
		_CMD_START("CMD_LINE_XX");
		cmd_xx(cmd_line, (yyvsp[-4].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3490 "itsh.tab.c"
    break;

  case 274:
#line 1765 "itsh.y"
        {
		char *_param2 = 0x00;
		
		if((yyvsp[-3].strval)[0]=='*'){
			_param2 = "0";
		}else{
			_param2 = (yyvsp[-3].strval);
		}
		
		_CMD_START("CMD_LINE_XX");
		cmd_xx(cmd_line, (yyvsp[-4].strval), _param2, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3509 "itsh.tab.c"
    break;

  case 275:
#line 1783 "itsh.y"
        {
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7(cmd_line, (yyvsp[-6].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3520 "itsh.tab.c"
    break;

  case 276:
#line 1790 "itsh.y"
        {
		char *_param2 = 0x00;
		
		if((yyvsp[-5].strval)[0]=='*'){
			_param2 = "0";
		}else{
			_param2 = (yyvsp[-5].strval);
		}
		
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7(cmd_line, (yyvsp[-6].strval), _param2, (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3539 "itsh.tab.c"
    break;

  case 277:
#line 1805 "itsh.y"
        {
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7_eg(cmd_line, (yyvsp[-8].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3550 "itsh.tab.c"
    break;

  case 278:
#line 1815 "itsh.y"
        {
		_CMD_START("CMD_LINE_SD_1");
		cmd_sd1(cmd_line, (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3561 "itsh.tab.c"
    break;

  case 279:
#line 1825 "itsh.y"
        {
		_CMD_START("CMD_LINE_SD_2");
		cmd_sd2(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3572 "itsh.tab.c"
    break;

  case 280:
#line 1835 "itsh.y"
        {
		_CMD_START("CMD_LINE_SD_3");
		cmd_sd3(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3583 "itsh.tab.c"
    break;

  case 281:
#line 1845 "itsh.y"
        {
		_CMD_START("CMD_LINE_NENPI");
		cmd_np(cmd_line, (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3594 "itsh.tab.c"
    break;

  case 282:
#line 1856 "itsh.y"
        {
		_CMD_START("CMD_LINE_V");
		cmd_vr(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3605 "itsh.tab.c"
    break;

  case 283:
#line 1866 "itsh.y"
        {
		_CMD_START("CMD_LINE_EA");
		cmd_ea(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3616 "itsh.tab.c"
    break;

  case 284:
#line 1876 "itsh.y"
        {
		_CMD_START("CMD_LINE_PA");
		cmd_pa(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3627 "itsh.tab.c"
    break;

  case 285:
#line 1886 "itsh.y"
        {
		_CMD_START("CMD_LINE_PB");
		cmd_pb(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3638 "itsh.tab.c"
    break;

  case 286:
#line 1896 "itsh.y"
        {
		_CMD_START("CMD_LINE_PC");
		cmd_pc(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3649 "itsh.tab.c"
    break;

  case 287:
#line 1906 "itsh.y"
        {
		_CMD_START("CMD_LINE_UA");
		cmd_ua(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3660 "itsh.tab.c"
    break;

  case 288:
#line 1916 "itsh.y"
        {
		_CMD_START("CMD_LINE_UB");
		cmd_ub(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3671 "itsh.tab.c"
    break;

  case 289:
#line 1926 "itsh.y"
        {
		_CMD_START("CMD_LINE_SW");
		cmd_sw(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3682 "itsh.tab.c"
    break;

  case 290:
#line 1936 "itsh.y"
        {
		_CMD_START("CMD_LINE_ST");
		cmd_st(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3693 "itsh.tab.c"
    break;

  case 291:
#line 1946 "itsh.y"
        {
		_CMD_START("CMD_LINE_MC");
		cmd_mc(cmd_line, (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 3704 "itsh.tab.c"
    break;

  case 292:
#line 1953 "itsh.y"
        {
		_CMD_START("CMD_LINE_MC");
		cmd_mc(cmd_line, (yyvsp[-7].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) );
	
		next_cmd();
	}
#line 3715 "itsh.tab.c"
    break;

  case 293:
#line 1963 "itsh.y"
        {
		_CMD_START("CMD_LINE_MT");
		cmd_mt(cmd_line, (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 3726 "itsh.tab.c"
    break;

  case 294:
#line 1970 "itsh.y"
        {
		_CMD_START("CMD_LINE_MT");
		cmd_mt(cmd_line, (yyvsp[-7].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) );
	
		next_cmd();
	}
#line 3737 "itsh.tab.c"
    break;

  case 295:
#line 1980 "itsh.y"
        {
		_CMD_START("CMD_LINE_DA");
		cmd_da(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3748 "itsh.tab.c"
    break;

  case 296:
#line 1990 "itsh.y"
        {
		_CMD_START("CMD_LINE_SL");
		cmd_sl(cmd_line, (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 3759 "itsh.tab.c"
    break;

  case 297:
#line 2000 "itsh.y"
        {
		_CMD_START("CMD_LINE_TD");
		cmd_td(cmd_line, (yyvsp[-1].strval), "");
	
		next_cmd();
	}
#line 3770 "itsh.tab.c"
    break;

  case 298:
#line 2010 "itsh.y"
        {
		_CMD_START("CMD_LINE_RES_TD-1");
		cmd_td(cmd_line, (yyvsp[-2].strval) , (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3781 "itsh.tab.c"
    break;

  case 299:
#line 2017 "itsh.y"
        {
		_CMD_START("CMD_LINE_RES_TD-2");
		cmd_td(cmd_line, "" , (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3792 "itsh.tab.c"
    break;

  case 300:
#line 2027 "itsh.y"
        {
		_CMD_START("CMD_LINE_AE");
		cmd_ae(cmd_line , (yyvsp[-3].strval) , (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3803 "itsh.tab.c"
    break;

  case 301:
#line 2037 "itsh.y"
        {
		_CMD_START("CMD_LINE_AR(1-25)");
		cmd_ar(cmd_line , (yyvsp[-49].strval) , (yyvsp[-47].strval) , (yyvsp[-45].strval), (yyvsp[-43].strval), (yyvsp[-41].strval), (yyvsp[-39].strval), (yyvsp[-37].strval), (yyvsp[-35].strval), (yyvsp[-33].strval), (yyvsp[-31].strval), (yyvsp[-29].strval), (yyvsp[-27].strval), (yyvsp[-25].strval), (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 3814 "itsh.tab.c"
    break;

  case 302:
#line 2044 "itsh.y"
        {
		_CMD_START("CMD_LINE_AR(0)");
		cmd_ar(cmd_line , (yyvsp[-3].strval) , (yyvsp[-1].strval) , "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" );
	
		next_cmd();
	}
#line 3825 "itsh.tab.c"
    break;

  case 303:
#line 2054 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-2].strval),  1, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3836 "itsh.tab.c"
    break;

  case 304:
#line 2061 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-8].strval),  4, (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3847 "itsh.tab.c"
    break;

  case 305:
#line 2068 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-6].strval),  3, (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3858 "itsh.tab.c"
    break;

  case 306:
#line 2075 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-10].strval),  5, (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3869 "itsh.tab.c"
    break;

  case 307:
#line 2082 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-24].strval), 12, (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3880 "itsh.tab.c"
    break;

  case 308:
#line 2089 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-26].strval), 13, (yyvsp[-25].strval), (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3891 "itsh.tab.c"
    break;

  case 309:
#line 2096 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-52].strval), 26, (yyvsp[-51].strval), (yyvsp[-49].strval), (yyvsp[-47].strval), (yyvsp[-45].strval), (yyvsp[-43].strval), (yyvsp[-41].strval), (yyvsp[-39].strval), (yyvsp[-37].strval), (yyvsp[-35].strval), (yyvsp[-33].strval), (yyvsp[-31].strval), (yyvsp[-29].strval), (yyvsp[-27].strval), (yyvsp[-25].strval), (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3902 "itsh.tab.c"
    break;

  case 310:
#line 2103 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-4].strval), 2, (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3913 "itsh.tab.c"
    break;

  case 311:
#line 2110 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-34].strval), 17, (yyvsp[-33].strval), (yyvsp[-31].strval), (yyvsp[-29].strval), (yyvsp[-27].strval), (yyvsp[-25].strval), (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3924 "itsh.tab.c"
    break;

  case 312:
#line 2117 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-22].strval), 11, (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3935 "itsh.tab.c"
    break;

  case 313:
#line 2124 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-12].strval), 6, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3946 "itsh.tab.c"
    break;

  case 314:
#line 2131 "itsh.y"
        {
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, (yyvsp[-16].strval), 8, (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3957 "itsh.tab.c"
    break;

  case 315:
#line 2141 "itsh.y"
        {
		_CMD_START("CMD_LINE_HA");
		cmd_ha(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3968 "itsh.tab.c"
    break;

  case 316:
#line 2151 "itsh.y"
        {
		_CMD_START("CMD_LINE_LK");
		cmd_lk(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3979 "itsh.tab.c"
    break;

  case 317:
#line 2161 "itsh.y"
        {
		_CMD_START("CMD_LINE_YD");
		cmd_yd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 3990 "itsh.tab.c"
    break;

  case 318:
#line 2171 "itsh.y"
        {
		_CMD_START("CMD_LINE_OT");
		cmd_ot(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4001 "itsh.tab.c"
    break;

  case 319:
#line 2181 "itsh.y"
        {
		_CMD_START("CMD_LINE_OT");
		cmd_m(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4012 "itsh.tab.c"
    break;

  case 320:
#line 2191 "itsh.y"
        {
		_CMD_START("CMD_LINE_JH");
		cmd_jh(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4023 "itsh.tab.c"
    break;

  case 321:
#line 2201 "itsh.y"
        {
		_CMD_START("CMD_LINE_JS");
		cmd_js(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4034 "itsh.tab.c"
    break;

  case 322:
#line 2211 "itsh.y"
        {
		_CMD_START("CMD_LINE_JE");
		cmd_je(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4045 "itsh.tab.c"
    break;

  case 323:
#line 2221 "itsh.y"
        {
		_CMD_START("CMD_LINE_AB");
		cmd_ab(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4056 "itsh.tab.c"
    break;

  case 324:
#line 2231 "itsh.y"
        {
		_CMD_START("CMD_LINE_SS");
	#ifdef DEBUG
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,cmd_line);
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,(yyvsp[-2].strval));
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,(yyvsp[-1].strval));
	#endif

		cmd_ss(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4073 "itsh.tab.c"
    break;

  case 325:
#line 2247 "itsh.y"
        {
		_CMD_START("CMD_LINE_SR");
		cmd_sr(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4084 "itsh.tab.c"
    break;

  case 326:
#line 2257 "itsh.y"
        {
		_CMD_START("CMD_LINE_SG");
		cmd_sg(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4095 "itsh.tab.c"
    break;

  case 327:
#line 2267 "itsh.y"
        {
		_CMD_START("CMD_LINE_SU");
		cmd_su(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4106 "itsh.tab.c"
    break;

  case 328:
#line 2277 "itsh.y"
        {
		_CMD_START("CMD_LINE_DG");
		cmd_res_remote_dl( cmd_line, (yyvsp[-6].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4117 "itsh.tab.c"
    break;

  case 329:
#line 2284 "itsh.y"
        {
		_CMD_START("CMD_LINE_DU");
		cmd_res_remote_dl( cmd_line, (yyvsp[-6].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4128 "itsh.tab.c"
    break;

  case 330:
#line 2291 "itsh.y"
        {
		_CMD_START("CMD_LINE_DC");
		cmd_res_remote_dl( cmd_line, (yyvsp[-6].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4139 "itsh.tab.c"
    break;

  case 331:
#line 2298 "itsh.y"
        {
		_CMD_START("CMD_LINE_DR");
		cmd_res_remote_dl( cmd_line, (yyvsp[-6].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4150 "itsh.tab.c"
    break;

  case 332:
#line 2305 "itsh.y"
        {
		_CMD_START("CMD_LINE_DR");
		cmd_res_remote_dl( cmd_line, (yyvsp[-6].strval) , (yyvsp[-5].strval) , (yyvsp[-3].strval) , (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4161 "itsh.tab.c"
    break;

  case 333:
#line 2315 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK1(5)");
		cmd_astrsk1(cmd_line, 5 , (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4172 "itsh.tab.c"
    break;

  case 334:
#line 2322 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK1(4)");
		cmd_astrsk1(cmd_line, 4 , (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4183 "itsh.tab.c"
    break;

  case 335:
#line 2329 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK1(3)");
		cmd_astrsk1(cmd_line, 3 , (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4194 "itsh.tab.c"
    break;

  case 336:
#line 2336 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK1(2)");
		cmd_astrsk1(cmd_line, 2 , (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4205 "itsh.tab.c"
    break;

  case 337:
#line 2343 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK1(1)");
		cmd_astrsk1(cmd_line, 1 ,(yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4216 "itsh.tab.c"
    break;

  case 338:
#line 2353 "itsh.y"
        {
		_CMD_START("CMD_LINE_ASTRSK2");
		cmd_astrsk2(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4227 "itsh.tab.c"
    break;

  case 339:
#line 2364 "itsh.y"
        {
		_CMD_START("CMD_LINE_NUMSIGN");
		cmd_numsign(cmd_line, (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4238 "itsh.tab.c"
    break;

  case 340:
#line 2375 "itsh.y"
        {
		_CMD_START("CMD_LINE_HD");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4249 "itsh.tab.c"
    break;

  case 341:
#line 2386 "itsh.y"
        {
		_CMD_START("CMD_LINE_HP");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4260 "itsh.tab.c"
    break;

  case 342:
#line 2397 "itsh.y"
        {
		_CMD_START("CMD_LINE_HQ");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4271 "itsh.tab.c"
    break;

  case 343:
#line 2407 "itsh.y"
        {
		_CMD_START("CMD_LINE_FR");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4282 "itsh.tab.c"
    break;

  case 344:
#line 2417 "itsh.y"
        {
		_CMD_START("CMD_LINE_FD");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4293 "itsh.tab.c"
    break;

  case 345:
#line 2428 "itsh.y"
        {
		_CMD_START("CMD_LINE_FQ");
		cmd_fd(cmd_line, (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4304 "itsh.tab.c"
    break;

  case 346:
#line 2438 "itsh.y"
        {
		_CMD_START("CMD_LINE_RR(0)");
		cmd_rr(cmd_line , (yyvsp[-3].strval), (yyvsp[-1].strval), "", "", "", "", "", "", "", "", "" );
	
		next_cmd();
	}
#line 4315 "itsh.tab.c"
    break;

  case 347:
#line 2445 "itsh.y"
        {
		_CMD_START("CMD_LINE_RR(1)");
		cmd_rr(cmd_line , (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval) );
	
		next_cmd();
	}
#line 4326 "itsh.tab.c"
    break;

  case 348:
#line 2452 "itsh.y"
        {
		_CMD_START("CMD_LINE_RR(2)");
		cmd_rr(cmd_line , (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval), "", "" );
	
		next_cmd();
	}
#line 4337 "itsh.tab.c"
    break;

  case 349:
#line 2462 "itsh.y"
        {
		_CMD_START("CMD_LINE_SSID");
		cmd_ssid(cmd_line, (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4348 "itsh.tab.c"
    break;

  case 350:
#line 2472 "itsh.y"
        {
		_CMD_START("CMD_LINE_LKOK");
		cmd_lkok(cmd_line, (yyvsp[-3].strval), (yyvsp[-2].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4359 "itsh.tab.c"
    break;

  case 351:
#line 2482 "itsh.y"
        {
		_CMD_START("CMD_LINE_VE");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-8].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",(yyvsp[-7].strval));
		cmd_x1(cmd_line, (yyvsp[-8].strval),  4, (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));

	
		next_cmd();
	}
#line 4373 "itsh.tab.c"
    break;

  case 352:
#line 2495 "itsh.y"
        {
		_CMD_START("CMD_LINE_TC");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-20].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",(yyvsp[-19].strval));
		cmd_x1(cmd_line, (yyvsp[-20].strval), 12, (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval),"55535","55535");
	
		next_cmd();
	}
#line 4386 "itsh.tab.c"
    break;

  case 353:
#line 2504 "itsh.y"
        {
		_CMD_START("CMD_LINE_TC");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-24].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",(yyvsp[-23].strval));
		cmd_x1(cmd_line, (yyvsp[-24].strval), 12, (yyvsp[-23].strval), (yyvsp[-21].strval), (yyvsp[-19].strval), (yyvsp[-17].strval), (yyvsp[-15].strval), (yyvsp[-13].strval), (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4399 "itsh.tab.c"
    break;

  case 354:
#line 2516 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4417 "itsh.tab.c"
    break;

  case 355:
#line 2530 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4435 "itsh.tab.c"
    break;

  case 356:
#line 2544 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4453 "itsh.tab.c"
    break;

  case 357:
#line 2558 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4471 "itsh.tab.c"
    break;

  case 358:
#line 2572 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4489 "itsh.tab.c"
    break;

  case 359:
#line 2586 "itsh.y"
        {
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",(yyvsp[-13].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",(yyvsp[-11].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",(yyvsp[-9].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",(yyvsp[-7].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",(yyvsp[-5].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",(yyvsp[-3].strval));
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",(yyvsp[-1].strval));
		cmd_kl(cmd_line, (yyvsp[-11].strval), (yyvsp[-9].strval), (yyvsp[-7].strval), (yyvsp[-5].strval), (yyvsp[-3].strval), (yyvsp[-1].strval));
	
		next_cmd();
	}
#line 4507 "itsh.tab.c"
    break;


#line 4511 "itsh.tab.c"

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
                  yystos[+*yyssp], yyvsp);
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
#line 2622 "itsh.y"


int _MAIL(){
	int ret = -1;
	

	setInitial_mode();
	yyclearin;

	return 0;
}

int _MAIL_HEADER(){
	
	#ifdef DEBUG
	printf("[%s][Line:%04d](...mail head end,next...BODY...)\n",__FUNCTION__,__LINE__);
	#endif
	
	return 0;
}

int _MLTYPE_ONLY_POS(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_ONLY_POS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"");
	return 0;
}

int _MLTYPE_DAILY_DAYTIME(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_DAYTIME);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"L");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_OPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_NON_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_NOPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_EXCEPTION(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_EXP);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_RESPONSE_RT(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RT);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RT");
	return 0;
}

int _MLTYPE_ALARM_SC(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SC);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_AMNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AM");
	return 0;
}

int _MLTYPE_HSOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HS");
	return 0;
}

int _MLTYPE_HSNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HS");
	return 0;
}

int _MLTYPE_HEOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HE");
	return 0;
}

int _MLTYPE_HENG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HE");
	return 0;
}

int _MLTYPE_HFOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HF);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HF");
	return 0;
}

int _MLTYPE_HFNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HF);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HF");
	return 0;
}

int _MLTYPE_HHOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HH");
	return 0;
}

int _MLTYPE_HHNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HH");
	return 0;
}

int _MLTYPE_HLOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HL");
	return 0;
}

int _MLTYPE_HLNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HL");
	return 0;
}

int _MLTYPE_RESPONSE_AC(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AC");
	return 0;
}

int _MLTYPE_ALARM_SA(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SA);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_BT(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BT);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_RESPONSE_AM(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AM");
	return 0;
}

int _MLTYPE_RESPONSE_CL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CL");
	return 0;
}

int _MLTYPE_RESPONSE_CM0(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CM0);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CM0");
	return 0;
}

int _MLTYPE_RESPONSE_CM1(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CM1);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CM1");
	return 0;
}

int _MLTYPE_RESPONSE_CT0(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CT0);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CT0");
	return 0;
}

int _MLTYPE_RESPONSE_CT1(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CT1);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CT1");
	return 0;
}

int _MLTYPE_XX(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XX);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_SD(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SD);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SD");
	return 0;
}

int _MLTYPE_RM(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RM");
	return 0;
}

int _MLTYPE_XX_V7(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XX_V7);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_TD(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_TD);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"TD");
	return 0;
}

int _MLTYPE_DAILY_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_OPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y1");
	return 0;
}

int _MLTYPE_DAILY_NOPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NOPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y2");
	return 0;
}

int _MLTYPE_ALARM_SS(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SG);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SU(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SU);

	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SU");
	return 0;
}


int _MLTYPE_RES_REMOTE_DL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_DG);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"DG");
	return 0;
}


int _MLTYPE_XXXX(int type){
	_MLTYPE_START(__FUNCTION__);
	#ifdef DEBUG
	printf("[%s][Line:%04d][%d]\n",__FUNCTION__,__LINE__,type);
	printf("\n");
	#endif
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XXXX);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"9");
	return 0;
}

int _MLTYPE_ASTRSK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HANYO);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"**");
	return 0;
}

int _MLTYPE_FDFR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_FDFR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"FD");
	return 0;
}

int _MLTYPE_HDHQHP(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HDHQHP);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HD");
	return 0;
}

int _MLTYPE_LKOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_LKOK);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"LK");
	return 0;
}

int _MLTYPE_AE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AE");
	return 0;
}

int _MLTYPE_AR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AR");
	return 0;
}

int _MLTYPE_RR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RR");
	return 0;
}

int _MLTYPE_SSID(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SSID);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SID");
	return 0;
}

int _MLTYPE_KL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_KL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"KL");
	return 0;
}

int _MLTYPE_START(char *s){
	printf("[%s][Line:%04d](^-^)%s\n",__FUNCTION__,__LINE__,s);
	printf("\n");
	
	return 0;
}

int _CMD_START(char *s){
	#ifdef DEBUG
	printf("[%s][Line:%04d](+_+)%s\n",__FUNCTION__,__LINE__,s);
	#endif
	
	return 0;
}



int _eof(char* p){
	#ifdef DEBUG
	printf("[%s][Line:%04d]*************EOF*************\n",__FUNCTION__,__LINE__);
	#endif
	yyclearin;
	setInitial_mode();
	return 0;
}

yyerror (s) 
     char *s;
{
	#ifdef DEBUG
	printf("[%s][Line:%04d]*************yyerror*************\n",__FUNCTION__,__LINE__);
	printf("[%s][Line:%04d]%s\n",__FUNCTION__,__LINE__,s);
	printf("[%s][Line:%04d]*********************************\n",__FUNCTION__,__LINE__);
	#endif
	
	yyclearin;
	setInitial_mode();
}
