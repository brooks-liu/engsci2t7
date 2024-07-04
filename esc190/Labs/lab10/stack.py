class Stack:
    def __init__(self):
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0
    
    def push(self, elem):
        self.stack.append(elem)
    
    def pop(self):
        if self.is_empty():
            print("Cannot pop from an empty stack")
        else:
            return self.stack.pop()


s = Stack()
s.stack # []

s.push(52)
s.push(125)
print(s.stack)
print(s.pop())
print(s.stack)