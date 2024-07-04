#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Part 1

//q5
void change_int(int* p_a){
   *p_a = 5;
}

//q10
void change_int2(int** p_p_a){
   *(*p_p_a) = 46;
}

//q11
void change_int_ptr(int** p_p_a){
   *p_p_a = (int*)malloc(sizeof(int));
}

//q16
void change_arr(int* arr){
   arr[2] = 8; 
}

//q21
typedef struct student{
   int name[1000];
   int age;
}student;

//q27
void change_name(student* p_s){
   strcpy(p_s->name, "Jenny");
}

//q28
void change_age(student* p_s){
   p_s->age = 20;
}

//q34
void create_student(student** p_p_s){
   *p_p_s = (student*)malloc(sizeof(student));
}


int main()
{
   //q1
   int a = 42;

   //q2
   int* p_a = &a;

   //q3
   *p_a = 43;

   //q4
   int b = 0;
   p_a = &b;

   //q6
   change_int(&a);

   //q7
   change_int(p_a);

   //q8 + q9
   int** p_p_a = &p_a;

   //q12
   change_int2(p_p_a);

   //q13
   change_int_ptr(&p_a);

   //q14
   change_int_ptr(p_p_a);

   //q15
   int arr[3] = {5, 6, 7};

   //q17
   change_arr(arr);

   //q18
   int* p_block = (int*)malloc(sizeof(int) * 3);
   change_arr(p_block);

   //q19
   change_int(p_block);

   //q20
   change_int_ptr(&p_block);

   //q21
   student s = {"Default", 4.0};

   //q22
   strcpy(s.name, "Jennifer");

   //q23
   s.age = 21;

   //q24
   student* p_s = &s;

   //q25
   strcpy(p_s->name, "Jenny");

   //q26
   p_s->age = 20;

   //q29
   change_name(p_s);

   //q30
   change_age(&s);

   //q31
   student block_s[5];

   //q32
   change_age(&(block_s[2]));
   change_name(&(block_s[2]));

   //q33
   student* p_block_s = (student*)malloc(sizeof(student) * 5);

   //q35
   create_student(&p_block_s);

   return 0;
}

// Part 2
/*
Exercise 1: Initialize two integer variables, and write a function that swaps the values of two integer variables.
Solution:

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    return 0;
}
*/


/*
Exercise 2: Initialize two integer variables, and write a function that adds the values of two integer variables 
and puts the value into both.

void add(int *a, int *b) {
    int temp = *a + *b;
    *a = temp;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    add(&x, &y);
    return 0;
}
*/

