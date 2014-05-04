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

void print_type(is_type_specifier* type);

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
    
    printf("ID(%s)\n",program->ident);
    
    is_field_or_method* node = program->field_or_method;
    
    while(node) {
        switch(node->type)
        {
            case d_field_declaration:
                
                indentation++;
                
                print_field_declaration(node);
                
                indentation--;
                break;
            case d_method_declaration:
                
                indentation++;
                
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
    printf("ID(%s)\n",var->method->id);
    
    if(var->method->opt_formal_params->formal_params) {
        print_formal_params(var->method->opt_formal_params->formal_params);
    }
}

void print_formal_params(is_formal_params* var) {
    indent();
    printf("MethodParams\n");
    indentation++;indent();
    
    
    if(var->type_specifier) {
        printf("ParamDeclaration\n");
        indentation++;indent();
        
        print_type(var->type_specifier);
        indent();
		printf("Id(%s)\n", var->id);
        
    } else {
        printf("ParamDeclaration\n");
        indentation++;indent();
        
        printf("StringArray\n");
        indent();
		printf("Id(%s)\n", var->id);
    }
    
}

void print_formal_params_list(is_formal_params_list* var) {
    /* if we have more params */
    
}

void print_field_declaration(is_field_or_method* var) {
    indent();

    printf("FieldDecl\n");
    
    indentation++;indent();
    print_type(var->field->varDecl->type_specifier);
    /*indentation--;indent();*/
    
    indentation++;indent();
    printf("ID(%s)\n", var->field->varDecl->ident);
    
    if(var->field->varDecl->opt_vars->ident != NULL) {
        while(var->field->varDecl->opt_vars->ident) {
            indent();
            printf("ID(%s)\n", var->field->varDecl->opt_vars->ident);
            var->field->varDecl->opt_vars = var->field->varDecl->opt_vars->next;
        }
    }
    indentation-=2;
}

void print_type(is_type_specifier* type) {
    switch(type->var_type->type) {
        case is_int:
            printf("INT\n");
            break;
        case is_bool:
            printf("BOOL\n");
            break;
    }
}

void indent() {
    int i;
    for(i = 0;i < indentation; i++) printf("  ");
}




