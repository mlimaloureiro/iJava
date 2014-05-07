#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int indentation = 0;

void indent();
void print_field_declaration(is_field_or_method* var);
void print_method_declaration(is_field_or_method* var);
void print_formal_params(is_formal_params* var);
void print_formal_params_list(is_formal_params_list* var);
void print_opt_var_decl(is_opt_var_decl* var);
void print_type(is_type_specifier* type);
void print_statements(is_statement* var);
void print_opt_statements(is_opt_statement* var);
void print_expression(is_expression* var);
void print_parse_args(is_opt_args* var);

void print_op_expression(is_expression* var);
void print_array_expression(is_expression* var);
void print_op3_expression(is_expression* var);
void print_array_expression2(is_expression* var);
void print_not_expression(is_expression* var);
void print_new_expression(is_expression* var);
void print_aux_value(char* value);
void print_opt_args(is_opt_args* args);
void print_opt_args_list(is_opt_args_list* list);

void show_program(is_root* list){
    /*printf("inside show program\n");*/
    
    if (list == NULL) {
        return;
    }
    
	printf("Program\n");
    print_program(list->program);
    
}

void print_program(is_program* program) {
    indentation++;
    indent();
    
    if(!program->ident) {
        printf("Null\n");
    } else {
        printf("Id(%s)\n",program->ident);
    }
    
    
    is_field_or_method* node = program->field_or_method;
    
    while(node) {
        switch(node->type)
        {
            case d_field_declaration:
                
                print_field_declaration(node);
                
                break;
            case d_method_declaration:
                
                /*indentation++;*/
                
                print_method_declaration(node);
                
                indentation--;
                break;
        }
        node = node->next;
    }
}


void print_method_declaration(is_field_or_method* var) {
    
    indent();

    printf("MethodDecl\n");
    
    
    if(var->method->function_type->type_specifier) {
        indentation++;indent();
		print_type(var->method->function_type->type_specifier);
	} else {
        indentation++;indent();
		printf("Void\n");
	}
    
    indent();
    printf("Id(%s)\n",var->method->id);
    
    /* if we have formal params */
    indent();
    printf("MethodParams\n");
    if(var->method->opt_formal_params->formal_params) {
        print_formal_params(var->method->opt_formal_params->formal_params);
    }
    
    /* method body */
    indent();
    printf("MethodBody\n");
    while(var->method->opt_var_decl->varDecl) {
        print_opt_var_decl(var->method->opt_var_decl);
        var->method->opt_var_decl = var->method->opt_var_decl->next;
    }
    
    if(var->method->opt_statement->statement) {
        indentation++;
        print_opt_statements(var->method->opt_statement);
    }
    
    
}

void print_opt_statements(is_opt_statement* var) {
    while(var->statement) {
        print_statements(var->statement);
        var = var->next;
    }
}


void print_opt_args(is_opt_args* args) {
    if(args->args->expr) {
        print_expression(args->args->expr);
    }

    if(args->args->list) {
        print_opt_args_list(args->args->list);
    }
}

void print_opt_args_list(is_opt_args_list* list) {
    
    while(list->expr) {
        indent();
        print_expression(list->expr);
        list = list->next;
    }
}

void print_expression(is_expression* var) {
    
    
    if(var->array_dim) {
        if(var->array_dim->dim_type->type == is_dot_length) {
            
            printf("Length\n");
            indentation++;indent();
            print_expression(var->array_dim->expr);
            
            indentation--;
        }
        else if(var->array_dim->dim_type->type == is_parse_int) {
            
            printf("ParseArgs\n");
            indentation++;indent();
            printf("Id(%s)\n", var->array_dim->id);
            indent();
            print_expression(var->array_dim->expr);
            
            indentation--;
        }
        else if(var->array_dim->dim_type->type == is_func_call) {
            
            printf("Call\n");
            indentation++;indent();
            printf("Id(%s)\n", var->array_dim->id);
            indent();
            
            if(var->array_dim->opt_args->args) {
                print_opt_args(var->array_dim->opt_args);
            }
            
            indentation--;
        }
    }
    
    
    
    switch (var->expr_type) {
        case op_expr:
            print_op_expression(var);
            break;
        case array_expr:
            print_array_expression(var);
            break;
        case op3_expr:
            print_op3_expression(var);
            break;
        case array_expr2:
            print_array_expression2(var);
            break;
        case not_expr:
            print_not_expression(var);
            break;
        case new_expr:
            print_new_expression(var);
            break;
        default:
            break;
    }
}


void print_op_expression(is_expression* var) {
    print_aux_value(var->auxvalue);
    indentation++;
    
    indent();
    print_expression(var->expression1);
    indent();
    print_expression(var->expression2);
    
    indentation--;
}

