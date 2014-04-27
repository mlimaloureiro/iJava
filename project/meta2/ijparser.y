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
    program:    CLASS ID OBRACE CBRACE                      {printf("start program, nothing inside\n");};
        |       CLASS ID OBRACE function_definition CBRACE  {printf("start program, function definition\n");}
        ;

    function_definition: function_definition FieldDecl      {printf("function definition, field declaration\n");}
        //|                function_definition MethodDecl     {printf("function definition, method declaration\n");}
        |                FieldDecl                          {printf("field declaration\n");}
        //|                MethodDecl                         {printf("method declaration\n");}
        ;

    FieldDecl: STATIC VarDecl                               {printf("inside field declaration\n");}
    ;

    VarDecl: Type ID SEMIC                                  {printf("var declaration\n");}
        |    Type ID VarDeclList SEMIC                      {printf("var declaration list\n");}
        ;

    VarDeclList: VarDeclList COMMA ID                       {printf("inside declaration list\n");}
        |        COMMA ID                                   {printf("last declaration list\n");}

    Type: INT OSQUARE CSQUARE                               {printf("var INT ARRAY\n");}
        | BOOL OSQUARE CSQUARE                              {printf("var BOOL ARRAY\n");}
        | INT                                               {printf("var INT\n");}
        | BOOL                                              {printf("var bool\n");}
        ;



    //MethodDecl:




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




