#include <iostream>
#include "freelist.h"
#include "allocatr.h"

// TODO: free_size isn't being updated 
// Also right now, new nodes aren't being created. Think it through

void print_node(Node *node) {
    std::cout << "Node at " << node << " | Next node at " << node->next << " | Free Space (B): " << node->free_size << std::endl;
}

void print_all_nodes(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        print_node(curr);
        curr = curr->next;
    }
}

Node *traverse(unsigned int request_size) {
    Node *node = head;
    Node *hole = nullptr;
    bool found = false;

    while (node) {
        if (node->free_size + sizeof(Node) >= request_size + sizeof(AllocHeader)) {
            hole = node;
            found = true;

            std::cout << node->free_size + sizeof(Node) << " and " << request_size + sizeof(AllocHeader) << std::endl;

            break;
        }
        node = node->next;
    }

    if (found) {
        std::cout << "Found!" << std::endl;
        return hole;
    }
    return nullptr;
}

// 'hole' would be made into an allocated block after adding the Header, which would then be returned to the user; if this is making any sense at all

AllocHeader *split(Node *hole, unsigned int request_size) { 
    
    void *next_node_addr = nullptr;

    if (hole == head) {
        // starting address of the allocated block is same the head's address    
        // move the head forward by request_size + Header Size
        head = (Node *)((char *)head + (request_size + sizeof(AllocHeader)));
        next_node_addr = head;
    }
    else {
        // find the node with node->next equal to the address of the allocated block's address
        Node *node = head;
        while (node->next != hole) {
            node = node->next;
        }
        node->next = (Node *)((char *)node->next + (request_size + sizeof(AllocHeader)));
        next_node_addr = node->next;
    }

    AllocHeader *block = (AllocHeader *)hole;
    block->size = (char *)next_node_addr - (char *)block;
    block->in_use = 0;
    block->magic = MAGIC;

    return block;
}

