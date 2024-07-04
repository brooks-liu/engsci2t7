#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
} node;


typedef struct LL{
    node *head;
    int size;
} LL;


void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

// created a linked list that looks like data[0]->data[1]->data[2]->...->data[size-1]
void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    if(size == 0){
        (*p_LL)->head = NULL;
        return;
    }
    
    node *n;
    create_node(&n, data_arr[0]);
    (*p_LL)->head = n;
    (*p_LL)->size++;

    node *cur = n;
    for(int i = 1; i < size; i++){
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        cur->next = n;
        cur = n;
        (*p_LL)->size++;
    }
}


void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}


void LL_insert(LL *my_list, int new_elem, int index)
{
    node *n;
    create_node(&n, new_elem);
    if(my_list->head == NULL){
        my_list->head = n;
        my_list->size++;
        return;
    }
    if(index == 0){
        n->next = my_list->head;
        my_list->head = n;
        my_list->size++;
        return;
    }
    
    // 1. just crash if index is out of bounds
    // 2. don't crash, don't insert at invalid index, set a global
    // variable to indicate an error
    // 3. print an error message and exit
    if (index < 0 || index > my_list->size-1){
        fprintf(stderr, "Invalid index %d", index);
        exit(1); // exits the program, returns 1 to the OS
    }


    node *cur = my_list->head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
    }
    
    n->next = cur->next;
    cur->next = n;
    my_list->size++;
}

void LL_delete(LL *my_list, int index)
{
    if(index == 0){
        node *temp = my_list->head;
        my_list->head = my_list->head->next;
        free(temp);
        my_list->size--;
        return;
    }
    
    node *cur = my_list->head;
    for(int i = 0; i < index - 1; i++){
        cur = cur->next;
    }
    node *temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
    my_list->size--;
}

void LL_free_all(LL *my_list)
{
    node *cur = my_list->head;
    while(cur != NULL){
        node *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(my_list);
}
//return the element at location index
int LL_get(LL *my_list, int index)
{
    node *cur = my_list->head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
        if(cur == NULL){
            fprintf(stderr, "Index out of bounds\n");
            exit(1);
        }
    }
    return cur->data;
}


void create_list_from_data(void **p_list, int *data_arr, int size)
{
    create_LL_from_data((LL**)p_list, data_arr, size);   
}

void list_append(void *list, int new_elem)
{
    LL_append((LL*)list, new_elem);
}

void list_insert(void *list, int new_elem, int index)
{
    LL_insert((LL*)list, new_elem, index);
}


void list_delete(void *list, int index)
{
    LL_delete((LL*)list, index);
}
void list_free_all(void *list)
{
    LL_free_all((LL*)list);
}

int list_get(void *list, int index)
{
    return LL_get(list, index);
}