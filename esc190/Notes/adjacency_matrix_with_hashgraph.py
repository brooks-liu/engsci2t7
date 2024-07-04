# want to store edges as adjacency matrix
import numpy as np

# adj matrix: M[i, j] is 1 if nodes i and j are linked by an edge
# are k and l linked? see if M[k, l] == 1
# average access is O(1), worst is O(1)

class Node:  # means graph vertex
    def __init__(self, value):
        self.value = value
        self.neighbours = set()  # O(1) to lookup and insert on average, O(n) worst case (unless you get extremely unlucky)

def are_nodes_linked(node1: Node, node2: Node):
    # linked if there's an edge between node1 and node2, assume nondirected
    # if its directed, then you need to check both ways
    return node2 in node1.neighbours

def get_node_by_str(nodes: dict, node_str):
    return nodes.get(node_str, None)  #returns None if not in there

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str, airport2_str)
    airport2 = get_node_by_str(airports, airport1_str, airport2_str)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked(airport1, airport2)


def make_airport_graph1():
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    yxy = Node("YXY")

    yyz.neighbours = set([yvr, yul])
    yvr.neighbours = set([yyz, yul, yxy])
    yul.neighbours = set([yyz, yvr])
    yxy.neighbours = set([yvr])

    airport_dictionary = {}
    for airport in [yyz, yvr, yul, yxy]:
        airport_dictionary[airport.value] = airport

    return airport_dictionary 

def convert_to_adj_matrix(airports: dict):
    adj_matrix = np.zeros(len(airports), len(airports))
    airport_callsigns = sorted(list(airports.keys()))
    airport_callsign_indices = {}
    for i, airport_callsigns in enumerate(airport_callsigns):
        airport_callsign_indices[airport_callsigns] = i

    for airport_callsigns, airport in airports.items():
        for neighbour in airport.neighbours:
            adj_matrix[airport_callsign_indices[airport_callsigns], airport_callsign_indices[neighbour.value]] = 1
            # works with directed and nondirected
    
    return adj_matrix, airport_callsign_indices


if __name__ == "__main__":
    airports = make_airport_graph1()
    print("Toronto is connected to Montreal?", are_airports_linked(airports, "YYZ", "YUL"))
    # complexity of are_airports_linked() using hash:
    # O(1) on average to find airport 1 and 2
    # are nodes linked? look up in dict is O(1)
    # whole thing is now O(1) ON AVERAGE, worst is still O(n)

    # a few tradeoffs: need to create a dictionary
    # dictionaries and sets take up more space
