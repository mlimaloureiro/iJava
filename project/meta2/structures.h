#define _STRUCTURES_

typedef enum { is_bool,is_int, is_id, is_equality, is_dot_length, is_parse_int, is_func_call} is_type;
typedef enum {d_field_declaration, d_method_declaration} d_field_or_method_type;
typedef enum {is_array,not_array} opt_array;
typedef enum {compound_stm, if_stm, else_stm, print_stm, return_stm, store_stm, while_stm} statement_type;
typedef enum {op_expr, array_expr, op3_expr, array_expr2, not_expr, new_expr} expression_type;

/* ----- common  -----*/

typedef struct is_root {
    struct root* is_root;
    struct is_program* program;
} is_root;

typedef struct is_program {
    char* ident;
    struct is_field_or_method* field_or_method;
    struct is_program* next;
} is_program;

typedef struct is_field_or_method {
    d_field_or_method_type type;
    /*union {*/
        struct is_field_declaration* field;
        struct is_method_declaration* method;
    /*} element;*/
    struct is_field_or_method* next;
} is_field_or_method;

/* ----- \common ----- */

/* ---- field specific ---- */

typedef struct is_field_declaration {
    struct field_declarator* varDecl;
} is_field_declaration;

typedef struct field_declarator {
    char* ident;
    struct is_type_specifier* type_specifier;
    struct field_declarator_list* opt_vars;
} field_declarator;

typedef struct field_declarator_list {
    char* ident;
    struct field_declarator_list* next;
} field_declarator_list;

/* ---- \field specific ----- */


/* ----- var types ----- */

typedef struct is_type_specifier{
    struct var_type* var_type;
    struct is_opt_array* opt_array;
} is_type_specifier;

typedef struct var_type {
    is_type type;
} var_type;

typedef struct is_opt_array {
    opt_array array;
} is_opt_array;

/* ----- \var types ----- */


/* ----- methods ----- */

typedef struct is_method_declaration {
    char* id;
    struct is_function_type* function_type;
    struct is_opt_formal_params* opt_formal_params;
    struct is_opt_var_decl* opt_var_decl;
    struct is_opt_statement* opt_statement;
} is_method_declaration;


typedef struct is_function_type {
    struct is_type_specifier* type_specifier;
} is_function_type;


typedef struct is_opt_formal_params {
    struct is_formal_params* formal_params;
} is_opt_formal_params;


typedef struct is_formal_params {
    char* id;
    struct is_type_specifier* type_specifier;
    struct is_formal_params_list* list;
} is_formal_params;

typedef struct is_formal_params_list {
    char* id;
    struct is_type_specifier* type_specifier;
    struct is_formal_params_list* next;
}is_formal_params_list;


typedef struct is_opt_var_decl {
    struct field_declarator* varDecl;
    struct is_opt_var_decl* next;
} is_opt_var_decl;


typedef struct is_opt_statement {
    struct is_statement* statement;
    struct is_opt_statement* next;
} is_opt_statement;


/* ---- statements ---- */

/* expressions */


typedef struct is_array_dim {
    char* id;
    char* value;
    struct is_expression* expr;
    struct is_opt_args* opt_args;
    struct var_type* dim_type;
} is_array_dim;


typedef struct is_expression {
    expression_type expr_type;
    struct var_type* type;
    struct is_array_dim* array_dim;
    struct is_expression* expression1;
    struct is_expression* expression2;
    char* auxvalue;
} is_expression;

typedef struct is_statement {
    char* id;
    statement_type type;
    struct is_opt_statement* opt_statement;
    struct is_expression* expression;
    struct is_statement* statement1;
    struct is_statement* statement2;
    struct is_opt_array_pos* opt_array_pos;
    struct is_opt_expr* opt_expr;
} is_statement;


typedef struct is_opt_expr {
    struct is_expression* expression;
} is_opt_expr;

typedef struct is_opt_array_pos {
    struct is_expression* expression;
} is_opt_array_pos;


typedef struct is_opt_args {
    struct is_args* args;
} is_opt_args;


typedef struct is_args {
    struct is_expression* expr;
    struct is_opt_args_list* list;
} is_args;


typedef struct is_opt_args_list {
    struct is_expression* expr;
    struct is_opt_args_list* next;
} is_opt_args_list;

















