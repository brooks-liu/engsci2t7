#include "mystr.h" //see the other file
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//ALWAYS ERROR CHECK!!

void mystr_create(mystr* ps, const char* str, int len){
    ps->len = len;
    ps->str = (char*)malloc((len + 1) * sizeof(char));  //+1 for the null
    strcpy(ps->str, str); // can modify it since its a copy
    //if str is a const char*, then we won't know that we cant modify ps->str afterwards
    //also cannot free a const char*
    //in general FREE ANYTHING THAT WAS MALLOCED, DON'T FREE ANYTHING THAT WASNT
    if(ps->str == NULL){ //error shooting
        printf("Malloc Failed\n");
        exit(1);

    }
}

void mystr_cat(mystr* pdest, const mystr* psource){
    pdest->str = (char*)realloc(pdest->str, (pdest->len + psource->len + 1) * sizeof(char));
    if(pdest->str == NULL){
        printf("Realloc failed");
        exit(1);
    }
    pdest->len += psource->len;
    strcat(pdest->str, psource->str);

}

void mystr_destroy(mystr* ps){
    free(ps->str);
    ps->str = NULL;
    ps->len = 0;
}

int main(){
    mystr s;
    mystr_create(&s, "Engsci", 6);
    mystr praxis;
    mystr_create(&praxis, "PRAXIS", 10);

    mystr_cat(&s, &praxis);
    printf("%s\n", s.str); //or &s->str


}

