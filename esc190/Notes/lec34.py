# recursive depth first search

'''DFS is pretty easy, bc you just call itself on itself
DFS(6) + DFS(4)     first call DFS(6) and that calls everything linked to 6 
  |        |
DFS(5)   DFS(3)    etc.

'''


def enum_all(prefix, score, path):
    '''sum to 21'''
    if score >= 21:
        path.append(prefix)
        return
    if score == 20:
        enum_all(prefix + '1', score + 1, path)
    else:
        enum_all(prefix + '1', score + 1, path)
        enum_all(prefix + '2', score + 2, path)

def enum_all_stack(prefix, score, path):
   '''depth first search b/c stack'''
   stack = [(prefix, score)]
   while stack:
       prefix, score = stack.pop()
       if score >= 21:
           path.append(prefix)
           continue
       stack.append((prefix + '1', score + 1))
       stack.append((prefix + '2', score + 2))
   return path

print(enum_all_stack('', 0, []))

# can also implement these for integrals


#priority queue:

'''
insert("esc194", 4)
insert("esc190", 0)
insert("esc195", 3)


lower index is first

pop()  // ESC190
pop()  // ESC195
pop()  // ESC194

'''

class PriorityQueue:
    def __init__(self) -> None:
        self.queue = []

    def insert(self, value, priority):
        self.queue.append((priority, value))
        self.queue.sort()
    
    def pop(self):
        return self.queue.pop(0)[1]

# pop is O(1)
# insert is O(nlogn)