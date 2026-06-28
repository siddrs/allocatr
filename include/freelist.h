#ifndef FREELIST_H
#define FREELIST_H

#include "types.h"

void print_node(Node *node); // done

void print_all_nodes(Node *head); // done

void coalesce();

AllocHeader *split(Node *hole, unsigned int request_size); // done

Node *traverse(unsigned int request_size); //done

#endif

