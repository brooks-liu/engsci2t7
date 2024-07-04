class Queue:
    def __init__(self):
        self.data = []

    def enqueue(self, item):
        self.data.append(item)   # O(n) worst-case, usually O(1)

    def dequeue(self):
        # return self.data.pop()
        ret_val = self.data[0]
        del self.data[0] # O(n), because need to move self.data[1:] to self.data[0:]
        return ret_val    
    
