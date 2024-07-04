class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = set() # O(1) to look up and insert on average
                                # O(n) in the worst case

def are_nodes_linked(node1, node2):
    # node1 and node2 are linked if there is an edge between
    # node1 and node2
    # Assume graph is undirected
    return node2 in node1.neighbours  # don't need to check that node1 is in node2.neighbours


def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)
    # for node in nodes:
    #     if node.value == node_str:
    #         return node
    # return None

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str)
    airport2 = get_node_by_str(airports, airport2_str)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked(airport1, airport2)



def make_airport_graph1():
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    whitehorse = Node("Whitehorse")

    yyz.neighbours = set([yvr, yul])
    yvr.neighbours = set([yyz, yul, whitehorse])
    yul.neighbours = set([yyz, yvr])
    whitehorse.neighbours = set([yvr])

    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport
    
    return airport_dict


def convert_to_adj_matrix(airports):
    adj_matrix = np.zeros((len(airports), len(airports)))
    airport_callsigns = sorted(list(airports.keys()))
    airport_callsigns_idx = {}
    for i, airport_callsign in enumerate(airport_callsigns):
        airport_callsigns_idx[airport_callsign] = i

    for airport_callsign, airport in airports.items():
        for neighbour in airport.neighbours:
            adj_matrix[airport_callsigns_idx[airport_callsigns], airport_callsigns_idx[neighbour.value]] = 1
            # adj_matrix[airport_callsigns_idx[neighbour.value], airport_callsigns_idx[airport_callsign]] = 1

    return adj_matrix, airport_callsigns_idx





if __name__ == '__main__':
    airports = make_airport_graph1()
    print("Toronto (YYZ) is connected to Montreal (YUL)?", are_airports_linked(airports, "YYZ", "YUL"))