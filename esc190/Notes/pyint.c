#include "pyint.h"
#include <stdio.h>

void create_pyint(pyint** p, int length){
    *p  =(pyint*)malloc(sizeof(pyint));
    (*p)->buffer = (int*)malloc(length * sizeof(int));
    (*p)->length = length;
    for(int i = 0; i < length; i++){
        (*p)->buffer[i] = 0;
    }  //initializes all the digits to 0
    // or use calloc: p->buffer = (int*)calloc(length, sizeof(elem))
    // or use memset: memset(p->buffer, 0, length * sizeof(int))
}

void set_pyint(pyint* p, int value){
    //say value == 190;
    // buffer is 0 9 1
    //DO NOT ASSUME LENGTH IS ENOUGH
    int i = 0;
    while(value > 0){
        p->buffer[i] = value % 10;
        value = value / 10;
        i++;
    }
}   

// 0 9 1
//+1 0 0
// 1 9 1

//   1 1
// 9 9 1
//+1 0 0
// 0 0 2

void plusplus(pyint* p){
    int carry = 1;
    int i = 0;
    while(carry != 0 && i < p->length){
        int sum = p->buffer[i] + carry;
        p->buffer = sum % 10;
        carry = sum / 10;
        i++;
    }
    if(carry == 1){
        p->buffer = (int*)realloc(p->buffer, (p->length + 1) * sizeof(int));
        p->buffer[p->length] = 1;
        p->length++;
    }
}

void add_pyint(pyint* p, int value){
    for(int i = 0; i < value; i++){
        plusplus(p);
    }  // this is the easy thing to do
}

void print_pyint(pyint* p){
    int i;
    for(i = p->length - 1; i >= 0; i--){
        printf("%d", p->buffer[i]);
    }
    printf("\n");
}


