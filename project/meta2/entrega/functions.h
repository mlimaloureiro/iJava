is_root* insert_start_list(is_program* program);

is_program* insert_program(char* ident, is_field_or_method* field_or_method);

is_field_or_method* insert_field_or_method(is_field_declaration* field, is_method_declaration* method, is_field_or_method* field_or_method_to_insert);

is_field_declaration* insert_field_declaration(field_declarator* varDecl);

field_declarator* insert_field_declarator(is_type_specifier* type, char* ident, field_declarator_list* opt_list);

field_declarator_list* insert_opt_vars(char* ident, field_declarator_list *next);

is_type_specifier* insert_type_specifier(var_type* var_type, is_opt_array* opt_array);

var_type* insert_type(is_type type);

is_opt_array* insert_opt_array(opt_array arr);


