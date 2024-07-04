#include <stdio.h>
#include <string.h>
// #include <lab03header.h>
#include <stdlib.h>

//q1
void set_int1(int x)
{
x = 42;
}

void set_int2(int *p_x)
{
*p_x = 42;
}

//q2
typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void printstudent(student1 x){
    printf("Student is named : %s\n", x.name);
    printf("Student number is: %s\n", x.student_number);
    printf("Student is in year %d\n", x.year);
}

//q3
void set_default_name(student1* p_s){
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;
}

void set_default_name_wrong(student1 s){
    // doens't work because not a pointer to s
}

//q4
void create_block1(student1** p_p_s, int n_students){
    *p_p_s = (student1*)malloc(n_students * sizeof(student1));
}

//q5
void set_name(student1* ps, char* string){
    int j = 0;
    for(j = 0; j < 200 ; j++){
        ps->name[j] = string[j];
    }
}

//q6
void destroy_block1(student1** pps){
    free(*pps);
}

//q7
typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){
    *p_p_s = (student2*)malloc(sizeof(student2) * num_students);
    (*p_p_s)[0].name = 0;
    *p_p_s[0]->student_number = 0;
}

//q8
void set_name2(student2* ps, char* string){
    ps->name = (char *)malloc((strlen(string) + 1)* sizeof(char));
    strcpy(ps->name, string);
}

//q9
void destroy_block2(student2* ps, int size){
    for(int i = 0; i < size; i++)
    {
        free(ps[i].name);
        free(ps[i].student_number);
    }
    free(ps);
}

//q10
void set_names(student1 s1, student2 s2){
    strcpy(s1.name, "aweoifj"); //this makes a copy of s1, so the array of the name is also local
    strcpy(s2.name, "aeirogrwio"); //this is a pointer to a string outside of the locals, so it changes it
}

//q13
void printcontent(char* filename){
    char line[8];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < 8; i++){
    fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
    //(including ’\0’) into line.
    }
    fclose(fp);

    printf("%s\n", line);
}

//q14
void printnums(char* filename){
    char line[8];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < 8; i++){
    fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
    //(including ’\0’) into line.
        int num = atoi(line);
        printf("%d \n", num);
    }
    fclose(fp);

    // while(fgets(line, sizeof(line), fp)) {
    //     int num = atoi(line);
    //     printf("%d \n", num);
    // }
}


int main(){
    // q1
    int x = 0;
    set_int1(x); // doesn't do anything because the local variable x gets deleted after the function call
    set_int2(&x); // sets x to 42

    //q2
    student1 me = {"Brooks Liu", "1009878027", 1};
    /* or strcpy(me.name, "Brooks Liu"); */
    printstudent(me);


    //q3a
    set_default_name(&me);
    printstudent(me);

    //q4
    student1* pme = &me;
    create_block1(&pme, 2);

    //q5
    set_name(&me, "hello");
    printstudent(me);

    //q6
    destroy_block1(&pme);

    //q7
    student2 I = {"brooks liu", "3450982", 1};
    student2* pI = &I; 
    char* yes = "why no work";
    set_name2(pI, yes);
    printf(I.name);

    //q14
    printnums("file.txt");
}
