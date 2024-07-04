#include <stdio.h>
#include <string.h>

void f(int *x) {
    *x = 10;
}

void change_array(int *list, int position, int new) {
    list[position] = new;
}

void insertion_sort(int *list, int size) {
    int i = 0;
    int j = 0;
    int len = size;

    if(len <= 1){
        return;
    }
    
    for(i = 1; i < len; i++){
        int value = list[i];
        j = i;
        while(j > 0 && value < list[j - 1]){
            list[j] = list[j - 1];  // shifts left
            j--;
        }
        list[j] = value;
    }
}

int length_string(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
    // runtime is O(n)
}

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    int size1 = arr1_sz;
    int size2 = arr2_sz;

    int i = 0;
    int j = 0;
    while(i < arr1_sz){
        j = 0;
        while(j < arr2_sz){
            if(arr1[i] == arr2[j]){
                arr1[i] = 0;
            }
            j++;
        }
        i++;
    }
}


int main() {
    int a = 5;
    int *p_a = &a;
    f(p_a);
    printf("%d \n", a);


    int arr[10] = {5, 7, 9, 6, 3, 1, 0, 2, 8, 4};
    //change_array(arr, 0, 2);
    printf("%d \n", arr[0]);
    insertion_sort(arr, 10);

    int x = 0;
    while(x < 10){
        printf("%d \n", arr[x]);
        x++;
    }
    

    char *yes = "hello";
    printf("%d\n", length_string(yes));


    printf("q7 start\n");
    int array1[] = {5, 6, 7, 8, 6, 6};
    int array2[] = {6, 7};
    seq_replace(array1, 6, array2, 2);

    int i = 0;
    for(i = 0; i < 6; i++){
        printf("%d\n", array1[i]);
    }

    return 0; 
}

