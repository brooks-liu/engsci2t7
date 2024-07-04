#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// q3b
typedef struct GraphNode {
    char *value;
    struct GraphNode **neighbours; //list of neighbours
    int num_neighbours; 
} GraphNode;

typedef struct node{
    GraphNode data;
    struct node *next;
} node;

void create_LL_graphnode(node **p_head, GraphNode** data, int size)
{
    if(size == 0){
        *p_head = NULL;
        return;
    }
    node *cur = (node *)malloc(sizeof(node));
    cur->next = data[0];
    *p_head = cur;
    for(int i = 1; i < size; i++){
        cur->next = (GraphNode *)malloc(sizeof(GraphNode));
        cur = cur->next;
    }
    cur->next = NULL;
}

// q3c
int is_linked(GraphNode item1, GraphNode item2, node* item1head){
    
}