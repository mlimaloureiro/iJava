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
    struct is_root *tree = NULL;
    char* yytext;
%}

%union{
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
    
    struct is_opt_expr*                     is_opt_expr_t;
    struct is_opt_array_pos*                is_opt_array_pos_t;
    struct is_expression*                   is_expression_t;
    
    struct is_array_dim*                    is_array_dim_t;
    struct is_opt_args*                     is_opt_args_t;
    struct is_args*                         is_args_t;
    struct is_opt_args_list*                is_opt_args_list_t;

    /* structures */
    char *value;
    int intlit;
    char *identifier;
}

%type <is_root_t>                   Start
%type <is_program_t>                Program
%type <field_or_method_t>			field_or_method
%type <method_decl_t>               method_decl
%type <field_decl_t>                field_decl
%type <field_declarator_t>          var_decl
%type <field_declarator_list_t>     opt_variable
%type <is_type_specifier_t>         Type
%type <is_opt_array_t>              opt_array
%type <is_var_type_t>               var_type

%type <is_opt_formal_params_t>      opt_formal_params
%type <is_formal_params_t>          formal_params
%type <is_formal_params_list_t>     opt_param

%type <is_function_type_t>          function_type
%type <is_opt_var_decl_t>           opt_var_decl
%type <is_opt_statement_t>          opt_statement
%type <is_statement_t>              Statement
%type <is_opt_expr_t>               opt_expr
%type <is_opt_array_pos_t>          opt_array_pos
%type <is_expression_t>             Expr

%type <is_array_dim_t>              array_dim;
%type <is_opt_args_t>               opt_args
%type <is_args_t>                   Args
%type <is_opt_args_list_t>          opt_arg



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

Start : Program {$$ = insert_start_list($1);tree = $$;}
;
Program : CLASS ID OBRACE field_or_method CBRACE {$$ = insert_program($2, $4);}

field_or_method: {$$ = insert_field_or_method(NULL, NULL, NULL);}
|field_decl field_or_method { $$ = insert_field_or_method($1, NULL, $2);}
|method_decl field_or_method { $$ = insert_field_or_method(NULL, $1, $2); }
;

field_decl : STATIC var_decl { $$ = insert_field_declaration($2);}
;

method_decl : PUBLIC STATIC function_type ID OCURV opt_formal_params CCURV OBRACE opt_var_decl opt_statement CBRACE { $$ = insert_method_declaration($3, $4, $6, $9, $10); }
;

function_type: Type { $$ = insert_function_type($1); }
|VOID { $$ = insert_function_type(NULL); }
;

opt_formal_params:  {$$ = insert_opt_formal_params(NULL);}
|formal_params      {$$ = insert_opt_formal_params($1);}
;

formal_params : Type ID opt_param { $$ = insert_formal_params($1, $2, $3); }
| STRING OSQUARE CSQUARE ID { $$ = insert_formal_params(NULL, $4, NULL); }
;

opt_param : { $$ = insert_formal_params_list(NULL,NULL,NULL);}
|COMMA Type ID opt_param { $$ = insert_formal_params_list($2, $3, $4);}
;

opt_var_decl: { $$ = insert_opt_var_decl(NULL,NULL); }
|var_decl opt_var_decl { $$ = insert_opt_var_decl($1, $2); }
;

opt_variable:           { $$ = insert_opt_vars(NULL,NULL); }
|COMMA ID opt_variable  { $$ = insert_opt_vars($2, $3); }
;

var_decl : Type ID opt_variable SEMIC { $$ = insert_field_declarator($1, $2, $3); }
;

Type : var_type opt_array { $$ = insert_type_specifier($1, $2); }
;

var_type:INT    { $$ = insert_type(is_int); }
|BOOL           { $$ = insert_type(is_bool); }
;

opt_array:                 { $$ = insert_opt_array(not_array); }
|OSQUARE CSQUARE           { $$ = insert_opt_array(is_array); }
;

opt_statement: { $$ = insert_opt_statement(NULL,NULL); }
|Statement opt_statement { $$ = insert_opt_statement($1, $2); }
;

Statement : OBRACE opt_statement CBRACE { $$ = insert_statement($2, compound_stm, NULL, NULL, NULL, NULL, NULL, NULL); }
| IF OCURV Expr CCURV Statement { $$ = insert_statement(NULL, if_stm, $5, NULL, NULL, NULL, $3, NULL); }
| IF OCURV Expr CCURV Statement ELSE Statement { $$ = insert_statement(NULL, else_stm, $5, $7, NULL, NULL, $3, NULL); }
| WHILE OCURV Expr CCURV Statement { $$ = insert_statement(NULL, while_stm, $5, NULL, NULL, NULL, $3, NULL); }
| PRINT OCURV Expr CCURV SEMIC { $$ = insert_statement(NULL, print_stm, NULL, NULL, NULL, NULL, $3, NULL); }
| ID opt_array_pos ASSIGN Expr SEMIC { $$ = insert_statement(NULL, store_stm, NULL, NULL, $1, $2, $4, NULL); }
| RETURN opt_expr SEMIC { $$ = insert_statement(NULL, return_stm, NULL, NULL, NULL, NULL, NULL, $2); }
;


opt_array_pos: { $$ = insert_opt_array_pos(NULL); }
|OSQUARE Expr CSQUARE { $$ = insert_opt_array_pos($2); }
;

opt_expr: { $$ = insert_opt_expr(NULL); }
|Expr { $$ = insert_opt_expr($1); }
;

Expr : array_dim OSQUARE Expr CSQUARE { $$ = insert_expression(array_expr,$1,$3,NULL,NULL); }
| NEW var_type OSQUARE Expr CSQUARE { $$ = insert_expression(new_expr,NULL,$4,NULL,$2); }
| Expr OP1 Expr { $$ = insert_expression(op_expr,NULL,$1,$3,NULL); }
| Expr OP2 Expr { $$ = insert_expression(op_expr,NULL,$1,$3,NULL); }
| Expr OP3 Expr { $$ = insert_expression(op_expr,NULL,$1,$3,NULL); }
| Expr OP4 Expr { $$ = insert_expression(op_expr,NULL,$1,$3,NULL); }
| OP3 Expr { $$ = insert_expression(op3_expr,NULL,$2,NULL,NULL); }
| NOT Expr { $$ = insert_expression(not_expr,NULL,$2,NULL,NULL);}
| array_dim { $$ = insert_expression(array_expr2,$1,NULL,NULL,NULL); }
;

array_dim: ID { }
| INTLIT { }
| BOOLLIT { }
| OCURV Expr CCURV { }
| Expr DOTLENGTH { }
| PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV { }
| ID OCURV opt_args CCURV { }
;

opt_args: { }
|Args { }
;

Args : Expr opt_arg { }
;

opt_arg: { }
|COMMA Expr opt_arg { }
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









