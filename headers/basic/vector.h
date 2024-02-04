#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector {
    void **data;
    size_t size;
    size_t capacity;
    size_t element_size;
};

typedef struct vector vector;

void initializeVector(vector *vec, size_t element_size);

void resizeVector(vector *vec, size_t new_capacity);

void push_back(vector *vec, void *element);

void insert_into(vector *vec, void *element, size_t ix);

void *list_get(vector *vec, size_t index);

void free_vec(vector *vec);

#endif