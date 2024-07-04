#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>


//q1a


/*void q1a(){
   // int* p[5] = {1, 2, 3, 4, 5};
   // printf("%d\n", p[100]);
   // why doesn't this cause seg fault, also what does initialization no pointer mean
   int** ppn = (int**)malloc(sizeof(int*) * 5);
   int a = *(*ppn);
   printf("%d\n", a);


   // this gives seg fault but doesnt crash
   int* pn = *ppn;
   int s = *pn;
   printf("%d\n", s);


}*/


//q1c and d
void read(char* filename){
   FILE *fp = fopen(filename, "r");
   if(fp == NULL){
       printf("No file with name %s\n", filename);
       return;
   }


   fclose(fp);


}


//q2


double sum_floats(char* filename){
   FILE* fp = fopen(filename, "r");
   char line[200];
   double res = 0.0;
   double decimal = 0.1;
   double temp = 0;
   int i = 0;
   int sign = 1;
   while(fgets(line, sizeof(line), fp)){
       i = 0;
       decimal = 0.1;
       temp = 0;
       sign = 1;
       if(line[i] == '-'){
           sign = -1;
           i++;
       }
       while(line[i] != '.' && line[i] != '\n'){
           temp = temp * 10 + (line[i] - '0');
           i++;
       }
       while(line[i] != '\n'){
           if(line[i] == '.'){
               i++;
           }
           temp += (line[i] - '0') * decimal;
           decimal *= 0.1;
           i++;
       }
       
       res += temp * sign;
   }
   fclose(fp);


   return res;
}




//q3
typedef struct student1{
   char name[3];
   int age;
} student1;


void change_name1_wrong(student1 s){
   s.name[0] = 'b';
}  //local s gets changed, then deleted


void change_name1_right_a(student1 *p_s){
   p_s->name[0] = 'b';
}  // changes first letter


void change_name1_right_b(student1 *p_s){
   strcpy(p_s->name, "b");
}  // changes the entire thing to 'b' (copies it)


// different from the python because memory allocation causes it to cut off


void change_name(student1 *student, const char *new_name) {
   strcpy(student->name, new_name);
}






int main(){
   //q1a();
   //read("a.txt");
   //read("fjile.txt");


   //printf("q2here\n");
   double res = sum_floats("test.txt");
   printf("%f\n", res);




}