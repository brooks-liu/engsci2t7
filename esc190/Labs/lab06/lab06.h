#if !defined(LAB06_H)
#define LAB06_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem);
void create_LL(node** p_head, int* data, int size);
void print_LL(node* head);
int validate_list_length(LL* list);
void delete_node(node* head, int index);

#endif