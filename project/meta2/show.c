#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "show.h"

int identation = 0;

void show_program(is_start_list *list){
    if (list == NULL) {
        return;
    }
    printf("Program\n");
    /*identation+=2;
    is_start_list* list_element;
    for(list_element=list; list_element!=NULL; list_element=list_element->next){
        switch(list_element->element_type)
        {
            case d_method_definition:
                show_function_definition(list_element->element.function_definition);
                break;
            case d_method_declaration:
                show_function_declaration(list_element->element.function_declaration);
                break;
            case d_declaration:
                show_declaration(list_element->element.declaration);
                break;
        }
    }
    identation-=2;
    */
}