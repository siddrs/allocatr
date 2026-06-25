#include <sys/mman.h>
#include "allocatr.h"
#include "freelist.h"

Node *heap_init(unsigned int heap_size) {
    Node *node = (Node *) mmap(0, heap_size, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    node->next = nullptr;
    node->size = heap_size - sizeof(Node);
    
    return node;
}


