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

import queue

# class Queue:
#     def __init__(self):
#         self.q = []

#     def enqueue(self, elem):
#         self.q.insert(0, elem)

#     def dequeue(self):
#         return self.q.pop()
    
#     def __repr__(self):
#         return f"Queue: LAST IN-> {self.q} <- FIRST IN"


q1 = queue.Queue()
q1.enqueue(10)
q1.enqueue(20)
q1.dequeue()
q1.enqueue(5)
print(q1)