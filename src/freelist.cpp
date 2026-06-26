#include <iostream>
#include "freelist.h"
#include "allocatr.h"

void print_node(Node *node) {
    std::cout << "Node at " << node << " | Next node at " << node->next << " | Free Space (B): " << node->free_size << std::endl;
}

void print_all_nodes(Node *head) {

}

Node *traverse(Node *head, unsigned int request_size) {
    Node *node = head;
    Node *hole = nullptr;
    bool found = false;

    while (node) {
        if (node->free_size + sizeof(Node) >= request_size + sizeof(AllocHeader)) {
            hole = node;
            found = true;
            break;
        }
        node = node->next;
    }

    if (found) {
        return hole;
    }
    return nullptr;
}

// 'hole' would be made into an allocated block after adding the Header, which would then be returned to the user; if this is making any sense at all

AllocHeader *split(Node *head, Node *hole, unsigned int request_size) { 
    if (hole == head) {
        // starting address of the allocated block is same the head's address    
        head = (Node *)((char *)head + (request_size + sizeof(AllocHeader)));
    }
    else {
        // find the node with node->next equal to the address of the allocated block's address
        Node *node = head;
        while (node->next != hole) {
            node = node->next;
        }
        node->next = (Node *)((char *)node->next + (request_size + sizeof(AllocHeader)));
    }

    AllocHeader *block = (AllocHeader *)hole;
    block->size = hole->free_size + sizeof(Node) - sizeof(AllocHeader);
    block->in_use = 0;
    block->magic = MAGIC;

    return block;
}

