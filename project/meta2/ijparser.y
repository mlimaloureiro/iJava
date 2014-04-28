%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "structures.h"

    int yylex(void);
    int yyerror(char *s);
    int linha, coluna;
    char* yytext;
%}

%union{
    /* structures */
    char *value;
    int intlit;
    char *identifier;
}

%token OCURV
%token CCURV
%token OBRACE
%token CBRACE
%token OSQUARE
%token CSQUARE
%token<value> BOOLLIT
%token INT
%token BOOL
%token NEW
%token PRINT
%token PARSEINT
%token CLASS
%token PUBLIC
%token STATIC
%token VOID
%token STRING
%token DOTLENGTH
%token RETURN
%token IF
%token ELSE
%token WHILE
%token<value> RESERVED
%token<value> OP1
%token<value> OP2
%token<value> OP3
%token<value> OP4
%token ASSIGN
%token SEMIC
%token COMMA
%token<identifier> ID
%token<intlit> INTLIT
%token NOT



%%
    start :     program;
    program:    CLASS ID OBRACE CBRACE
                {printf("start program, nothing inside\n");};
        |       CLASS ID OBRACE class_definition CBRACE
                {printf("start program, function definition\n");}
        ;

    class_definition: class_definition FieldDecl
                      {printf("class definition, field declaration\n");}
        |             class_definition MethodDecl
                      {printf("class definition, method declaration\n");}
        |             FieldDecl
                      {printf("field declaration\n");}
        |             MethodDecl
                      {printf("method declaration\n");}
        ;

    FieldDecl: STATIC VarDecl
               {printf("inside field declaration\n");}
    ;

    VarDecl: Type ID SEMIC
             {printf("var declaration\n");}
        |    Type ID VarDeclList SEMIC
             {printf("var declaration list\n");}
        ;

    VarDeclList: VarDeclList COMMA ID
                 {printf("inside declaration list\n");}
        |        COMMA ID
                 {printf("last declaration list\n");}

    Type: INT OSQUARE CSQUARE
          {printf("var INT ARRAY\n");}
        | BOOL OSQUARE CSQUARE
          {printf("var BOOL ARRAY\n");}
        | INT
          {printf("var INT\n");}
        | BOOL
          {printf("var bool\n");}
        ;

    /* --------- METHODS PART ---------*/
    MethodDecl: PUBLIC STATIC Type ID method_declarator
                {printf("inside MethodDecl\n");}
        |       PUBLIC STATIC VOID ID method_declarator
                {printf("inside VOID MethodDecl\n");}
        ;

    method_declarator: OCURV FormalParams CCURV OBRACE method_optionals CBRACE
                       {printf("Method 1\n");}
        |              OCURV CCURV OBRACE method_optionals CBRACE
                       {printf("Method 2\n");}
        |              OCURV CCURV OBRACE CBRACE
                       {printf("Method 3\n");}
        ;

    method_optionals: method_var_declarator method_statement
                      {printf("USING BOTH OPTIONALS\n");}
        |             method_var_declarator
                      {printf("ONLY VAR DECLARATOR\n");}
        |             method_statement
                      {printf("ONLY STATEMENTS\n");}
        ;

    method_var_declarator: method_var_declarator VarDecl
                           {printf("Method var declarator\n");}
        |                  VarDecl
                           {printf("end Method var declarator\n");}
        ;

    method_statement: method_statement Statement
                      {printf("Method statement\n");}
        |             Statement
                      {printf("end Method statement\n");}
        ;

    FormalParams: Type ID formal_params_cont
                  {printf("Formal Params 1\n");}
        |         STRING OSQUARE CSQUARE ID
                  {printf("Formal Params 2\n");}
        ;

    formal_params_cont: formal_params_cont COMMA Type ID
                        {printf("Formal params cont 1\n");}
        |               COMMA Type ID
                        {printf("Formal params cont 2\n");}
        ;

    /* ----------- STATEMENTS ------------ */

    Statement: OBRACE Statement CBRACE
               {printf("statement 1\n");}
        |      IF OCURV Expr CCURV Statement ELSE Statement
               {printf("statement 2\n");}
        |      IF OCURV Expr CCURV Statement
               {printf("statement 3\n");}
        |      WHILE OCURV Expr CCURV Statement
               {printf("statement 4\n");}
        |      PRINT OCURV Expr CCURV SEMIC
               {printf("statement 5\n");}
        |      ID OSQUARE Expr CSQUARE ASSIGN Expr SEMIC
               {printf("statement 6\n");}
        |      ID ASSIGN Expr SEMIC
               {printf("statement 7\n");}
        |      RETURN Expr SEMIC
               {printf("statement 8\n");}
        |      RETURN SEMIC
               {printf("statement 9\n");}
        ;

    /* ---------- EXPRESSIONS ------------ */
    Expr:



%%

int main(int argc, char* argv[])
{
    coluna = 0;
    linha = 0;
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    return 0;
}




