#include <stdio.h>
#include <stdint.h>
//q1

int linear_search(int *a, int sz, int elem){
    /* The function returns the index of the first occurrence of the 
    element elem in a block of ints a of size sz. Assume elem occurs in a. */
    int i = 0;
    for(i = 0; i < sz; i++){
        if(a[i] == elem){
            return i;
        }
    }
    return -1;
}


void reverse_arr(int *arr, int sz){
    /* The function reverses the block of ints arr, which is of size sz. 
    For example, if arr starts out as {5, 6, 7, 8}, it should become {8, 7, 6, 5}*/
    int i = 0;
    int* temp = (int*)malloc((sz) * sizeof(int));
    for(i = 0; i < sz; i++){
        temp[i] = arr[sz - 1 - i];
    }
    i = 0;
    for(i = 0; i < sz; i++){
        arr[i] = temp[i];
    }
}

int main(){
    // q0
    printf("Hello, world! \n");

    // q1 test
    int* arr[] = {5, 6, 7, 8};
    printf("%d \n", linear_search(arr, 4, 3));
    printf("%d \n", linear_search(arr, 4, 7));

    // q2 test

    printf("q2 test \n");
    int i = 0;
    for(i = 0; i < 4; i++){
        printf("%d \n", arr[i]);
    }

    i = 0;
    reverse_arr(arr, 4);

    for(i = 0; i < 4; i++){
        printf("%d \n", arr[i]);
    }

}

