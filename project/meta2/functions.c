#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>


is_start_list* insert_start_list_field_declaration( is_start_list* list, is_field_declaration* to_insert) {

    is_start_list* new_element = (is_start_list*)malloc( sizeof(is_start_list));
    new_element->element_type=d_field_declaration;
    new_element->element.field_declaration=(struct is_field_declaration*) to_insert;
    new_element->next = NULL;
    if(list==NULL)
        return new_element;
    is_start_list* last_element;
    for(last_element=list; last_element->next != NULL; last_element = last_element->next);

    last_element->next = new_element;

    return list;
}

