#if !defined(PYINT_H)
#define PYINT_H

typedef struct pyint{
    int* buffer; //stored backwards
    int length;
}pyint;

void create_pyint(pyint** p, int length);
void destroy_pyint(pyint* p);
void set_pyint(pyint* p, int value);
void print_pyint(pyint* p);
void add_pyint(pyint* p, int value);
void plusplus(pyint* p);


#endif