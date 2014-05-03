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
    /*printf("in insert field or method\n");*/

    is_field_or_method* new = (is_field_or_method*) malloc(sizeof(is_field_or_method));
    
    if(method != NULL) {
        /*printf("last element is a method\n");*/
        new->type = d_method_declaration;
        new->field = NULL;
        new->method = method;
    } else if(field != NULL) {
        /*printf("last element is a field\n");*/
        new->type = d_field_declaration;
        new->field = field;
        new->method = NULL;
    } else {
        return NULL;
    }
    
    new->next = field_or_method_to_insert;
    
    return new;
}

is_field_declaration* insert_field_declaration(field_declarator* varDecl) {
    is_field_declaration* new = (is_field_declaration*)malloc(sizeof(is_field_declaration));
    new->varDecl = varDecl;
    return new;
}

field_declarator* insert_field_declarator(is_type_specifier* type, char* ident, field_declarator_list* opt_list) {
    field_declarator* new = (field_declarator*)malloc(sizeof(field_declarator));
    new->type_specifier = type;
    new->ident = ident;
    new->opt_vars = opt_list;
    
    /*printf("Inserted field declarator %s\n", ident);*/
    
    return new;
}

field_declarator_list* insert_opt_vars(char* ident, field_declarator_list *next) {;
    field_declarator_list* new = (field_declarator_list*)malloc(sizeof(field_declarator_list));
    new->ident = ident;
    new->next = next;
    /*printf("Inserted field list %s\n", ident);*/
    return new;
}

is_type_specifier* insert_type_specifier(var_type* var_type, is_opt_array* opt_array) {
	is_type_specifier* new = (is_type_specifier*) malloc(sizeof(is_type_specifier));
	new->var_type = var_type;
	new->opt_array = opt_array;
	return new;
}

var_type* insert_type(is_type type) {
	var_type* new = (var_type*) malloc(sizeof(var_type));
    new->type = type;
	return new;
}

is_opt_array* insert_opt_array(opt_array arr) {
	is_opt_array* new = (is_opt_array*) malloc(sizeof(is_opt_array));
	new->array = arr;
	return new;
}


