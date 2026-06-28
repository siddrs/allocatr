#include <iostream>
#include "allocatr.h"
#include "freelist.h"

Node *head;

int main() {
    head = heap_init(4096);
    print_node(head);

    void *ptr = pls_allocate(300);
    std::cout << "User Pointer: " << ptr << std::endl;
    print_node(head);

    void *ptr2 = pls_allocate(400); // well shit

    return 0;
}
