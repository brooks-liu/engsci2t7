/*
def BFS(adj_matrix, node_indices):
    queue = []
    traversed = []
    inv_map = {v: k for k, v in node_indices.items()}  # invert dictionary
    nodes = []

    for node, index in node_indices.items():
        nodes.append((node, index))
    
    while len(traversed) != len(adj_matrix):
        if len(queue) == 0:
            queue.append(nodes[0][0])
            print("Queue is currently:", queue)
            print("Already Traversed:", traversed)
            continue
        cur_node = queue[0]
        index = [item[1] for item in nodes if item[0] == queue[0]]

        for col in range(len(adj_matrix)):
            if adj_matrix[index, col] == 1 and inv_map[col] not in queue and inv_map[col] not in traversed:
                queue.append(inv_map[col])

        queue.pop(0)
        traversed.append(cur_node)

        print("Queue is currently:", queue)
        print("Already Traversed:", traversed)

def DFS(adj_matrix, node_indices):
    queue = []
    traversed = []
    inv_map = {v: k for k, v in node_indices.items()}  # invert dictionary
    nodes = []

    for node, index in node_indices.items():
        nodes.append((node, index))
    
    while len(traversed) != len(adj_matrix):
        if len(queue) == 0:
            queue.append(nodes[0][0])
            print("Queue is currently:", queue)
            print("Already Traversed:", traversed)
            continue

        cur_node = queue[len(queue) - 1]
        index = [item[1] for item in nodes if item[0] == queue[len(queue) - 1]]
        queue.pop()

        for col in range(len(adj_matrix)):
            if adj_matrix[index, col] == 1 and inv_map[col] not in queue and inv_map[col] not in traversed:
                queue.append(inv_map[col])
        
        traversed.append(cur_node)

        print("Queue is currently:", queue)
        print("Already Traversed:", traversed)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    int* neighbours;
    int size;
} node;

typedef struct graph {
    node* nodes;
} graph;

void make_adjacency_matrix(int size, graph graph1, int** matrix, int** nodes, int** node_indices) {
    *matrix = (int*)calloc(size * size, sizeof(int));
    *nodes = (int*)calloc(size, sizeof(int));
    *node_indices = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; i++){
        (*nodes)[i] = graph1.nodes[i].value;
        (*node_indices)[graph1.nodes[i].value - 1] = i;

        for(int j = 0; j < graph1.nodes[i].size; j++){
            printf("%d", i * size + (graph1.nodes[i].neighbours[j]) - 1);
            (*matrix)[i * size + (graph1.nodes[i].neighbours[j]) - 1] = 1;
        }
    }
}

void BFS(int size, int* adj_matrix, int* ndoes, int* node_indices){
    int* queue;
    int* traversed;
    int queuesize;
    int traversedsize;

    while(traversedsize != size){
        
    }
}

int main(){
    graph graph1;
    graph1.nodes = (node*)malloc(sizeof(node) * 6);
    graph1.nodes[0].value = 1;
    graph1.nodes[0].neighbours = (int*)malloc(sizeof(int) * 2) ;
    graph1.nodes[1].value = 2;
    graph1.nodes[1].neighbours = (int*)malloc(sizeof(int) * 2) ;
    graph1.nodes[2].value = 3;
    graph1.nodes[2].neighbours = (int*)malloc(sizeof(int) * 4) ;
    graph1.nodes[3].value = 4;
    graph1.nodes[3].neighbours = (int*)malloc(sizeof(int) * 2) ;
    graph1.nodes[4].value = 5;
    graph1.nodes[4].neighbours = (int*)malloc(sizeof(int) * 4) ;
    graph1.nodes[5].value = 6;
    graph1.nodes[5].neighbours = (int*)malloc(sizeof(int) * 2) ;
    graph1.nodes[0].size = 2;
    graph1.nodes[1].size = 2;
    graph1.nodes[2].size = 4;
    graph1.nodes[3].size = 2;    
    graph1.nodes[4].size = 4;
    graph1.nodes[5].size = 2;
    graph1.nodes[0].neighbours[0] = 3;
    graph1.nodes[1].neighbours[0] = 3;
    graph1.nodes[2].neighbours[0] = 1;
    graph1.nodes[3].neighbours[0] = 3;
    graph1.nodes[4].neighbours[0] = 2;
    graph1.nodes[5].neighbours[0] = 1;
    graph1.nodes[0].neighbours[1] = 6;
    graph1.nodes[1].neighbours[1] = 5;
    graph1.nodes[2].neighbours[1] = 2;
    graph1.nodes[3].neighbours[1] = 5;
    graph1.nodes[4].neighbours[1] = 3;
    graph1.nodes[5].neighbours[1] = 5;
    graph1.nodes[2].neighbours[2] = 4;
    graph1.nodes[2].neighbours[3] = 5;
    graph1.nodes[4].neighbours[2] = 4;
    graph1.nodes[4].neighbours[3] = 6;

    int size = 6;
    int* matrix;
    int* nodes;
    int *node_indices;

    make_adjacency_matrix(size, graph1, &matrix, &nodes, &node_indices);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }

    printf("DEPTH FIRST\n");
    //BFS(matrix, indices)
    printf("DEPTH FIRST\n");
    //DFS(matrix, indices)

}