/*
building on lecture 13. usually include the function delaractions in the .h file, and define the function in the .c file 
otherwise you have to be careful compiling the .c file and make sure you get the order right

can also compile all the functions in a separate .c file, and then have the main function in a different c file



*/

#include <stdio.h>

int main(){
    int n = 10;
    while(1){
        printf("n = %d\n", n);
        n *= 2;
        int temp;
        scanf("%d", &temp);
    }
}  //eventually gets to negative numbers, becuase it just loops after the largest number


//see pyint.c and pyint.h for rest of notes - we are implementing addition in python