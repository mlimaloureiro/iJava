#define _STRUCTURES_

typedef enum { is_bool,is_int} is_type;

typedef enum {d_field_declaration, d_method_declaration} d_start_element;

typedef struct is_start_list {
    d_start_element  element_type;
    union{
        struct is_field_declaration* field_declaration
        struct is_method_declaration* method_declaration;
    }element;
    struct is_start_list *next;
}is_start_list;


typedef struct is_field_declaration {
    struct is_type_specifier *type_specifier;
    char *identifier;
}is_field_declaration;

typedef struct is_type_specifier{
    is_type type;
}is_type_specifier;

