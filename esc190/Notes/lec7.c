void change(int *pa){
    pa = 0;
}  // this changes the address of a (why would you do that)

// python always passes an address, unlike c

void change_list(int *arr){
    arr[0] = 5;  // this changes the array
}

void dont_change_list(int *arr){
    arr = 0;  // this does not change the array
} // similar to changing a local list L instead of the global list L


void change_string(const char *s){
    "s[0] = 'x'";  // compilation error
}

void change_string2(char *s){
    s[0] = 'x';  // runs ok, but may crash if s is actually constant
}



// strlen() counts how many steps it takes to get to the null character

#include <stdio.h>

int my_strlen(char *str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}


int my_strlen2(char *str){
    int len = 0;
    while(*str != '\0'){
        len++;
        str++;
    }
    return len;
}

// recursive version
int my_strlen_rec(char *str){
    if(*str == '\0'){
        return 0;
    }  // base case
    return 1 + my_strlen3(str + 1);
}


int main(){
    char *s1 = "abc";
    change_string(s1); //may cause a crash

    char s2[] = "abc";
    change_string2(s2);  //ok

    //neither of these work in python


    const char *str = "hi";
    printf("%d \n", my_strlen(str));  
}


// malloc() is a function that allocates memory:
/*
#include <stdlib.h>
int *block_int = (int *)malloc(sizeof(int) * 150);  makes space for 150 ints, malloc returns the address of the first int

block_int[7] = 42;
*(block + 7) = 42;  // same thing


usually addresses are 8 bytes
using sizeof(arr), sends the address of the array, not the size of the array, so prints 8, not however long arr is 



*/



