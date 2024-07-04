import numpy as np

def make_adjacency_matrix(size: int, neighbours: dict):
    adj_matrix = np.zeros((size, size))
    nodes = sorted(list(neighbours.keys()))
    node_indices = {}
    for i, node in enumerate(nodes):
        node_indices[node] = i

    for node, neighbours in neighbours.items():
        for neighbour in neighbours:
            adj_matrix[node_indices[node], node_indices[neighbour]] = 1
    
    return adj_matrix, node_indices

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


if __name__ == "__main__":
    graph = {
        "1": ["3", "6"],
        "2": ["3", "5"],
        "3": ["1", "2", "4", "5"],
        "4": ["3", "5"],
        "5": ["2", "3", "4", "6"],
        "6": ["1", "5"]
    }
    matrix, indices = make_adjacency_matrix(6, graph)
    print(matrix)
    
    print("DEPTH FIRST")
    BFS(matrix, indices)
    print("\nDEPTH FIRST")
    DFS(matrix, indices)