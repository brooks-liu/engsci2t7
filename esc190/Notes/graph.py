class Node:  # means graph vertex
    def __init__(self, value):
        self.value = value
        self.neighbours = [] 

def are_nodes_linked(node1: Node, node2: Node):
    # linked if there's an edge between node1 and node2, assume nondirected
    # if its directed, then you need to check both ways
    return node2 in node1.neighbours

def get_node_by_str(nodes, node_str):
    for node in nodes:
        if node.value == node.str:
            return Node
    return None  # this is a helper

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

    yyz.neighbours = [yvr, yul]
    yvr.neighbours = [yyz, yul, yxy]
    yul.neighbours = [yyz, yvr]
    yxy.neighbours = [yvr]

    #can store graph as a list
    return [yyz, yvr, yul, yxy]  # arbitrary return of the nodes

    # in c, could have it as an array of pointers

    # complexity of finding out whether yvr has an edge to yyz?
    # O(d)
    # if want to insert, then prob want a linked list and not an array list


if __name__ == "__main__":
    airports = make_airport_graph1()
    print("Toronto is connected to Montreal?", are_airports_linked(airports, "YYZ", "YUL"))
    #complexity of are_airports_linked():
    # need to find airports O(n) (assuming strings aren't that long), need to run it twice since two airports
    # are_nodes_linked() looks through every airport in the list, O(d), d is the degree of airport1 (# of neighbours)
    # d is smaller than or equal to n
    # total run is 2*c1*n + c2*d <= 2*c1*n + c2*n --> O(n)
