#include <stdio.h>



void change_a(int *p_a)
{
  *p_a = 0;
}



int main()
{
int a = 1;
change_a(&a);
printf("%d\n", a);
}