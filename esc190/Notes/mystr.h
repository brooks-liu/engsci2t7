#if !defined(MYSTR_H)
#define MYSTR_H 

typedef struct mystr{
    char* str;
    int len;

}mystr;

void mystr_create(mystr* ps, const char* str, int len);
void mystr_cat(mystr* pdest, const mystr* psource);
void mystr_destroy(mystr* ps);


#endif