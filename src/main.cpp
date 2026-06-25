#include "allocatr.h"
#include "freelist.h"

int main() {
    Node *head = heap_init(4096);
    print_node(head);

    return 0;
}
