#if !defined(INTLIST2_H)
#define INTLIST2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IntList {
    int *data;
    int size;
    int capacity;
} IntList;



// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    *p_IntList  = (IntList*)malloc(sizeof(IntList));
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size;
    (*p_IntList)->data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        (*p_IntList)->data[i] = data_arr[i];
    }
}  //done

// Append new_elem to the end of list

void list_append(IntList *list, int new_elem){
    if(list->capacity < list->size || list->data == NULL){
        printf("List size exceeded capacity, or list does not exist\n");
        exit(1);
    }
    //-------------------------------------------
    if(list->capacity % 2 >= list->size){
        list->capacity /= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }  
    //-----------------------------------------------
    if(list->capacity == list->size){
        list->capacity += 1;
        list->data = (int*)realloc(list->data, (list->capacity) * sizeof(int)); //doubles it
    }
    list->data[list->size] = new_elem;
    list->size += 1;
} //done



// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(IntList *list, int new_elem, int index){
    if(list->capacity < list->size || list->data == NULL){
        printf("List size exceeded capacity, or list does not exist\n");
        exit(1);
    }  //error catching

    //-------------------------------------------
    if(list->capacity % 2 >= list->size){
        list->capacity /= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }  
    //-----------------------------------------------

    if(list->capacity == list->size){
        list->capacity += 1;
        list->data = (int*)realloc(list->data, (list->capacity) * sizeof(int)); //doubles it
    }

    memmove(list->data + index + 1, list->data + index, sizeof(int) * (list->size - index));
    list->data[index] = new_elem;
    list->size += 1;
} //done, but didnt use memcopy

// Delete the element at index index

void list_delete(IntList *list, int index){
    memmove(list->data + index, list->data + index + 1, list->size - index - 1);
    list->size -= 1;
}

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)  -- if you free list first you cant access the data to free it
void list_destroy(IntList *list){
    free(list->data);
    free(list);
}

// Return the element at index index in list
int list_get(IntList *list, int index){
    return list->data[index];
} //done

#endif


/*updated code:
#include "commoncode.h"

void testblock2(IntList* list){
    if(list->capacity % 2 >= list->size){
        list->capacity /= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }  
    //-----------------------------------------------
    if(list->capacity == list->size){
        list->capacity += 1;
        list->data = (int*)realloc(list->data, (list->capacity) * sizeof(int)); //doubles it
    }
}

void create_list_from_data2(IntList **p_IntList, int *data_arr, int size){
    create_list_from_data(**p_IntList, *data_arr, int size);
}

void list_append2(IntList *list, int new_elem){
    testblock2(list);
    list_append(list, new_elem);
}

void list_insert2(IntList *list, int new_elem, int index){
    testblock2(list);
    list_insert(list, new_elem, index);
}

void list_delete2(IntList *list, int index){
    memmove(list->data + index, list->data + index + 1, list->size - index - 1);
    list->size -= 1;
}


void list_destroy2(IntList *list){
    list_destroy(list)
}


int list_get2(IntList *list, int index){
    return list_get(list, index)
}
*/