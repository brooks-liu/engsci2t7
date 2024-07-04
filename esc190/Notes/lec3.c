int main()  
{  
    //before using a variable, we must declare it
    //usually also initiatlize it (assigning an initial value)
    int a = 5;
    int b; //this is possible, there just isn't an initial value
    //other values include double, char, int * (which is the address of an integer), and 
    //char * (which is the address of a character)
    char c1 = '0';
    char *s = 'a';
    printf("hello world");  
    return 0; 
}

/* this table is for example below
address     value                                      variable     value
1032        'h'                                        a            @1035
1033        'i'                                        s1           @4089
1034        \0  
1035        43                                       
.
.
.
4089        '1032'   this is what the char * is referring to, it is a character type

*/


int aowiejf()  
{  
    char *s1 = 'hi';  //puts 'hi' in memory followed by a null character \0 (see above)
    printf("%s\n", s1); //%s: string (prints sequece of characters at given address until /0)
    printf("%ld\n", s1);  //%ld: long decimal (stores more data than a usual integer)
    //s1 would refer to the address of the address of 'h', and the thing after % tells the printf what to print
    //essentially s1 (1032) is stored at 4089 as a character, if it wants the string,???????

    printf("The string is: %s, the address is %ld\n", s1);

    int a = 43;
    printf("The integer is: %d\n", a);
    printf("The string is: %s\n", a);


    return 0; 
}


int yes()
{
    int a = 42;
    int b;  //can have any value
    char *s1 = "abcdef";  //type char *
    char c = '0';  // type char
    double d = 3.14;  //like floats in python

    printf("The int is: %d\n", a);
    printf("The character is: %c\n", c);
    printf("The double is: %f\n", d);

    int *p_a = &a; //p_a is type int *, stores an address of an int, &a is the address in the memory table where a is stored
    printf("%ld\n", p_a);  //prints the address of a
    printf("%d\n", *p_a);  //prints the value of a, usually do it by replacing *p_a with a

    double x = 10.34;
    double *address_of_x = &x;
    double y = 25+ *address_of_x;  //y is not 25+10.34

    char *s1 = "hello";
    // * is used as a part of the type char * 
    char c = *s1; //c is 'h', and * is used as a "dereferencing operator", gets the value at the given address


}

//* variables are called pointers. traditionally the hardest thing in first year programming, but we're special! so its easy or smth!
