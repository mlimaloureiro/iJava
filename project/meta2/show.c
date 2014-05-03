#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int identation = 0;

void show_program(is_start_list* list){
    printf("AQUI ESTOU EU\n");
    
    if (list == NULL) {
        return;
    }
    
	printf("Program\n");
    identation+=2;
    is_start_list* element;
    
    for(element = list; element != NULL; element = element->next){
        printf("%s\n",element->program->ident);
    }
}