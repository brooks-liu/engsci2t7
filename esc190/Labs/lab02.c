#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//q1
void q1(char **s, int *x){
    printf("Input the length of the string: ");
    scanf(" %d", x);
    int i = 0;
    *s = (char *)malloc((*x + 1) * sizeof(char));

    for(i = 0; i < *x; i++){
        printf("Enter the next character: ");
        scanf(" %c", *s + i);
    }
    (*s)[i] = '\0';
}

//q2
char* my_strcat_increment(char *destination, const char *source){
    int len1 = strlen(destination);
    int len2 = strlen(source);
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    int i = 0;
    for(i = 0; i < len1; i++){
        result[i] = destination[i];
    }
    i = len1;
    for(i = len1; i < (len1 + len2); i++){
        result[i] = source[i - len1];
    }
    result[len1 + len2] = '\0';
    return result;
}

void my_strcat_point(char *destination, const char *source){
    while (*destination != '\0') {
        destination++;
    }

    while(*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
}

// q3
int my_strcmp(const char* str1, const char* str2){
    int i = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(i = 0; i < len1; i++){
        if(str1[i] == str2[i]){
            continue;
        }
        else{
            str1[i] - '0';
            str2[i] - '0';
            if(str1[i] > str2[i]){
                return str1[i] - str2[i];
            }
            else{
                return str1[i] - str2[i];
            }
        }
    }
    return 0;
}

int my_strcmp_rec(const char *str1, const char *str2){
    if(str1[0] == '\0' && str2[0] == '\0'){
        return 0;
    }

    if(str1[0] == str2[0]){
        return my_strcmp_rec(str1 + 1, str2 + 1);
    }

    return ((str1[0]-'0') - (str2[0]-'0'));
}


// s1 == s2 compares both strings, *s1 == *s2 compares the first characters, strcmp() also tells you whether or not the 
// first nonmatching character in string1 is a higher ASCII value than in string2


//q4 - see python file

//q5
#include <ctype.h>

int my_atoi(char *str){
    int i = 0;
    bool all_digit = true;
    int len = strlen(str);
    int res = 0;
    for(i = 0; i < len; i++){
        if(isdigit(str[i]) != true){
            return false;
        }

        res = (str[i]-'0') + res*10;
    }
    return res;

}

int main(){
    //q1
    printf("q1\n");
    char* s1 = "ohmy";
    char** ps1 = &s1;
    int x1 = 5;
    int* px1 = &x1;
    q1(ps1, px1);
    printf("%s \n", *ps1);

    //q2
    printf("q2\n");
    char* a = "oh";
    char* b = "yea";
    printf("%s \n", my_strcat_increment(a, b));

    //q3
    printf("q3\n");
    char *str1 = "bruh";
    char *str2 = "bruh";
    char *str3 = "broh";

    printf("%d \n", my_strcmp(str1, str2));
    printf("%d \n", my_strcmp(str1, str3));
    printf("%d \n", my_strcmp(str3, str2));

    str1 = "bruh";
    str2 = "bruh";
    str3 = "broh";

    printf("%d \n", my_strcmp_rec(str1, str3));
    printf("%d \n", my_strcmp_rec(str3, str2));

    printf("q5\n");




    //q5
    int i = 0;
    char *str = "123";
    int len = strlen(str);

    for(i=0;i<len; i++){
        printf("%c \n", str[i]);
    }

    i = 0;
    printf("%d \n", my_atoi(str));
    




}