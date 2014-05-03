#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int identation = 0;

void show_program(is_program* list){
    /*printf("inside show program\n");*/
    
    if (list == NULL) {
        return;
    }
    
	printf("Program\n");
    identation+=2;
    is_program* element;
    
    for(element = list; element != NULL; element = element->next){
        print_program(element);
    }
}

void print_program(is_program* program) {
    int i;
    for(i=0;i<identation;i++) printf(" ");
    printf("ID(%s)\n",program->ident);
}