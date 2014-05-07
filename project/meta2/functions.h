is_root* insert_start_list(is_program* program);

is_program* insert_program(char* ident, is_field_or_method* field_or_method);

is_field_or_method* insert_field_or_method(is_field_declaration* field, is_method_declaration* method, is_field_or_method* field_or_method_to_insert);

is_field_declaration* insert_field_declaration(field_declarator* varDecl);

field_declarator* insert_field_declarator(is_type_specifier* type, char* ident, field_declarator_list* opt_list);

field_declarator_list* insert_opt_vars(char* ident, field_declarator_list *next);

is_type_specifier* insert_type_specifier(var_type* var_type, is_opt_array* opt_array);

var_type* insert_type(is_type type);

is_opt_array* insert_opt_array(opt_array arr);



is_method_declaration* insert_method_declaration(is_function_type* function_type,
                                                 char* id,
                                                 is_opt_formal_params* opt_formal_params,
                                                 is_opt_var_decl* opt_var_decl,
                                                 is_opt_statement* opt_statement );

is_function_type* insert_function_type(is_type_specifier* type_specifier);

is_opt_formal_params* insert_opt_formal_params(is_formal_params* params);

is_formal_params* insert_formal_params(is_type_specifier* type, char* id, is_formal_params_list* list);

is_formal_params_list* insert_formal_params_list(is_type_specifier* type, char* id, is_formal_params_list* list);

is_opt_var_decl* insert_opt_var_decl(field_declarator* var_decl, is_opt_var_decl* next);

is_opt_statement* insert_opt_statement(is_statement* , is_opt_statement* list);

is_statement* insert_statement(is_opt_statement* compound, statement_type type, is_statement* statement1, is_statement* statement2, char* id, is_opt_array_pos* opt_array_pos, is_expression* expr, is_opt_expr* opt_expr);


is_opt_array_pos* insert_opt_array_pos(is_expression* expr);

is_opt_expr* insert_opt_expr(is_expression* expr);

is_expression* insert_expression(expression_type type, is_array_dim* array_dim, is_expression* expression1,
                                 is_expression* expression2, var_type* var_type, char* value);


is_array_dim* insert_array_dim(char* id, is_expression* expression, is_opt_args* opt_args, char* value, int type_check, is_array_dim* next);


is_opt_args* insert_opt_args(is_args* args);

is_args* insert_args(is_expression* expression, is_opt_args_list* list);

is_opt_args_list* insert_opt_arg(is_expression* expression, is_opt_args_list* list);





