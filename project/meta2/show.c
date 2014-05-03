#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int identation = 0;

void print_field_declaration(is_field_or_method* var);
void print_type(is_type_specifier* type);

void show_program(is_root* list){
    /*printf("inside show program\n");*/
    
    if (list == NULL) {
        return;
    }
    
	printf("Program\n");
    identation+=2;
    print_program(list->program);
    
}

void print_program(is_program* program) {
    int i;
    for(i = 0;i < identation; i++) printf(" ");
    printf("ID(%s)\n",program->ident);
    
    is_field_or_method* node = program->field_or_method;
    
    while(node) {
        switch(node->type)
        {
            case d_field_declaration:
                print_field_declaration(node);
                break;
            case d_method_declaration:
                printf("WE HAVE A METHOD DECLARATION\n");
                break;
        }
        node = node->next;
    }
}

void print_field_declaration(is_field_or_method* var) {
        print_type(var->field->varDecl->type_specifier);
        printf("ID(%s)\n", var->field->varDecl->ident);
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




