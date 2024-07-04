// Q1
#include <stdio.h>

void set_int1(int x)
{
  x = 42;
}

void set_int2(int *p_x)
{
  *p_x = 42;
}

int main()
{
  int a = 10;
  set_int1(a);
  printf("a after set_int1: %d\n", a);

  int b = 20;
  set_int2(&b);
  printf("b after set_int2: %d\n", b);

  return 0;
}

/*
set_int1 takes an int as an argument, which means that it only receives a copy of the value of the argument passed to it, not the original value. So, when x is assigned the value 42 within the function, the original value of a is not changed.

set_int2 takes a pointer to an int as an argument, which means that it receives the address of the original value of the argument passed to it. So, when *p_x is assigned the value 42 within the function, the original value of b is changed.
*/

// Q2

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;


void print_student1(student1 s)
{
    printf("name: %s, student_number: %s, year: %d", s.name, s.student_number, s.year);
}

int main()
{
    student1 s1;
    s1.year = 1;
    strcpy(s1.name, "John");
    strcpy(s1.student_number, "1234567890");
    print_student1(s1);
    return 0;
}

// Q3

void set_default_name(student1 *p_s)
{
    strcpy(p_s->name, "John Doe");
}


void set_default_name_wrong(student1 s)
{
    strcpy(s.name, "John Doe");
}

// The entire s, including the name field, is copied into the function. So, when the name field is changed,
// the original value of s is not changed.

// Q4
void create_block1(student1 **p_p_s, int num_students)
{
    *p_p_s = (student1 *)malloc(num_students * sizeof(student1));
}
// Q5
void set_name(student1 *p_s, char *name)
{
    for(int i = 0; i < 200; i++)
    {
        p_s->name[i] = name[i];
    }
    p_s->name[199] = '\0';

    //strncpy(p_s->name, name, 200);
}

// Q6
void destroy_block1(student1 *p_s)
{
    free(p_s);
}


typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

// Q7

void create_block2(student2 **p_p_s, int num_students)
{
    *p_p_s = (student2 *)malloc(num_students * sizeof(student2));
    for(int i = 0; i < num_students; i++){
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }
    
    // or *p_p_s = (student2 *)calloc(num_students * sizeof(student2));
    // or     *p_p_s = (student2 *)malloc(num_students * sizeof(student2)); memset(*p_p_s, 0, num_students * sizeof(student2))
    
}

// Q8

void set_name2(student2 *p_s, char *name)
{
    p_s->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(p_s->name, name);
}

// Q9

void destroy_block2(student2 *p_s, int block_sz)
{
    for(int i = 0; i < block_sz; i++)
    {
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}

// Q10

void set_names(student1 s1, student2 s2)
{
    strcpy(s1.name, "John"); // copies the string "John" into the array in the local s1
                             // no effect outside the function
    strcpy(s2.name, "John"); // copies the string "John" to the address s2.name, which is
                             // the same address as in the struct outside the function

    // Can try s1.name (as an address) and s2.name, and verify that the address s1.name is different outside the function, but
    // the address s2.name isn't. That's because the array s1.name gets copied as part of s1.
    // The address s2.name also gets copied, but it's just an address.

    // Note that &s1.name changes, in the same way &s2.name changes
    // (&arr is the same as just arr -- the address of the first element of the array)
}




int main()
{
    student1 *p_s;
    create_block1(&p_s, 10);
    strcpy(p_s->name, "John");
    strcpy(p_s->student_number, "1234567890");
    p_s->year = 1;
    print_student1(*p_s);
    return 0;
}

// Q12
// Write in student.h, then #include "student.h"
/*
#if !defined(STUDENT_H)
#define STUDENT_H

typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

#endif
*/



// Q13
void print_file(filename)
{
    char line[200];
    FILE *fp = fopen(filename, "r");
    for(int i = 0; i < N; i++){
        fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
//(including ’\0’) into line.
        printf("%s", line);
    }
    fclose(fp);
}

// Q14

double avg_nums(filename)
{
    double sum = 0;
    char line[200];
    FILE *fp = fopen(filename, "r");
    
    int count = 0;
    while(!fgets(line, sizeof(line), fp)){
        sum += atoi(line);
        count++;
    }
    fclose(fp);
    return sum/count;
}
