#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CirQueue{
    int size;
    int* data;
    int start;
    int end;
}CirQueue;

void enqueue(CirQueue* queue, int item){
    int b = 1;
    for(int i = 0; i < queue->size; i++){
        if(queue->data[i] != 0){
            b = 0;
        } // test if its completely empty
    }
    if(b == 0){
        if(queue->end == queue->size - 1){
            queue->end = 0;
        }
        else{
            queue->end++;
        }
        queue->data[queue->end] = item;
    }
    else{
        queue->data[0] = item;
    }
}

int dequeue(CirQueue* queue){
    int ret_val = queue->data[queue->start];
    queue->data[queue->start] = 0;
    if(queue->start == queue->size - 1){
        queue->start = 0;
    }
    else{
        queue->start++;
    }
    return ret_val;
}

int main(){
    CirQueue array;
    array.size = 6;
    array.start = 0;
    array.end = 0;
    array.data = (int*)malloc(sizeof(int) * array.size);
    for (int i=0; i<array.size; i++) {array.data[i] = 0;} // initilaizes to 0

    for(int i = 0; i < array.size; i++){
        printf("%d ", array.data[i]);
    }
    printf("\n");

    enqueue(&array, 1);
    enqueue(&array, 2);

    for(int i = 0; i < array.size; i++){
        printf("%d ", array.data[i]);
    }
    printf("\n");

    enqueue(&array, 3);
    dequeue(&array);

    for(int i = 0; i < array.size; i++){
        printf("%d ", array.data[i]);
    }
    printf("\n");

}