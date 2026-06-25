#ifndef ALLOCATR_H
#define ALLOCATR_H

#include "freelist.h"

typedef struct Header {
    int magic;
    int size;
    int allocated;
} Header;


Node *heap_init(unsigned int heap_size);

void *pls_allocate(unsigned int request);

void pls_free(void *ptr);

#endif
