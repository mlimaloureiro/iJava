#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>


is_start_list* insert_start_list(is_program* program, is_start_list* list) {
    /**
     *
     * bullshit
     *
     */
    
    is_start_list* new = (is_start_list*)malloc(sizeof(is_start_list));
    new->program = program;
    new->next = NULL;
    
    if(list->next == NULL) {
        return new;
    }
    is_start_list* last_element;
    for(last_element=list; last_element->next != NULL; last_element = last_element->next);
    
    last_element->next = new;
    
    return list;
}

is_program* insert_program(char* ident, is_field_or_method* field_or_method) {
    is_program* new = (is_program*)malloc(sizeof(is_program));
    new->field_or_method = field_or_method;
    new->ident = ident;
    new->next = NULL;
    
    /*printf("inserted program %s\n", ident);*/
    return new;
}

is_field_or_method* insert_field_or_method(is_field_declaration* field, is_method_declaration* method, is_field_or_method* field_or_method_to_insert) {
    printf("in insert field or method\n");

    is_field_or_method* new = (is_field_or_method*) malloc(sizeof(is_field_or_method));
    
    if(method != NULL) {
        printf("last element is a method\n");
        new->type = d_method_declaration;
    } else if(field != NULL) {
        printf("last element is a field\n");
        new->type = d_field_declaration;
    }
    
    new->next = field_or_method_to_insert;
    new->element.field = (struct is_field_declaration*) field;
    new->element.method = (struct is_method_declaration*) method;
    
    return field_or_method_to_insert;
}

