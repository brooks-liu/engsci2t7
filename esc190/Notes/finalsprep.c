#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    double res = 1;
    for(int i = 1; i <= 5; i++){
        res *= i;
    }
    printf("%f\n", res);
    printf("%d\n", 299/100);

    int arr1[3] = {1, 2, 3};
    int* arr = (int*)malloc(sizeof(int) * 3);
    for(int i = 0; i < 3; i++){
        arr[i] = arr1[i];
    }
    for(int i = 0; i < 3; i++){
        printf("%d\n", arr[i]);
    }
}