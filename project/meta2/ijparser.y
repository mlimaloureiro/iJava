%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include "structures.h"
	#include "functions.h"
	#include "show.h"


    int yylex(void);
    int yyerror(char *s);
    int linha, coluna,error;
    struct is_program *tree = NULL;
    char* yytext;
%}

%union{
    struct is_start_list* is_start_list_t;
    struct is_program* is_program_t;
    struct is_field_or_method* field_or_method_t;
    struct is_method_declaration* method_decl_t;
    struct is_field_declaration* field_decl_t;
    /* structures */
    char *value;
    int intlit;
    char *identifier;
}

%type <is_start_list_t>             Start
%type <is_program_t>                Program
%type <field_or_method_t>			field_or_method
%type <method_decl_t>               method_decl
%type <field_decl_t>                field_decl

%token NUMBER
%token ENDOF
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

%left OR
%left AND
%left EQUALS
%left OP1
%left OP2
%left OP3
%left OP4
%right NOT
%left DOTLENGTH
%left OCURV CCURV OSQUARE CSQUARE
%nonassoc ELSE

%start Start

%%

Start : Program {/*$$ = insert_start_list($1,NULL);tree = $$;*/}
;
Program : CLASS ID OBRACE field_or_method CBRACE {$$ = insert_program($2, $4); tree = $$;}

field_or_method: {$$ = insert_field_or_method(NULL, NULL, NULL);}
|field_decl field_or_method { $$ = insert_field_or_method($1, NULL, $2);}
|method_decl field_or_method { $$ = insert_field_or_method(NULL, $1, $2); }
;

field_decl : STATIC var_decl {}
;

method_decl : PUBLIC STATIC function_type ID OCURV opt_formal_params CCURV OBRACE opt_var_decl opt_statement CBRACE {  }
;

function_type: Type {}
|VOID {}
;

opt_formal_params:
|formal_params
;

formal_params : Type ID opt_param
| STRING OSQUARE CSQUARE ID
;

opt_param :
|COMMA Type ID opt_param
;

opt_var_decl:
|var_decl opt_var_decl
;

opt_variable:
|COMMA ID opt_variable
;

var_decl : Type ID opt_variable SEMIC
;

Type : var_type opt_array
;

var_type:INT
|BOOL
;

opt_array:
|OSQUARE CSQUARE opt_array
;

opt_statement:
|Statement opt_statement
;

Statement : OBRACE opt_statement CBRACE
| IF OCURV Expr CCURV Statement
| IF OCURV Expr CCURV Statement ELSE Statement
| WHILE OCURV Expr CCURV Statement
| PRINT OCURV Expr CCURV SEMIC
| ID opt_array_pos ASSIGN Expr SEMIC
| RETURN opt_expr SEMIC
;


opt_array_pos:
|OSQUARE Expr CSQUARE
;

opt_expr:
|Expr
;

Expr : array_dim OSQUARE Expr CSQUARE
| NEW n_Type OSQUARE Expr CSQUARE
| Expr OP1 Expr
| Expr OP2 Expr
| Expr OP3 Expr
| Expr OP4 Expr
| OP3 Expr
| NOT Expr
| array_dim
;

array_dim: ID
| INTLIT
| BOOLLIT
| OCURV Expr CCURV
| Expr DOTLENGTH
| PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV
| ID OCURV opt_args CCURV
;

n_Type:INT
|BOOL
;

opt_args:
|Args
;

Args : Expr opt_arg
;

opt_arg:
|COMMA Expr opt_arg
;



%%

int main(int argc, char* argv[])
{
    coluna = 0;
    linha = 1;
    yyparse();

    if(error == 0) {
        show_program(tree);
    }

    return 0;
}

int yyerror(char *s)
{
    printf ("Line %d, col %zd: %s: %s\n", linha, coluna - strlen(yytext) + 1, s, yytext);
    error=1;
    return 0;
}




