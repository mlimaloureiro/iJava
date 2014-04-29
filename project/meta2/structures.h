#define _STRUCTURES_

typedef enum {d_method_definition, d_method_declaration, d_declaration} d_start_element;

typedef struct is_start_list {
    d_start_element  element_type;
    union{
        struct is_method_definition* method_definition;
        struct is_method_declaration* method_declaration;
        struct is_declaration* declaration;
    }element;
    struct is_start_list *next;
}is_start_list;