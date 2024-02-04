#include "vector.h"
#include <stdlib.h>
#include <string.h>

void initializeVector(vector *vec, size_t element_size) {
    vec->data = NULL;
    vec->capacity = 0;
    vec->size = 0;
    vec->element_size = sizeof(void **);
}

void resizeVector(vector *vec, size_t new_capacity) {
    vec->data = realloc(vec->data, new_capacity * vec->element_size);
    vec->capacity = new_capacity;
}

void push_back(vector *vec, void *element) {
    if (vec->size == vec->capacity) {
        resizeVector(vec, ((vec->capacity == 0) ? 1 : (2 * vec->capacity)));
    }

    // char **destination = (char **)vec->data + vec->size * vec->element_size;
    // memcpy(destination, &element, vec->element_size);
    vec->data[vec->size] = element;

    vec->size++;
}

void insert_into(vector *vec, void *element, size_t ix) {
    if (ix >= vec->capacity) return ;

    vec->data[ix] = element;
    if (ix == vec->size) vec->size++;
}

void *list_get(vector *vec, size_t index) {
    if (index >= vec->size) return NULL;

    // char **address = (char **) vec->data + index * vec->element_size;

    // return (void **)address;
    return vec->data[index];
}

void free_vec(vector *vec) {
    free(vec->data);
}