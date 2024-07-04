#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void create_LL(node **p_head, int *data, int size)
{
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node *cur = (node *)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for(int i = 1; i < size; i++){
        cur->next = (node *)malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }
    cur->next = NULL;
}

void print_LL(node *head)
{
    // head is always the (address of) node we're currently printing
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
}

void insert_LL(node **p_head, int ind, int num)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = num;
    // insert num at index ind
    if(ind == 0){
        new->next = *p_head;
        *p_head = new;
    }
    else{
        // go through the linked list until node i-1
        // insert the new node after i-1
        node *cur = *p_head;
        for(int i = 0; i < ind - 1; i++){
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }

}



int main()
{
    // create a simple linked list
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;

    node *n2 = (node *)malloc(sizeof(node));
    n2->data = 5;
    head->next = n2;

    // insert a value between 1 and 5
    node *n10 = (node *)malloc(sizeof(node));
    head->next = n10;
    n10->next = n2;

    // want to insert the value 10 between 1 and 5

    node a;
    a.data = 123;
    // free(&a); // would crash
    // free(a); // would not compile: a is not a pointer
    free(head);
    free(n2);
}

