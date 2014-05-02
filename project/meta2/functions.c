#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>


is_field_or_method* insert_field_or_method(is_field_declaration* field, is_method_declaration* method, is_field_or_method* field_or_method_to_insert) {

    is_field_or_method* new = (is_field_or_method*) malloc(sizeof(is_field_or_method));
    
    new->method = method;
    new->field = field;
    new->next = field_or_method_to_insert;
    
    if (field_or_method_to_insert == NULL)
        return new;
    
    is_field_or_method* last_element;
    for (last_element = field_or_method_to_insert; last_element->next != NULL; last_element = last_element->next);
    
    last_element->next = new;
    
    return new;
}

