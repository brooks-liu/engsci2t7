//midterm: look at last years midterm - a little more difficult than this years
// like 2023 but with shorter questions (short questions like 2012-2013) - review 2021 ad 2023
// do the labs and project from scratch
// will be python but only to the extend covered


/*topics:
syntax from C, functions, conditionals, loops
structs, pointers
#define, #include, #if/#endif
*/

//linked lists:
//are a way to store lists without preallocating large blocks of memory
//  A->B->C
// to insert, make B point to something else, and point back to C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;  //must say struct node because haven't gotten to the end "node" in the next line yet
}node;

int main(){
    //simple list
    node* head = (node*)malloc(sizeof(node));
    head->data = 1;
    node* n2 = (node*)malloc(sizeof(node));
    n2->data = 5;
    head->next = n2;

    // insert between head and n2
    node* n1 = (node*)malloc(sizeof(node));
    n1->data = 10;
    head->next = n1;
    n1->next = n2;

    free(head);
    free(n2);

    return 0;
}

void create_LL(node** p_head, int* data, int size){
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node* cur = (node*)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for(int i = 0; i < size; i++){
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
}

void insert_LL(node** phead, int index, int number){
    //what if index is 0??
    node* new = (node*)malloc(sizeof(node));
    new->data = number;
    if(index == 0){
        new->next = *phead;
        *phead = new;
    }
    else{
        //go through until i-1, insert after i-1
        node* cur = *phead;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }
}

void delete_values(node* head, int value, int size){
    node* current = head;
    if(head == NULL){
        printf("Linked list is size 0\n");
    }
    for(int i = 0; i < size; i++){
        if(current->next == NULL){
            printf("End of list");
            break;
        }
        if(current->next->data != value){
            current = current->next;
            i++;
        }
        else{
            current->next = (current->next)->next;
            current->data = (current->next)->data;
            free(current->next);
            current = current->next;
            i++;
        }

    }
}