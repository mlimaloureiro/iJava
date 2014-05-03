#define _STRUCTURES_

typedef enum { is_bool,is_int} is_type;
typedef enum {d_field_declaration, d_method_declaration} d_field_or_method_type;
typedef enum {is_array,not_array} opt_array;

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
    union {
        struct is_field_declaration* field;
        struct is_method_declaration* method;
    } element;
    struct is_field_or_method* next;
} is_field_or_method;


typedef struct is_method_declaration {
    struct is_type_specifier* type_specifier;
} is_method_declaration;

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


typedef struct is_type_specifier{
    struct var_type* var_type;
    struct is_opt_array* opt_array;
}is_type_specifier;

typedef struct var_type {
    is_type type;
}var_type;

typedef struct is_opt_array {
    opt_array array;
} is_opt_array;
