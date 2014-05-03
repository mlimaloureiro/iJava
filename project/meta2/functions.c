#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>


is_root* insert_start_list(is_program* program) {
    /**
     *
     * bullshit
     *
     */
    
    is_root* new = (is_root*)malloc(sizeof(is_root));
    new->program = program;
    return new;
}

is_program* insert_program(char* ident, is_field_or_method* field_or_method) {
    is_program* new = (is_program*)malloc(sizeof(is_program));
    new->field_or_method = field_or_method;
    new->ident = ident;
    new->next = NULL;
    
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
    
    return new;
}

