#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    (*p_AL) = (ArrayList*)malloc(sizeof(ArrayList));
    (*p_AL)->size = size;
    (*p_AL)->capacity = size;
    (*p_AL)->data = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        (*p_AL)->data[i] = data_arr[i];
    }
    // (*p_AL)->data = data_arr;
}

void AL_append(ArrayList *my_list, int new_elem)
{
    if(my_list->size == my_list->capacity){
        my_list->capacity *= 2;
        my_list->data = (int*)realloc(my_list->data, sizeof(int) * my_list->capacity);
    }
    my_list->data[my_list->size] = new_elem;
    my_list->size++;
}

void AL_insert(ArrayList *my_list, int new_elem, int index)
{
    if(my_list->size == my_list->capacity){
        my_list->capacity *= 2;
        my_list->data = (int*)realloc(my_list->data, sizeof(int) * my_list->capacity);
    }
    // must use memmove since memove is safe for overlapping memory
    memmove(my_list->data + index + 1, my_list->data + index, sizeof(int) * (my_list->size - index));
    my_list->data[index] = new_elem;
    my_list->size++;

}

void AL_delete(ArrayList *my_list, int index)
{
    memmove(my_list->data + index, my_list->data + index + 1, sizeof(int) * (my_list->size - index - 1));
    my_list->size--;
}

void AL_free(ArrayList *my_list)
{
    free(my_list->data);
    free(my_list);
}



void create_list_from_data(void **p_list, int *data_arr, int size)
{
    create_AL_from_data((ArrayList**)p_list, data_arr, size);   
}

void list_append(void *list, int new_elem)
{
    AL_append((ArrayList*)list, new_elem);
}

void list_insert(void *list, int new_elem, int index)
{
    AL_insert((ArrayList*)list, new_elem, index);
}


void list_delete(void *list, int index)
{
    AL_delete((ArrayList*)list, index);
}
void list_free_all(void *list)
{
    AL_free((ArrayList*)list);
}


int list_get(void *my_list, int index)
{
    ArrayList *AL = (ArrayList*)my_list;
    return AL->data[index];
}
