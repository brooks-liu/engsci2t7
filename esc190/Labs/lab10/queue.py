# Want to make a Queue class
# Queue: first in, first out

q = [7, 4, 5]
#enqueue(10)
q = [10, 7, 4, 5]
#dequeue() -> 5
q = [10, 7, 4]
#dequeue() -> 4
q = [10, 7]

# enqueue: add an object to the queue
# dequeue: remove the first object in line from the queue and return its value

# q: [50, 10, 8, 12, 4]

class Queue:
    def __init__(self):
        self.q = []

    def enqueue(self, elem):
        self.q.insert(0, elem) # O(n), where n is len(self.q)

    def dequeue(self):
        return self.q.pop() # O(1)
    
    def __repr__(self):
        return f"Queue: LAST IN-> {self.q} <- FIRST IN"


# Idea 0: O(1) for enqueue using append, O(n) for dequeue using pop(0)

# Idea 1 for O(1) enqueue and dequeue
# Linked list:
    # A->B->C->D->E (needs to doubly linked, so that D has a link to C)
    # To enqueue, add to the end (O(1) if you keep track of the node before last at the end currently)
    # To dequeue, remove the first node (O(1) if you keep track of the head node currently)

# Idea 2 for O(1) (almost) enqueue and dequeue
    # Use a circular array
    [   ,  , , , F, G, H, X, ]
    # keep track of the last and first index
    # to enqueue Y at the end, wrap around
    [Y,   ,  , , , F, G, H, X, ]

q1 = Queue()
q1.enqueue(10)
q1.enqueue(20)
q1.dequeue()
q1.enqueue(5)
print(q1)