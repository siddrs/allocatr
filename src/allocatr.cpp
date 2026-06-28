#include <iostream>
#include <sys/mman.h>

#include "allocatr.h"
#include "freelist.h"
#include "types.h"

Node *heap_init(unsigned int heap_size) {
    Node *node = (Node *) mmap(0, heap_size,
                               PROT_WRITE | PROT_READ,
                               MAP_PRIVATE | MAP_ANONYMOUS,
                               -1, 0);
    node->next = nullptr;
    node->free_size = heap_size - sizeof(Node);
 
    return node;
}


void *pls_allocate(unsigned int request_size) {
    Node *hole = traverse(request_size);
    AllocHeader *block = split(hole, request_size);
    block->in_use = 1;
    void *user_ptr = (void *)((char *)block + sizeof(AllocHeader));

    std::cout << "Allocated " << block->size << " bytes." << std::endl;
    return user_ptr;
}

