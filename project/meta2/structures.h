#define _STRUCTURES_

typedef enum { is_bool,is_int} is_type;

typedef enum {d_field_declaration, d_method_declaration} d_field_or_method_type;


typedef struct is_field_or_method {
    union {
        struct is_field_declaration* field;
        struct is_method_declaration* method;
    };
    struct is_field_or_method* next;
} is_field_or_method;


typedef struct is_method_declaration {
    struct is_type_specifier *type_specifier;
} is_method_declaration;

typedef struct is_field_declaration {
    struct is_type_specifier *type_specifier;
} is_field_declaration;


