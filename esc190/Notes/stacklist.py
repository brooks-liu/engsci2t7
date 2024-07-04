# linked lists are better to use for stacks, since its O(1) to insert and remove at the head

class LL:
    def __init__(self) -> None:
        self.head = None

    def insert(self, loc, element):
        new_node = Node(element)  #data is element, next is none
        if loc == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            cur = self.head
            for i in range(loc - 1):
                cur = cur.next
            new_node.next = cur.next
            cur.next = new_node
    
    def delete(self, loc):
        if loc == 0:
            self.head = self.head.next
        else:
            cur = self.head
            for i in range(loc - 1):
                cur = cur.next
            cur.next = cur.next.next

class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class Stack:
    def __init__(self) -> None:
        self.stack = LL() #self.stack is LL with head == None
    
    def push(self, element):  # insert at 0
        self.stack.insert(0, element)

    def pop(self):  # remove from 0
        cur = self.stack.head
        self.stack.delete(0)
        return cur.data

n = Node(1)
