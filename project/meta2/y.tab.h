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
     OCURV = 258,
     CCURV = 259,
     OBRACE = 260,
     CBRACE = 261,
     OSQUARE = 262,
     CSQUARE = 263,
     BOOLLIT = 264,
     INT = 265,
     BOOL = 266,
     NEW = 267,
     PRINT = 268,
     PARSEINT = 269,
     CLASS = 270,
     PUBLIC = 271,
     STATIC = 272,
     VOID = 273,
     STRING = 274,
     DOTLENGTH = 275,
     RETURN = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     RESERVED = 280,
     OP1 = 281,
     OP2 = 282,
     OP3 = 283,
     OP4 = 284,
     ASSIGN = 285,
     SEMIC = 286,
     COMMA = 287,
     ID = 288,
     INTLIT = 289,
     NOT = 290
   };
#endif
/* Tokens.  */
#define OCURV 258
#define CCURV 259
#define OBRACE 260
#define CBRACE 261
#define OSQUARE 262
#define CSQUARE 263
#define BOOLLIT 264
#define INT 265
#define BOOL 266
#define NEW 267
#define PRINT 268
#define PARSEINT 269
#define CLASS 270
#define PUBLIC 271
#define STATIC 272
#define VOID 273
#define STRING 274
#define DOTLENGTH 275
#define RETURN 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define RESERVED 280
#define OP1 281
#define OP2 282
#define OP3 283
#define OP4 284
#define ASSIGN 285
#define SEMIC 286
#define COMMA 287
#define ID 288
#define INTLIT 289
#define NOT 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "ijparser.y"
{
    /* structures */
    char *value;
    int intlit;
    char *identifier;
}
/* Line 1529 of yacc.c.  */
#line 126 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

