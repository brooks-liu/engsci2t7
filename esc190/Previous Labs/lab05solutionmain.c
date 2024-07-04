#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"


void create_list_from_data(LL *p_list, int *data_arr, int size)
{
    p_list->size = 0;
    p->head = NULL;
}

int main()
{
    int data[5] = {1, 2, 3, 4, 5};
    void *my_list;
    create_list_from_data(&my_list, data, 5);
    printf("elem at 3: %d\n", list_get(my_list, 3));


}