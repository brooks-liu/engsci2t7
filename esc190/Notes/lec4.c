#include <stdio.h>

/*
review
declaration is used when first creating a variable
c always stores an extra "null character" '/0' at the end of the line in memory tables to know when to stop reading
a pointer char * stores the address of the starting location of a char in a different address
making char *p = &c


another type is int arr[]= {5, 10, 2}  CAN ONLY USE THIS WHEN DECLARING, NOT WHEN REASSIGNING
arr[0] = 3
CANNOT SAY arr = {1, 2, 3}

long int la = 1234567890;  stores more data than a usual integer, usually how you store addresses

how functions work:
specify a return type, specify type of inputs

int add(int a, int b) {
    return a + b;
}

int f(int *p) {
    *p = 40;
}
this function puts 5 at the address specified by p

when using arrays, a[0] is the same as *(a+0), with the pointer refering to an address of list

*/

double sum(double x, double y) {
    return x + y;
}


int main() {
    int a = 42;
    printf("%d \n", a);  // %d stands for integer, \n is a new line

    double s = sum(1.2, 3.4);
    printf("%ld \n", s);  // this is incorrect, it tells it to interpret it as a long decimal, so it assumes its the address
    printf("%f \n", s);  // %f stands for float, so it is interpreted as a float, printing the correct number
    //casting is basically converting between types
    // int 1.2 --> 1  (truncates)
    int x = 1.2;  
    printf("%d \n", x);
    char *str = "hello";
    printf("%s is stored at address %ld \n", str, str);


    int arr[] = {5, 6, 7};
    printf("%d \n", arr[0]);
    printf("%d \n", arr); //prints the starting location of the 5

    printf("%d \n", *arr);  // *arr is the same as arr[0] and *(arr+0)

    char *str2 = "hi";
    printf("%c \n", str2[0]);  // h
    printf("%c \n", *str2);  // h
    printf("%c \n", *(str2+0));  // h


    q1();
    q2();
    q3();
    q4();
    return 0;
}
// you have to save the program before running it again


// if a function doesn't return anything, you can make it void
void change_p(int *pointer_a) {
    *pointer_a = 10;
}

int anothermain() {
    int aa = 43;
    int *pointer_aa = &aa;  // pointer_aa is a pointer to address of aa
    change_p(pointer_aa);  // this changes the value at pointer_aa to 10
    // aa is now 10

    /*
    recap:
    int * stores address of int
    *p means the value at address p
    &a means the address of a
    you copy the value to the local variable from the function call
    arr[0] is the same as *arr
    */
    return 0;
}

// practice:
void q1() {
    int a = 5;
    int *p_a = &a;
    printf("%d, %ld, %d \n", a, p_a, *p_a); 
    printf("hello");
    // i think this prints 5, address of a (say 1091245), 5
}

void q2() {
    int a[] = {5, 6, 7};
    a[0] = 6;
    int *p = a;
    printf("%d, %d \n", a[0], *p);
    // i thinkt his prints 6, 6
}

void f(int *aa) {
    aa[0] = 7;
}

int q3(){
    int a[] = {5, 6, 7};
    a[0] = 6;
    int *p = a;
    f(a);
    printf("%d \n", a[0]);
    //prints 7
}

int q4() {
    int b = 45;
    f(&b);
    printf("%d \n", b);
    //prints 7
}


// all functions have to be run in main
// a * without a type declaration is a delimiter, it "dereferences" the pointer and it goes to the address and grab the value there
