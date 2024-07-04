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
