%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "structures.h"

    int yylex(void);
    int yyerror(char *s);
    int linha, coluna,error;
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

%right ASSIGN
%left OP1
%left OP2
%left OP3
%left OP4
%right NOT
%left OBRACE CBRACE OSQUARE CSQUARE
%nonassoc IF ELSE


%%
    start :     program;
    program:    CLASS ID OBRACE CBRACE
                {};
        |       CLASS ID OBRACE class_definition CBRACE
                {}
        ;

    class_definition: class_definition FieldDecl
                      {}
        |             class_definition MethodDecl
                      {}
        |             FieldDecl
                      {}
        |             MethodDecl
                      {}
        ;

    FieldDecl: STATIC VarDecl
              {}
    ;

    VarDecl: Type ID SEMIC
             {}
        |    Type ID VarDeclList SEMIC
             {}
        ;

    VarDeclList: VarDeclList COMMA ID
                 {}
        |        COMMA ID
                 {}
        ;

    Type: INT OSQUARE CSQUARE
          {}
        | BOOL OSQUARE CSQUARE
          {}
        | INT
          {}
        | BOOL
          {}
        ;

    /* --------- METHODS PART ---------*/
    MethodDecl: PUBLIC STATIC Type ID method_declarator
                {}
        |       PUBLIC STATIC VOID ID method_declarator
                {}
        ;

    method_declarator: OCURV FormalParams CCURV OBRACE method_optionals CBRACE
                       {}
        |              OCURV CCURV OBRACE method_optionals CBRACE
                       {}
        |              OCURV CCURV OBRACE CBRACE
                       {}
        ;

    method_optionals: method_var_declarator method_statement
                      {}
        |             method_var_declarator
                      {}
        |             method_statement
                      {}
        ;

    method_var_declarator: method_var_declarator VarDecl
                           {}
        |                  VarDecl
                           {}
        ;

    method_statement: method_statement Statement
                      {}
        |             Statement
                      {}
        ;

    FormalParams: Type ID formal_params_cont
                  {}
        |         STRING OSQUARE CSQUARE ID
                  {}
        ;

    formal_params_cont: formal_params_cont COMMA Type ID
                        {}
        |               COMMA Type ID
                        {}
        ;

    /* ----------- STATEMENTS ------------ */

    Statement: OBRACE Statement CBRACE
               {}
        /*|      IF OCURV Expr CCURV Statement ELSE Statement
               {printf("statement 2\n");}*/
        |      IF OCURV Expr CCURV Statement
               {}
        |      WHILE OCURV Expr CCURV Statement
               {}
        |      PRINT OCURV Expr CCURV SEMIC
               {}
        |      ID OSQUARE Expr CSQUARE ASSIGN Expr SEMIC
               {}
        |      ID ASSIGN Expr SEMIC
               {}
        |      RETURN Expr SEMIC
               {}
        |      RETURN SEMIC
               {}
        ;

    /* ---------- EXPRESSIONS ------------ */
    Expr: /*Expr OP1 Expr
          {printf("expr1");}
      |   Expr OP2 Expr
          {printf("expr2");}
      |   Expr OP3 Expr
          {printf("expr3");}
      |   Expr OP4 Expr
          {printf("expr4");}
      |   Expr OSQUARE Expr CSQUARE
          {printf("expr5");}
      |*/   ID
          {}
      |   INTLIT
          {}
      |   BOOLLIT
          {}
      |   NEW INT OSQUARE Expr CSQUARE
          {}
      |   NEW BOOL OSQUARE Expr CSQUARE
          {}
      |   OCURV Expr CCURV
          {}
      |   Expr DOTLENGTH
          {}
      | /*  OP3 Expr
          {printf("expr13");}
      |   NOT Expr
          {printf("expr14");}
      | */  PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
          {}
      |   ID OCURV Args CCURV
          {}
      |   ID OCURV CCURV
          {}

    Args: Args COMMA Expr
          {}
        |  Expr
          {}


%%

int main(int argc, char* argv[])
{
    coluna = 1;
    linha = 1;
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf ("Line %d, col %zd: %s: %s\n", linha, coluna - strlen(yytext), s, yytext);
    error=1;
    return 0;
}


