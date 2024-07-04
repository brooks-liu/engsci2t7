//q1 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lab06.h"

/*typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;*/

// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem){
    int size = my_list->size;
    node* new = (node*)malloc(sizeof(node));
    new->data = new_elem;
    new->next = NULL;
    if(my_list->head == NULL){
        my_list->head = new;
    }
    else{
        node* cur = my_list->head;
        for(int i = 0; i < size - 1; i++){
            cur = cur->next;
        }
        cur->next = new;
    }
    my_list->size++;
}

//q2

int validate_list_length(LL* list){
    int counter = 0;
    node* cur = list->head;
    counter++;
    //check if head is null
    while(cur->next != NULL){
        cur = cur->next;
        counter++;
    }
    if(counter == list->size){
        return 1;
    }
    return 0;
}

//q3
void delete_node(node* head, int index){
    node* cur = head;
    for(int i = 0; i < index - 1; i++){
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

void create_LL(node** p_head, int* data, int size){
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node* cur = (node*)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for(int i = 1; i < size; i++){
        cur->next = (node*)malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }
    cur->next = NULL;  // this is catching when it ends
}

void print_LL(node* head){
    while(head != NULL){
        printf("%d ->", head->data);
        head = head->next; //puts it to the next node
    }
    printf("\n");
}

/*int main(){
    node* head = (node*)malloc(sizeof(node));
    int list[5] = {1, 2, 3, 4, 5};
    create_LL(&head, list, 5);
    print_LL(head);
    LL linkedlist;
    linkedlist.head = head;
    linkedlist.size = 5;
    LL_append(&linkedlist, 6);
    print_LL(head);

    printf("%d\n", validate_list_length(&linkedlist));
    linkedlist.size = 3;
    printf("%d\n", validate_list_length(&linkedlist));

    delete_node(head, 5);
    print_LL(head);

}*/