#if !defined(COMMONCODE_H)
#define COMMONCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IntList {
    int *data;
    int size;
    int capacity;
} IntList;

void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    *p_IntList  = (IntList*)malloc(sizeof(IntList));
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size;
    (*p_IntList)->data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        (*p_IntList)->data[i] = data_arr[i];
    }
}

void list_append(IntList *list, int new_elem){
    list->data[list->size] = new_elem;
    list->size += 1;
}

void list_insert(IntList *list, int new_elem, int index){
    memmove(list->data + index + 1, list->data + index, sizeof(int) * (list->size - index));
    list->data[index] = new_elem;
    list->size += 1;
}

void list_delete(IntList *list, int index){
    memmove(list->data + index, list->data + index + 1, list->size - index - 1);
    list->size -= 1;
}

void list_destroy(IntList *list){
    free(list->data);
    free(list);
}


int list_get(IntList *list, int index){
    return list->data[index];
}

#endif
