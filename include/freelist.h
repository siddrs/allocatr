#ifndef FREELIST_H
#define FREELIST_H

typedef struct Node {
    struct Node *next;
    unsigned int size;  // size of the actual free space excluding the Node metadata
} Node;

void print_node(Node *node);

void coalesce();

void split();

void traverse();

#endif

