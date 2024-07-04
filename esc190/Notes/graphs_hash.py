# couple changes: using sets instead of lists, using dictionaries instead of lists

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


if __name__ == "__main__":
    airports = make_airport_graph1()
    print("Toronto is connected to Montreal?", are_airports_linked(airports, "YYZ", "YUL"))
    # complexity of are_airports_linked() using hash:
    # O(1) on average to find airport 1 and 2
    # are nodes linked? look up in dict is O(1)
    # whole thing is now O(1) ON AVERAGE, worst is still O(n)

    # a few tradeoffs: need to create a dictionary
    # dictionaries and sets take up more space
