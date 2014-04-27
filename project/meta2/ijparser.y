%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

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

    program: CLASS ID OBRACE CBRACE {printf("%s\n", $2);};


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




