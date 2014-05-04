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
     NUMBER = 258,
     ENDOF = 259,
     OCURV = 260,
     CCURV = 261,
     OBRACE = 262,
     CBRACE = 263,
     OSQUARE = 264,
     CSQUARE = 265,
     BOOLLIT = 266,
     INT = 267,
     BOOL = 268,
     NEW = 269,
     PRINT = 270,
     PARSEINT = 271,
     CLASS = 272,
     PUBLIC = 273,
     STATIC = 274,
     VOID = 275,
     STRING = 276,
     DOTLENGTH = 277,
     RETURN = 278,
     IF = 279,
     ELSE = 280,
     WHILE = 281,
     RESERVED = 282,
     OP1 = 283,
     OP2 = 284,
     OP3 = 285,
     OP4 = 286,
     ASSIGN = 287,
     SEMIC = 288,
     COMMA = 289,
     ID = 290,
     INTLIT = 291,
     NOT = 292,
     OR = 293,
     AND = 294,
     EQUALS = 295
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ENDOF 259
#define OCURV 260
#define CCURV 261
#define OBRACE 262
#define CBRACE 263
#define OSQUARE 264
#define CSQUARE 265
#define BOOLLIT 266
#define INT 267
#define BOOL 268
#define NEW 269
#define PRINT 270
#define PARSEINT 271
#define CLASS 272
#define PUBLIC 273
#define STATIC 274
#define VOID 275
#define STRING 276
#define DOTLENGTH 277
#define RETURN 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define RESERVED 282
#define OP1 283
#define OP2 284
#define OP3 285
#define OP4 286
#define ASSIGN 287
#define SEMIC 288
#define COMMA 289
#define ID 290
#define INTLIT 291
#define NOT 292
#define OR 293
#define AND 294
#define EQUALS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "ijparser.y"
{
    struct is_root*                         is_root_t;
    struct is_program*                      is_program_t;
    struct is_field_or_method*              field_or_method_t;
    struct is_method_declaration*           method_decl_t;
    struct is_field_declaration*            field_decl_t;
    struct field_declarator*                field_declarator_t;
    struct field_declarator_list*           field_declarator_list_t;
    struct is_type_specifier*               is_type_specifier_t;
    struct is_opt_array*                    is_opt_array_t;
    struct var_type*                        is_var_type_t;
    struct is_function_type*                is_function_type_t;
    
    struct is_opt_formal_params*            is_opt_formal_params_t;
    struct is_formal_params*                is_formal_params_t;
    struct is_formal_params_list*           is_formal_params_list_t;
    
    struct is_opt_var_decl*                 is_opt_var_decl_t;
    struct is_opt_statement*                is_opt_statement_t;
    struct is_statement*                    is_statement_t;

    /* structures */
    char *value;
    int intlit;
    char *identifier;
}
/* Line 1529 of yacc.c.  */
#line 156 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

