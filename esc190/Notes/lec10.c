// store everything inside struct
typedef struct student1{
    char name[50];  //specified at 50 characters
    double gpa;
} student1;

// store a pointer to name inside the struct
typedef struct student2{
    char* name;  // student2 takes up less space than student1 since char* is more efficient than char[50], since names are less than 50
    double gpa;
} student2;

int main(){
    student1 s1[150];  //150 cells or students
    // a malloced block of student1s:
    student1* s1_block = (student1*)malloc(150*sizeof(student1));
    // unlike s1, we can return s1_block because the address of the block is valid until freed

    
    student2 s2[150];  //150 cells of students, but cannot access the name addresses yet since not given an address yet
    // we can access gpa tho, since it is a value and not an address
    // if you say print %ld for the name, it will work, but %d will not work

    s2[0].name = "John"; //fine but not allowed to change s2[0].name[0] = 'f'
    s2[0].name = (char*)malloc(50*sizeof(char));
    strcpy(s2[0].name, "John"); //good

    //if want a block of students, want a variable of type student*
    //if want a block of addresses to blocks, want student** 
    student2** p_s2_block = (student2**)malloc(150* sizeof(student2*)); // stores address of the first address

    int i;
    for(i = 0; i < 150; i++){
        p_s2_block[i] = (student2*)malloc(sizeof(student2));
        p_s2_block[i]->gpa = 4.0;  // equivalent to (*p_s2_block[i]).gpa = 4.0, use -> if its a pointer, use . if its not

        p_s2_block[i]->name = (char*)malloc(50 * sizeof(char));
        strcpy(p_s2_block[i]->name, "John");  //do it this way because we usually don't know the name before hand

    }



}
//like a list in a dictionary in python
