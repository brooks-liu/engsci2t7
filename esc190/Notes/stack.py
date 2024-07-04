class Stack:
    def __init__(self) -> None:
        self.stack = []

    def is_empty(self):
        return len(self.stack) == 0
    
    def push(self, element):
        return self.stack.append(element)
    
    def pop(self):
        if self.is_empty():
            print("No")
        else:
            return self.stack.pop()
    
s = Stack()
#s.stack.pop() would crash if no warning

s.push(25)
s.push(52)
print(s.stack)
print(s.pop())  # returns 52 (removes 52 from list)
print(s.stack) # prints 25
