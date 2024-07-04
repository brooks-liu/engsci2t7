#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void* b){
    return(*(int*)a - *(int*)b);
}

void g(int* arr, int size){
    int* temp = (int*)malloc(size*sizeof(int));
    for(int j = 0; j < size; j++){
        temp[j] = arr[j];
    }
    qsort(temp, size, sizeof(int), cmp);
    for(int i = 0; i < size; i++){
        printf("%d, ", temp[i]);
    }
}


//q3
int compare(char* str1, char* str2){
    if(str2[0] == '\0'){
        return 1;
    }
    if(str1[0] == str2[0]){
        return compare(str1 + 1, str2 + 1);
    }
    else{
        return 0;
    }
}

int strcmp_rec(char* str1, char* str2, int index){ //pass 0 to start
    if(str1[index] == '\0'){
        return -1;
    }
    if(compare(str1 + index, str2) == 1){
        return index;
    }
    else{
        return strcmp_rec(str1, str2, index + 1);
    }
}

//q5a
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct LL{
    node* head;
}LL;

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

int length_LL(LL list){
    if(list.head == NULL){
        return 0;
    }
    int counter = 0;
    while(list.head != NULL){
        list.head = list.head->next;
        counter++;
    }
    return counter;
}

//q5b
int cmpfnc(const void *num1, const void* num2){
    return(*(int*)num1 - *(int*)num2);
}

int median_LL(LL list){
    int length = length_LL(list);
    int arr[length];
    node* cur = list.head;
    arr[0] = cur->data;
    for(int i = 1; i < length; i++){
        cur = cur->next;
        arr[i] = cur->data;
    }
    qsort(arr, length, sizeof(int), cmpfnc);
    return arr[(length-1)/2];
}

//q6
/*#include <math.h>
char* generate_strings(char* alphabet, int k){
    //char* string = (char*)malloc(sizeof(char) * pow(strlen(alphabet), k) * (k+1));
    if(k == 0){
        //return strcat(string, '\n');
        return '\n';
    }
    for(int i = 0; i < k; i++){
        // char* temp = (char*)malloc(sizeof(char) * (k+1));
        // temp[0] = alphabet[i];
        
        // return strcat(string, strcat(temp, generate_strings(alphabet, k-1)));
        return strcat(alphabet[i], generate_strings(alphabet, k-1));
    }
}*/

/*
def all_strings(k, alphabet):
    '''Return a list of all strings of length k over the alphabet'''
    if k == 0:
        return [""]

    res = []
    for letter in alphabet:
        all_k1_strings = all_strings(k-1, alphabet)
        for string in all_k1_strings:
            res.append(letter + string)
    return res
*/

int main(){
    int arr[5] = {5, 4, 3, 2, 1};
    g(arr, 5);

    char str1[] = "aEngsci Engsci Trackone";
    char str2[] = "Engsci";
    
    printf("%d\n", strcmp_rec(str1, str2, 0));

    node* head = (node*)malloc(sizeof(node));
    int list[5] = {1, 2, 3, 2, 5};
    create_LL(&head, list, 5);
    LL linkedlist;
    linkedlist.head = head;
    printf("%d\n", length_LL(linkedlist));

    printf("median: %d\n", median_LL(linkedlist));
    printf("hi\n");

    //printf("%s", generate_strings("abc", 2));
}
