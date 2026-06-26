#ifndef FREELIST_H
#define FREELIST_H

#include "types.h"

void print_node(Node *node);

void print_all_nodes(Node *head);

void coalesce();

AllocHeader *split(Node *head, Node *hole, unsigned int request_size);

void traverse();

#endif

