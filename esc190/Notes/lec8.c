int* f(){
    int* arr[20];


}

int* make_block(int sz){
    int* p = (int*) malloc(sz * sizeof(int));

    if(isnull(p)){
        printf("out of memory");
        exit(1);    // exit one crashes it with exit code 1 (not successful)
    }

    return p;
}


int main(){
    int* p = f();
    p[0];  //undefined behavior, because the local variable is gone (might crash, print 42, break)

    int* q = make_block(50);
    q[7] = 50;  //this works

    return 0;
}

/*
in general it is good practice to free(blockname) to free up space
on modern OS, its usually freed after the program terminates
sometimes on older OS, you might run out of memory

trying to access a block after the memory is freed is undefined behaviour, might crash 


*/

/*
typedef struct student{
    char name[200];
    int age;
} student;

student students[500];
student* students_block = (student * (int*)malloc(sizeof(student) * 500))

*/

// dealing with strings
void strings(){
    char s1[] = "hi";  
    char* s2 = 0;  // not a valid address

    s2 = s1;  // legal but strings are now aliases
    strcpy(s2, s1);  //not ok since cannot copy address of s2 yet, this is basically doing s2[0] = s1[0] ... etc
                     // cannot do that cause s2 is not a valid address, and there is no null character to stop at
    s2 = (char*)malloc(sizeof(char) * (strlen(s1) + 1));
    strcpy(s2, s1);  //copy the contests of s1 into s2
}


// pointers to pointers
void set_to_0(int **ppa){
    *ppa = 0; // sets the value at the address ppa to 0, so the address of a is now 0 since *ppa is int* type
}

void aewfi(){
    int a = 42;
    int* pa = &a;
    set_to_0(&pa);  //int* pa = 0; now, a is not affected 
}



