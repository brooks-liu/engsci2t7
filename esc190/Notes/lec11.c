/* 
sometimes there just might not be enough space

char* BLOCK = malloc(10000000);
if (block == NULL){
    printf("out of memory");
    exit(1);  //this terminates the program, doesn't run anything else 
}

ALWAYS HAVE ERROR CHECKING - it might take down the entire computer sometimes

pointers are basically like units in physics, make sure double/single are consistent with function inputs


strcat() concatenates two strings, assuming str1 has enough space to accommodate extra characters, crashes if not
*/
#include <stdio.h>
#include <string.h>


void safer_strcat(char** p_str1, char* str2){
    //needs enough space for both str1 and str2 and null character
    *p_str1 = (char*)realloc(*p_str1, strlen(*p_str1) + strlen(str2) + 1);
    if(*p_str1 == NULL){
        printf("strcat failed to allocate memory\n");
        exit(1);
    }

    strcat(*p_str1, str2);
}

// realloc is like this:
// smth = realloc(smth, 200*sizeof(aoewjf))