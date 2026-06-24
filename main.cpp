#include <iostream>
#include <sys/mman.h>

#define PAGESIZE 4096

// Header for allocated blocks
typedef struct header {
    int magic;
} header;


// For the free list
typedef struct Node {
    Node *next;         // Holds the address of the next node in the freelist
    void *ptr;          // Holds the starting address of the free block
    unsigned int len;   // Size of the free block
} Node;



int main() {
    Node freeHead;
    freeHead.ptr = mmap(0, 4 * PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    std::cout << freeHead.ptr << std::endl;

    return 0;
}
