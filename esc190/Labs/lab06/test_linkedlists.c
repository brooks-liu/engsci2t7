#include "lab06.h"


int main(){
    node* head = (node*)malloc(sizeof(node));
    int list[5] = {1, 2, 3, 4, 5};
    create_LL(&head, list, 5);
    print_LL(head);
    LL linkedlist;
    linkedlist.head = head;
    linkedlist.size = 5;
    LL_append(&linkedlist, 6);
    print_LL(head);



}