#include <stdio.h>


void set10(int *p_a){
    *p_a = 10;
}


def sets010(int *arr){
    arr[0] = 10;
}

void insertion_sort(int *arr, int len){
    int i, j, key;
    for (i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void my_strlen(s) {
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}

void seq_replace(int *arr, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    int i, j;
    for (i = 0; i < arr1_sz; i++){
        int match = 0;
        for (j = 0; j < arr2_sz; j++){
            if (arr[i+j] == arr2[j]){
                match++;
            }
        }
        if (match == arr2_sz){
            for (j = 0; j < arr2_sz; j++){
                arr[i+j] = 0;
            }
        }
    }
}
    


int main(void)
{
    int a= 5;
    printf("old value: %d\n", a);
    set10(&a);
    printf("new value: %d\n", *p_a);

    int *arr = [5, 6, 7];

    return 0;
}

