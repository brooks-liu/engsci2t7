// use dir in the terminal to get list of files
// gcc program1.c program2.c -o myexec.exe  --> the executable is not named myexec.exe
// ./myexec.exe to run exectuables
// #DEFINE PI 3.14 --> PI is always replaced by 3.14 (faster than defining a variable)

// #if !defined(VARIABLE_H)  --> if not already defined, define it
// #define STUDENT_H

//generally need to compile manually, the run button only compiles one file
/* to run multiple files:

termial -> configure tasks -> gcc    this will go into tasks.json
go to args
-g means include line numbers
${file} means current file  

change to ${fileDirname}/filename1.c and new line: ${fileDirname}/filename2.c

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char* s = "Hello";
    printf("%s\n", s);
    strcpy(s, "!");
    printf("%s\n", s);
}