#if !defined(LIST_H)
#define LIST_H
void create_list_from_data(void **p_list, int *data_arr, int size);
void list_append(void *list, int new_elem);
void list_insert(void *list, int new_elem, int index);
void list_delete(void *list, int index);
void list_free_all(void *list);
int list_get(void *list, int index);
#endif