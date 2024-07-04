# In Python, strings are immutable. 
# That means that we cannot change the value of a string to something else,
# which is what is happenning in all the C functions.

# Here is what we can do:


def change_name(s, new_name):
    s[1] = new_name


s = [20, "Bob"]
change_name(s, "Alice")

# In C, this would be equivalent to:
# 1. Storing the address of the name string for each student
# 2. In the function, changing the address of the name string to point to a new string    


typedef struct student2{
    char *name;
    int age;
} student2;


void change_name(student2 *p_s, const char *new_name)
{
    p_s->name = new_name;
}

int main()
{
    student2 s = {"Bob", 20};
    change_name(&s, "Alice");
}



# Python memory diagram:



Memory table:
1032    20
1036    "Bob"
1064    [@1032, @1036]  (then changed to [@1032, @2072])
2072    "Alice"

Variable table [globals]
s       @1064

Variable table [locals for change_name]
s          @1064
new_name   @2072


# C memory diagram:


Memory table:
32    Initially 1036, then 2072// s
36                             //s.name takes up 8 bytes   
40    20                       //s.age takes up 4 bytes
90    32 // p_s [local]
98    2072 // new_name [local]
1036  "Bob"
2072  "Alice"