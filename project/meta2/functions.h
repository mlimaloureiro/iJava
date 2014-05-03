is_root* insert_start_list(is_program* program);

is_program* insert_program(char* ident, is_field_or_method* field_or_method);

is_field_or_method* insert_field_or_method(is_field_declaration* field, is_method_declaration* method, is_field_or_method* field_or_method_to_insert);
