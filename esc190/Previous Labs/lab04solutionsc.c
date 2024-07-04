#include <stdio.h>
#include <stdlib.h>


void segfault()
{
    char a[5] = "EngSci";
    printf("%c", a[100000]); // segmentation fault
}



double my_atof(const char *str)
{
    int i = 0;
    while(str[i] != "="){
        i++;
    }
    i++;

    double result = 0;
    int sign = 1;
    if(str[i] == "-"){
        sign = -1;
        i++;
    }
    while(str[i] != "."){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    i++;
    double pow10 = 0.1;
    while(str[i] != "\n"){
        result += (str[i] - '0') * pow10;
        pow10 *= 0.1;
    }
    return result * sign;
}

void parse_consts(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error: file not found");
        return;
    }
    char line[100];
    double sum = 0;
    while(fgets(line, 100, fp) != NULL){
        double value = my_atof(line);
        sum += value;
    }
    return sum;
}


