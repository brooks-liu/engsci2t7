#include <stdio.h>
void f(int a) {
    a = 42;
}
// f(43) copies 43 to local variable a

void g(int *pa) {
    pa = 0;
}

int a = 45;
// g(&a) copies &a to local variable pa, pa is local but *pa is the same as a, so f has no affect

void h(int *pa) {
    *pa = 0;
}

int a = 45;
// h(&a) changes the value at the address of a to 0. this might give an error since &a is a number (int) not int *

// blocks of values are things such as arrays or strings (stored consecutively in memory)
/*

2064: 3
2064 + 4: 4
int arr[] = {3,4}
arr + 1 is address of 4 (2064 + 4),     ints take 4 spaces, chars take one space (so if its a string it goes to 2064 + 1)
*arr == 3
*(arr + 1) == 4   (next value)

arr[5] is the same as *(arr + 5)

*/ 

//practice:
void func(int *a)
{
  a[0] = 7;
}

int main()
{
    int a[] = {5, 6, 7};
    a[0] = 6;   //6, 6, 7
    int *p = a;  // a is array so can do without the &
    f(a);
    printf("%d\n", a[0]);  // prints 7, 6, 7

    int arr[] = {1,2,3};
    sizeof(arr);   // this gives the number of cells occupied (12)
    sizeof(arr[0]);  // this gives the size of each cell (4)
    // therefore sizeof(arr) / sizeof(arr[0]) gives the number of cells in the array (3)
}
			
			
			
			
			
			
			
			
			






