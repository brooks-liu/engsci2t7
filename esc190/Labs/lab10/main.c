#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void create_LL(node **p_head, int *data, int size)
{
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node *cur = (node *)malloc(sizeof(node));
    cur->data = data[0];
    *p_head = cur;
    for(int i = 1; i < size; i++){
        cur->next = (node *)malloc(sizeof(node));
        cur->next->data = data[i];
        cur = cur->next;
    }
    cur->next = NULL;
}

void print_LL(node *head)
{
    // head is always the (address of) node we're currently printing
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
}

void insert_LL(node **p_head, int ind, int num)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = num;
    // insert num at index ind
    if(ind == 0){
        new->next = *p_head;
        *p_head = new;
    }
    else{
        // go through the linked list until node i-1
        // insert the new node after i-1
        node *cur = *p_head;
        for(int i = 0; i < ind - 1; i++){
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }

}

// q3a
// Function to check if two airports are directly linked
int are_linked(node *airport1, node *airport2) {
    node *cur = airport1;
    while (cur != NULL) {
        if (cur->data == airport2->data) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

typedef struct vertex {
    char *value;
    struct vertex **neighbours;
    int num_neighbours;
} vertex;

int main() {
    // Creating airports
    vertex *yyz = (vertex *)malloc(sizeof(vertex));
    yyz->value = "YYZ";
    yyz->num_neighbours = 2;
    yyz->neighbours = (vertex **)malloc(yyz->num_neighbours * sizeof(vertex *));
    
    vertex *yvr = (vertex *)malloc(sizeof(vertex));
    yvr->value = "YVR";
    yvr->num_neighbours = 3;
    yvr->neighbours = (vertex **)malloc(yvr->num_neighbours * sizeof(vertex *));
    
    vertex *yul = (vertex *)malloc(sizeof(vertex));
    yul->value = "YUL";
    yul->num_neighbours = 2;
    yul->neighbours = (vertex **)malloc(yul->num_neighbours * sizeof(vertex *));
    
    vertex *yxy = (vertex *)malloc(sizeof(vertex));
    yxy->value = "YXY";
    yxy->num_neighbours = 1;
    yxy->neighbours = (vertex **)malloc(yxy->num_neighbours * sizeof(vertex *));
    
    yyz->neighbours[0] = yvr;
    yyz->neighbours[1] = yul;
    yvr->neighbours[0] = yyz;
    yvr->neighbours[1] = yul;
    yvr->neighbours[2] = yxy;
    yul->neighbours[0] = yyz;
    yul->neighbours[1] = yvr;
    yxy->neighbours[0] = yvr;

    node *tor = NULL;
    node *van = NULL;
    node *mon = NULL;
    node *whi = NULL;

    vertex *airports[] = {yyz, yvr, yul, yxy};
    node airport_lists[] = {tor, van, mon, whi};

    for (int i = 0; i < 4; i++) {
        create_LL(&airport_lists[i], airports, airports[i]->num_neighbours);
    }

    printf("%s\n", are_linked(tor, van) ? "True" : "False");
    printf("%s\n", are_linked(tor, whi) ? "True" : "False");
    return 0;
}