void print_array_expression(is_expression* var) {
    print_aux_value(var->auxvalue);
    printf("LoadArray\n");
    indentation++;indent();
    
    if(var->array_dim->id) {
        printf("Id(%s)\n", var->array_dim->id);
    } else {
        print_expression(var->array_dim->expr);
    }
    
    indent();
    
    
    /*if(var->expression1->array_dim->value) {
        printf("IntLit(%s)\n", var->expression1->array_dim->value);
    } else {
        print_expression(var->expression1);
    }*/
    if(var->expression1)
        print_expression(var->expression1);
    
    indentation--;
}

void print_op3_expression(is_expression* var) {
    
    if(strcmp(var->auxvalue, "-") == 0) {
        printf("Minus\n");
        indentation++;indent();
    
        print_expression(var->expression1);
        
        indentation--;
        
    } else if (strcmp(var->auxvalue, "+") == 0) {
        printf("Plus\n");
        indentation++;indent();
        
        print_expression(var->expression1);

        indentation--;

    }
}

void print_array_expression2(is_expression* var) {
    
    if(var->array_dim->dim_type->type == is_id) {
        printf("Id(%s)\n", var->array_dim->id);
    
    } else if(var->array_dim->dim_type->type == is_int) {
        printf("IntLit(%s)\n", var->array_dim->value);
    
    } else if(var->array_dim->dim_type->type == is_bool) {
        printf("BoolLit(%s)\n", var->array_dim->value);
    
    } else if(var->array_dim->dim_type->type == is_equality) {
        print_expression(var->array_dim->expr);
    }
    
}

void print_not_expression(is_expression* var) {
    print_aux_value(var->auxvalue);
    
    if(var->expression1) {
        indentation++;indent();
        print_expression(var->expression1);
        indentation--;
    } else {
        printf("Null\n");
    }
    
    /*
    if(var->expression1) {
        print_expression(var->expression1);
    }
    */
}

void print_new_expression(is_expression* var) {
    if(var->type->type == is_int){
        printf("NewInt\n");
        indentation++;indent();
        
        /* 
         *
         * a expressao é NEW var_type OSQUARE Expr CSQUARE
         * precisamos de aceder a expr filha para aceder ao value
         *
         */
        printf("IntLit(%s)\n", var->expression1->array_dim->value);
        
        indentation--;
    } else if(var->type->type == is_bool) {
        printf("NewBool\n");
        indentation++;indent();
        printf("BoolLit(%s)\n", var->expression1->array_dim->value);
        indentation--;
    }
    
    /* @TODO PRINT INTARRAY BOOLARRAY */
    
}

void print_aux_value(char* value) {
    
    if(value != NULL) {
        
        if(strcmp("==", value) == 0) {
            printf("Eq\n");
        } else if(strcmp("||", value) == 0) {
            printf("Or\n");
        } else if(strcmp("&&", value) == 0) {
            printf("And\n");
        } else if(strcmp("!=", value) == 0) {
            printf("Neq\n");
        } else if(strcmp("<", value) == 0) {
            printf("Lt\n");
        } else if(strcmp(">", value) == 0) {
            printf("Gt\n");
        } else if(strcmp("<=", value) == 0) {
            printf("Leq\n");
        } else if(strcmp(">=", value) == 0) {
            printf("Geq\n");
        } else if(strcmp("+", value) == 0) {
            printf("Add\n");
        } else if(strcmp("-", value) == 0) {
            printf("Sub\n");
        } else if(strcmp("*", value) == 0) {
            printf("Mul\n");
        } else if(strcmp("/", value) == 0) {
            printf("Div\n");
        } else if(strcmp("!", value) == 0) {
            printf("Not\n");
        } else if(strcmp("%", value) == 0) {
            printf("Mod\n");
        }
    }
}


