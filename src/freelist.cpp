#include <iostream>
#include "freelist.h"

void print_node(Node *node) {
    std::cout << "Node at " << node << " | Next node at " << node->next << " | Free Space (B): " << node->size << std::endl;
}

