// TODO: structure codebase

#include <iostream>
#include <sys/mman.h>

#define PAGESIZE 4096
#define MAGIC 123456789

// Header for allocated blocks
typedef struct Header {
    int magic;
    unsigned int size;  // size of the allocated region returned to the user
} Header;


// FREE LIST STUFF ---------------------------------------

// For the free list
typedef struct Node {
    struct Node *next;  // Holds the address of the next node in the freelist
    unsigned int size;   // Size of the free block (excluding the metadata -> len = actual size - sizeof(Node))
} Node;

// utility functions for freelist
void print_node_info(struct Node *node) {
    std::cout << node << " | Next Node at " << node->next << " | Free Space (B): " << node->size << std::endl;
}

// ---------------------------------------

Node *heap_init(unsigned int heap_size) {
    Node *node = (Node *) mmap(0, heap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    node->size = heap_size - sizeof(Node);
    node->next = nullptr;

    return node;
}

void *pls_alloc(unsigned int request_size) {
    // this should call a bunch of functions: traverse(), split()
    return nullptr; // for now
}

void pls_free(void *ptr) {
    // after every pls_free call, we should try to coalesce()
}

int main() {
    Node *head = heap_init(PAGESIZE);

    print_node_info(head);

    return 0;
}
