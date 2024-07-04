# first in first out

q = [4, 5, 6]
# enqueue -> add object to end of queue
# dequeue -> remove first objectin line from queue and return the value

class Queue:
    def __init__(self) -> None:
        self.q = []
    
    def enqueue(self, elem):
        self.q.insert(0, elem)  # O(n)

    def dequeue(self):
        return self.q.pop()  # O(1)

    def __repr__(self):
        return f"Last -> {self.q} <- Last"

# could also make it so enqueue and dequeue are both O(1) by using a linked list (as long as you keep track of begining and end)
# or use a circular array