void print_statements(is_statement* var) {
    
    
        switch (var->type) {
            
            case compound_stm:
            
                /*printf("CompoundStat\n");*/
                break;
            
            case if_stm:
                
                indent();
                
                printf("IfElse\n");
                
                indentation++;indent();
                
                if(var->expression) {
                    print_expression(var->expression);
                } else {
                    printf("Null\n");
                }
                
                if(var->statement1) {
                    print_statements(var->statement1);
                } else {
                    indent();
                    printf("Null\n");
                }
                
                if(var->statement2) {
                    print_statements(var->statement1);
                } else {
                    indent();
                    printf("Null\n");
                }
                
                indentation--;
                
                break;
            
            case else_stm:
                
                indent();
                printf("IfElse\n");
                
                indentation++;indent();
                
                if(var->expression) {
                    print_expression(var->expression);
                } else {
                    printf("Null\n");
                }
                
                if(var->statement1->type) {
                    print_statements(var->statement1);
                } else {
                    printf("Null\n");
                }
                
                if(var->statement2->type) {
                    print_statements(var->statement2);
                } else {
                    printf("Null\n");
                }
                
                indentation--;
                
                break;
            
            case print_stm:
                
                indent();
                
                printf("Print\n");
                
                indentation++;
                
                if(var->expression) {
                    indent();print_expression(var->expression);
                } else {
                    printf("Null\n");
                }
                
                indentation--;
                break;
            
            case return_stm:
                
                indent();
                printf("Return\n");
                
                if(var->opt_expr) {
                    indentation++;
                    indent();
                    print_expression(var->opt_expr->expression);
                    indentation--;
                }
                
                break;
            
            case store_stm:
            
                indent();
                
                if(var->opt_array_pos->expression) {
                    
                    printf("StoreArray\n");
                    indentation++;indent();
                    printf("Id(%s)\n", var->id);

                    if(var->opt_array_pos->expression) {
                        indent();print_expression(var->opt_array_pos->expression);
                    } else {
                        printf("Null\n");
                    }
                    
                    /* PARSE ARGS OR INTLIT OR EXPR */
                    
                    if(var->expression->array_dim) {
                        if(var->expression->array_dim->id) {
                            indent();
                            printf("ParseArgs\n");
                            
                            indentation++;indent();
                            printf("Id(%s)\n", var->expression->array_dim->id);
                            
                            indent();
                            printf("IntLit(%s)\n", var->expression->array_dim->expr->array_dim->value);
                            indentation--;
                        } else if(var->expression->array_dim->value) {
                            indent();
                            printf("IntLit(%s)\n", var->expression->array_dim->value);
                            indentation--;
                        }
                    } else if(var->expression) {
                        indent();
                        print_expression(var->expression);
                    }
                    
                    
                    indentation--;
                } else {
                    
                    printf("Store\n");
                    indentation++;indent();
                    printf("Id(%s)\n", var->id);
                    
                    
                    if(var->expression) {
                        indent(); print_expression(var->expression);
                    } else {
                        printf("Null\n");
                    }

                    indentation--;
                }
                break;
            case while_stm:
                indent();
                printf("While\n");
                
                indentation++;indent();
                
                if(var->expression) {
                    print_expression(var->expression);
                } else {
                    printf("Null\n");
                }
                
                if(var->statement1) {
                    print_statements(var->statement1);
                } else {
                    indent();
                    printf("Null\n");
                }
                
                indentation--;
                
                break;
            default:
                break;
        }
    
    /* coumpound stat */
    
    if(var->opt_statement) {
        print_opt_statements(var->opt_statement);
    }

}


void print_opt_var_decl(is_opt_var_decl* var) {
    indentation++;indent();
    printf("VarDecl\n");
    indentation++;indent();
    
    /* print the type */
    print_type(var->varDecl->type_specifier);
    indent();
    printf("Id(%s)\n", var->varDecl->ident);
    
    /* if we have opt vars like int 1,2,3 print them */
    if(var->varDecl->opt_vars->ident) {
        while(var->varDecl->opt_vars->ident) {
            indent();
			printf("Id(%s)\n", var->varDecl->opt_vars->ident);
            var->varDecl->opt_vars = var->varDecl->opt_vars->next;
        }
    }
    indentation-=2;
}

void print_formal_params(is_formal_params* var) {

    indentation++;indent();
    
    if(var->type_specifier) {
        printf("ParamDeclaration\n");
        indentation++;indent();
        
        print_type(var->type_specifier);
        indent();
		printf("Id(%s)\n", var->id);
        
        /* if we have a list */
        if(var->list->id) {
            print_formal_params_list(var->list);
        }
        
        indentation--;
        
    } else {
        printf("ParamDeclaration\n");
        indentation++;indent();
        
        printf("StringArray\n");
        indent();
		printf("Id(%s)\n", var->id);
        indentation--;
    }
    indentation--;
    
}

void print_formal_params_list(is_formal_params_list* var) {
    /* @TODO if we have more params */
    while(var->id) {
        indentation--;indent();
        printf("ParamDeclaration\n");
        indentation++;indent();
        
        print_type(var->type_specifier);
        
        indent();
        
        printf("Id(%s)\n", var->id);
        var = var->next;
    }
    
}

void print_field_declaration(is_field_or_method* var) {
    indent();
    
    printf("VarDecl\n");
    
    indentation++;indent();
    
    print_type(var->field->varDecl->type_specifier);
    
    indent();
    
    if(!var->field->varDecl->ident) {
        printf("Null\n");
    } else {
        printf("Id(%s)\n", var->field->varDecl->ident);
    }
    
    if(var->field->varDecl->opt_vars->ident != NULL) {
        while(var->field->varDecl->opt_vars->ident) {
            indent();
            
            printf("Id(%s)\n", var->field->varDecl->opt_vars->ident);
            
            var->field->varDecl->opt_vars = var->field->varDecl->opt_vars->next;
        }
    }
    indentation--;
}

void print_type(is_type_specifier* type) {
    if (!type) {
        printf("Null\n");
        return;
    }
    
    switch(type->var_type->type) {
        case is_int:
            printf("Int");
            break;
        case is_bool:
            printf("Bool");
            break;
        case is_id:
            break;
        case is_equality:
            break;
        case is_dot_length:
            break;
        case is_parse_int:
            break;
        case is_func_call:
            break;
    }
    if(type->opt_array->array == is_array) {
        printf("Array");
    }
    printf("\n");
}

void indent() {
    int i;
    for(i = 0;i < indentation; i++) printf("  ");
}



















