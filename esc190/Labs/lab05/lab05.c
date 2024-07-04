#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "intlist.h"

//q1a
//memcpy is not good because it might write into unallocated memory causing errors

//q1b see other

//q1c - running using tasks.json

//q1d debugging

//q2 cannot do at the same time because have the same function names and they do different things

int main(){
    int data[4] = {1, 2, 3, 4};
    IntList* block;
    create_list_from_data(&block, data, 4);
    list_append(block, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d \n", block->data[i]);
    } 
    list_insert(block, 6, 3);
    for(int i = 0; i < 6; i++) {
        printf("%d \n", block->data[i]);
    } 

    list_delete(block, 3);
    for(int i = 0; i < 5; i++) {
        printf("%d \n", block->data[i]);
    } 

    list_destroy(block);

    return 0;
}