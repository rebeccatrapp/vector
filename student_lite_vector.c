#include "lite_vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

lite_vector* lv_new_vec(size_t type_size){
	lite_vector * l = malloc(sizeof l);
	l->data = malloc(sizeof (void*) * l->max_capacity);
	l->max_capacity = 10;
	l->length = 0;
	l->type_size = type_size;
	return l;

}

void lv_cleanup(lite_vector* vec){
	lv_clear(vec);
	free(vec);
}

size_t lv_get_length(lite_vector* vec){
	size_t length = vec->length;
	return length;
}

bool lv_clear(lite_vector* vec){
	vec = lv_new_vec(vec->type_size);
	if(vec == NULL){
	       return false;
	} else return true;	
}

void* lv_get(lite_vector* vec, size_t index){
	return vec->data[index];
}

static bool lv_resize(lite_vector* vec){
	lite_vector * doodoo = malloc(sizeof(void*) * vec->max_capacity+10);
	memcpy(doodoo, vec->data, sizeof(void*) * vec->max_capacity+10);
	memcpy(vec->data, doodoo, sizeof(void*) * vec->max_capacity+10);	
	vec->max_capacity += 10;
	return true;
}

bool lv_append(lite_vector* vec, void* element){
	for(int i = 0; i < vec->max_capacity; i++){
		if(i == vec->max_capacity-1){
			lv_resize(vec);
		}
		if(vec->data[i] != NULL){
			return false;
		} else{
			vec->data[i] = element;
			return true;
		}
	}
		
}
