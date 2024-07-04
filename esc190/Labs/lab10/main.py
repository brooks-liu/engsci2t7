# q1

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LL:
    def __init__(self, data):
        self.head = Node(data)


    def insert(self, loc, element):
        new_node = Node(element)  # data: element, next: None
        if loc == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            cur = self.head
            for i in range(loc-1):
                cur = cur.next
            new_node.next = cur.next
            cur.next = new_node
        
    def delete(self, loc):
        if loc == 0:
            self.head = self.head.next 
        else:
            cur = self.head
            for i in range(loc-1):
                cur = cur.next
            # cur is the node before the node that we want to delete
            cur.next = cur.next.next

class Vertex:  
    def __init__(self, value):
        self.value = value
        self.neighbours = [] 

def make_airport_graph1():
    yyz = Vertex("YYZ")
    yvr = Vertex("YVR")
    yul = Vertex("YUL")
    yxy = Vertex("YXY")

    yyz.neighbours = [yvr, yul]
    yvr.neighbours = [yyz, yul, yxy]
    yul.neighbours = [yyz, yvr]
    yxy.neighbours = [yvr]

    Tor = LL(yyz)
    Van = LL(yvr)
    Mon = LL(yul)
    Whi = LL(yxy)

    for airport, LLhead in [(yyz, Tor), (yvr, Van) , (yul, Mon), (yxy, Whi)]:
        for i in range(len(airport.neighbours)):
            LLhead.insert(i+1, airport.neighbours[i])

    return [Tor, Van, Mon, Whi]

# q2
def are_linked(airport1: LL, airport2: LL):
    cur = airport1.head
    while cur.next != None:
        if cur.data == airport2.head.data:
            return True
        cur = cur.next
    
    return False




if __name__ == "__main__":
    airports = make_airport_graph1()
    print(are_linked(airports[0], airports[1]))
    print(are_linked(airports[0], airports[3]))
