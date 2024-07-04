/*
compiled languages takes human-readable code and translates it to machine code.
machine code is faster to execte than interpreting human readable code, and then running it separately
(like Python, which is an interpreted language)

Low-level languages are easy to translate to machine code (like C)
High-level languages are harder because of abstractions (like Python)
    An example of abstraction is for loops and functions (lines of code in one line of code)


Python is an interpreted language vs C as a compiled language
C can be much faster to run, but slower to write
*/
#include <stdio.h>  //like an import command, stdio.h is used for printing

int main()  //almost no code can go outside the function, C also doesnt care if you indent
{  //putting the bracket like this is Kernighan & Ritchie style
    int a = 42;
    char c1 = '0';
    printf("hello world\n");  //semicolons are mandatory, must use double quotes
    printf("test");
    return 0;  //return 0 means successfully run
} 

//debug console tells you whats happening

//must always declare a variable (int, double (float in python), char - in single quotes, int*(address of an integer), 
//char* (address of a char), )
