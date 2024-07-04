// valgrind
/*detects incorrect access to memory or memory leaks*/
// WSL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* p = (char*)calloc(0, 10000);  //calloc fills it with 0s
    printf("bruh\n");
    printf("value: %c\n", p[5000]); // this 

    printf("%s\n", p+10000-3);
    //stars at p[9997], tries until reaches null, if null is never accessed it never stops

    int** ppint;
    ppint = (int**)malloc(3 * sizeof(int*));
    // ppint is a block of 3 int* s
    int* pint = *ppint; //ppint[0] - now pint is a pointer to nothing
    printf("pint: %ld\n", (unsigned long)pint);  // prints 0
    int myint;
    if (pint != NULL) {
        myint = *pint;  // allocate memory for pint before dereferencing it
    } 
    else {
        // handle the case when pint is NULL
    }
    //valgrind can catch this, compilers usually dont
    /* to use valgrind, do this in the terminal:
    gcc -o. <valgrind file name> <filename.c> -g
    valgrind ./<file>
    */
}