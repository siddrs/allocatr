#ifndef ALLOCATR_H
#define ALLOCATR_H

#include "types.h"

#define MAGIC 123456789

Node *heap_init(unsigned int heap_size);

void *pls_allocate(unsigned int request_size);

void pls_free(void *ptr);

#endif
