#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int identation = 0;

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
                printf("WE HAVE A FIELD DECLARATION\n");
                
                break;
            case d_method_declaration:
                printf("WE HAVE A METHOD DECLARATION\n");
                
                break;
        }
        node = node->next;
    }
}




