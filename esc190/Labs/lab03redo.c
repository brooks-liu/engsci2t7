#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void print_student(student1 s){
    printf("%s\n", s.name);
    printf("%s\n", s.student_number);
    printf("%d\n", s.year);
}


void set_default_name(student1 *p_s){
    strcpy(p_s->name, "default");
}

void set_default_name_wrong(student1 s){
    strcpy(&s.name, "eeee");
    s.year = 0;  //doesnt work
}

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1*)malloc(sizeof(student1) * n_students);
}

void set_name(student1* ps1, char* string){
    if(strlen(string) > 199){
        for(int i = 0; i < 199; i++){
            ps1->name[i] = string[i];
        }
        ps1->name[199] = '/0';
    }
    else{
        strcpy(ps1->name, string);
    }
}

void destroy_block1(student1** pps){
    free(*pps);
}

typedef struct student2{
char *name;
char *student_number;
int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){
    *p_p_s = (student2*)malloc(sizeof(student2) * num_students);
    for(int i = 0; i < num_students; i++){
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }

}

void set_name2(student2* ps, char* string){
    ps->name = (char*)malloc((strlen(string) + 1) * sizeof(char));
    strcpy(ps->name, string);

}

void destroy_block2(student2** pps, int blocksize){
    for(int i = 0; i < blocksize; i++){
        free((*pps)[i].name);
        free((*pps)[i].student_number);
    }
    free(*pps);

}

void main(){
    student1 brooks = {"brooks", "105083502", 1};
    print_student(brooks);
    set_default_name(&brooks);
    print_student(brooks);
    set_default_name_wrong(brooks);
    print_student(brooks);

    student1 s1;
    student1* ps1 = &s1;
    create_block1(&ps1, 5);  //ps1 no longer points to s1

    student2 joel;
    set_name2(&joel, "notjoel");
    printf("%s\n", joel.name);
    





}