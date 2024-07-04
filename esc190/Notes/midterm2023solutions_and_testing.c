




//SOLUTIONS FOLLOW
//===================================================================

// Q1(a)
/*
Write a function that appends a node to a linked list. You must use the definitions below. Make sure that
the code works on lists of any size. If you need helper functions, you must write them yourself.
You may need to make assumptions like â€œthe next field of the last node is NULL.â€ State any such
assumption as a comment
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct LL{
    node *head;
    int size;
} LL;

void LL_append(LL *my_list, int new_elem) {
	node *new_node = (node*)malloc(sizeof(node)); // allocate memory for new node
	new_node->data = new_elem; // set new node data to new_elem
	new_node->next = NULL; // assume the next field of the last node is NULL
	if (my_list->head == NULL) { // if the list is empty
	    my_list->head = new_node; // set head to the new node
	} 
	else {	 // if the list is not empty
	    node *current_node = my_list->head; // start at the head of the list
	    while (current_node->next != NULL) { // traverse the list until the end is reached
        	current_node = current_node->next; // move to the next node
	    }
    current_node->next = new_node; // set the next field of the last node to the new node
    }
    my_list->size++; // increment the size of the list
}

// Q2
/*
Write a function with the signature char * strcat_rec(char *dest, const char *src) that concate-
nates dest and src recursively. The result is to be stored at dest. The function returns the destination
string dest. The function does the same thing as strcat in string.h. You must use recursion. You
must not include header files, use helper functions, or use loops. You may assume that there is sufficient
space at dest to store the resultant string.
*/
char * strcat_rec(char *dest, const char *src) {
    if(*dest!= '\0'){
        strcat_rec(dest + 1, src);
        return dest;
    }
    *dest = *src;
    if(*src == '\0')
        return dest;
    *(dest + 1) = '\0';
    strcat_rec(dest + 1, src + 1);   
    return dest;
}

char* strcat_rec_lecture(char *dest, const char *src) {
    if(*dest!= '\0'){
        strcat_rec(dest + 1, src);
        return dest;
    }
    else{
        if(*src == '\0'){
            return dest;
        }    
        dest[0] = src[0];
        dest[1] = '\0';
        strcat_rec(dest + 1, src + 1);
        return dest;
    }
}

// Q3
/*
You have been tasked with creating a digital White Pages book for the Province of Ontario. You have
been provided with a text file. The first line of the file contains the number of entries present. Each of the
following lines contains a phone number formatted as XXX-XXX-XXXX, followed by a tab, followed by
the business name.
3
226-222-6678
289-778-1123
416-445-2555
Spring Cleaning 4 U
Nowruz Party Planners
The April Shower Curtain Company
Part (a) [15 marks]
Write a function to read the file filename and set the values at the input pointers appropriately so that
the information can be used outside the function. The data must be stored as a contiguous block of struct
businessâ€™s.
Assume memory allocated in this function will be freed elsewhere. Assume that the number of businesses
can fit in an int. You may not assume that you know the maximum size of a business name. Your code
needs to be able to handle business names of any length.
We strongly recommend, but donâ€™t require, using a while-loop rather than strtok or
sscanf in order to read in the phone numbers and business names. It is MUCH easier to use
a while-loop!*/

typedef struct business {
    int phone_number[10]; // Note: this is an array of 10 integers
                          // one per digit), not a character array
    char *name;
} business;

void skip_n1_lines(FILE *fp, int n) {
    int i;
    char *line = NULL;
    for(i = 0; i < n; i++){
        fgets(line, 0, fp);
        free(line);
    }
}

void my_getline(char **dest, const char *filename, int index) {
    int cur_len = 1;
    *dest = NULL;

    do{
        FILE *fp = fopen(filename, "r");
        skip_n1_lines(fp, index - 1);
        *dest = (char*)realloc(*dest, sizeof(char) * cur_len);
        fgets(*dest, cur_len, fp);
        cur_len *=2;
        fclose(fp);

    } while((*dest)[strlen(*dest) - 1] != '\n');
}

void read_numbers(const char *filename, business **whitepages, int *size)
{
    FILE *fp = fopen(filename, "r");
    *whitepages = (business*)malloc(sizeof(business) * (*size));
     
    char line[(int)(sizeof(int)*8)];
    *size = atoi(fgets(line, sizeof(int)*8 /*/log(10)/log(2)*/, fp));
    int i;
    for(i = 0; i < *size; i++){
        char *line = NULL;
        int ph_sz = 0;
        int index = 0;
        my_getline(&line, filename, i+1);
        do{
            if(line[index] != '-')
                (*whitepages)[i].phone_number[ph_sz++] = (line[index] - '\0');
        }while(line[++index] != '\t');
        index++;
        strcpy(whitepages[i]->name, line + index);
        free(line);

    }
    

}

typedef struct daylight{
    int hours;
    int minutes;
} daylight;

void create_daylight_pt_block(daylight ***block, int *data, int n)
{
    *block = (daylight**)malloc(sizeof(daylight*)*(n/2));
    for(int i = 0; i < n/2; i++){
        (*block)[i] = (daylight*)malloc(sizeof(daylight));
        (*block)[i]->hours = data[2*i];
        (*block)[i]->minutes = data[2*i+1];
    }
}
void Q4bc()
{
    int data[] = {11, 29, 12, 9};
    daylight **block;
    create_daylight_pt_block(&block, data, 4);
    printf("%d %d\n", block[1]->hours, block[1]->minutes);
    free(block[0]);
    free(block[1]);
    free(block);
}




int main()
{
    char s[] = "hello";
    char dest[10] = "xxx";
    //strcpy(dest, s);
    //printf("%s\n\n", strcat_rec(dest, s));
    business *whitepages;
    int size;
    read_numbers("wp.txt", &whitepages, &size);
}