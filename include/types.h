#ifndef TYPES_H
#define TYPES_H

// For ze free list
typedef struct Node {
    struct Node *next;
    unsigned int free_size;  // size of the actual free space excluding the Node metadata
} Node;


// Header for the allocated blocks
typedef struct AllocHeader {
    int magic;
    int size;
    int in_use;
} AllocHeader;

#endif

