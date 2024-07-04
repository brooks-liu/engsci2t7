void change_a(int *a) {
    *a = 5;
}

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
    // cannot have multiple assignments in c
}

void set_arr0(int *arr){
    arr[0] = 0;

}

void set_arr1(int *arr){
    arr = 0;  // doesnt change anything since arr is a local, but arr[0] is a pointer to the first element of the array

}

int main() {
    int a = 3;
    change_a(&a);
    printf("%d \n", a);

    int x = 3, y = 4;
    swap(&x, &y);
    printf("%d, %d \n", x, y);

    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d \n", arr[0]);
    set_arr0(arr);
    printf("%d \n", arr[0]);

    return 0;
}

/*
c does not have strings
char s1 = "abc"  this is basically initializing an array of characters (4 total)
char *s2 = "abc"   s2 is the address of a

the literal "abc" is actually type const char*
const means you cannot change the contents of the string
trying to do so just doesnt make it compile

char *s1 = "abc";  //compiles with warning
s1[0] = 'x';  //might or might not crash
const char *s2 = "abc";  // compiles without warning
s2[0] = 'y';  // this will not compile

const int a = 42;   works similarily
a = 43;  // will not compile

char * const a = "abc";  // cannot change the address of a, but can change the value of a character in the string
const char * const a = "abc";  // cannot change value of a character in the string, and cannot change the string itself
const char * a = "abc";  // cannot change value of a character in the string, but can change the string itself


*/