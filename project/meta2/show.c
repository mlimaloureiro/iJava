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

void print_op_expression(is_expression* var);
void print_array_expression(is_expression* var);
void print_op3_expression(is_expression* var);
void print_array_expression2(is_expression* var);
void print_not_expression(is_expression* var);
void print_new_expression(is_expression* var);
void print_aux_value(char* value);

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
    if(var->method->opt_var_decl->varDecl) {
        print_opt_var_decl(var->method->opt_var_decl);
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


void print_expression(is_expression* var) {
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
    
}

void print_array_expression(is_expression* var) {
    printf("array exp\n");
}

void print_op3_expression(is_expression* var) {
    printf("op3 exp\n");
}

void print_array_expression2(is_expression* var) {
    printf("array2 exp\n");
}

void print_not_expression(is_expression* var) {
    printf("not exp\n");
}

void print_new_expression(is_expression* var) {
    printf("new exp\n");

    
}

void print_aux_value(char* value) {
    if(strcmp("==", value) == 0) {
        printf("Eq");
    } else if(strcmp("||", value) == 0) {
        printf("Or");
    } else if(strcmp("&&", value) == 0) {
        printf("And");
    } else if(strcmp("!=", value) == 0) {
        printf("Neq");
    } else if(strcmp("<", value) == 0) {
        printf("Lt");
    } else if(strcmp(">", value) == 0) {
        printf("Gt");
    } else if(strcmp("<=", value) == 0) {
        printf("Leq");
    } else if(strcmp(">=", value) == 0) {
        printf("Geq");
    } else if(strcmp("+", value) == 0) {
        printf("Add");
    } else if(strcmp("-", value) == 0) {
        printf("Sub");
    } else if(strcmp("*", value) == 0) {
        printf("Mul");
    } else if(strcmp("/", value) == 0) {
        printf("Div");
    } else if(strcmp("!", value) == 0) {
        printf("Not");
    } else if(strcmp("%", value) == 0) {
        printf("Mod");
    }
    
    printf("\n");
}


void print_statements(is_statement* var) {
    
        indent();
        switch (var->type) {
            case compound_stm:
                printf("\n");
                break;
            case if_stm:
                printf("IfElse\n");
                indentation++;indent();

                if(var->expression) {
                    print_expression(var->expression);
                }
                else { printf("Null\n"); }
                
                if(var->statement1) { print_statements(var->statement1); }
                else { printf("Null\n"); }
                
                indentation--;
                
                break;
            case else_stm:
                printf("IfElse\n");
                indentation++;indent();
                
                if(var->expression) { print_expression(var->expression); }
                else { printf("Null\n"); }
                
                if(var->statement1) { print_statements(var->statement1);}
                else { printf("Null\n"); }
                
                if(var->statement2) { print_statements(var->statement2); }
                else { printf("Null\n"); }
                
                indentation--;
                
                break;
            case print_stm:
                printf("Print\n");
                break;
            case return_stm:
                printf("Return\n");
                break;
            case store_stm:
                if(var->opt_array_pos->expression) {
                    printf("StoreArray\n");
                    indentation++;indent();
                    printf("Id(%s)\n", var->id);
                    
                    if(var->expression) { indent();print_expression(var->expression); }
                    else { printf("Null\n"); }

                    indentation--;
                } else {
                    printf("Store\n");
                    indentation++;indent();
                    printf("Id(%s)\n", var->id);
                    
                    if(var->expression) { indent(); print_expression(var->expression); }
                    else { printf("Null\n"); }

                    indentation--;
                }
                break;
            case while_stm:
                printf("While\n");
                
                indentation++;indent();
                
                if(var->expression) { print_expression(var->expression); }
                else { printf("Null\n");}
                
                if(var->statement1) { print_statements(var->statement1); }
                else { printf("Null\n"); }
                
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



















