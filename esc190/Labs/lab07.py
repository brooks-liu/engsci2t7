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
    
class CirQueue:
    def __init__(self, size):
        self.data = [None] * size
        self.size = size
        self.start = 0
        self.end = 0

    def enqueue(self, item):
        b = 1
        for i in range(self.size):
            if self.data[i] != None:
                b = 0
        if b == 0:
            if self.end == self.size - 1:
                self.end = 0
            else:
                self.end += 1
            self.data[self.end] = item
        else:
            self.data[0] = (item) 

    def dequeue(self):
        # return self.data.pop()
        ret_val = self.data[self.start]
        self.data[self.start] = None
        if self.start == self.size - 1:
            self.start = 0
        else:
            self.start += 1
        return ret_val    
    
    def __str__(self):
        return f"Index: 0   1   2   3   4   5\n{self.data[0]}  {self.data[1]}  {self.data[2]}  {self.data[3]}  {self.data[4]}  {self.data[5]}\nStart: {self.start}, End: {self.end}"
    
    def __lt__(self, other):
        size1 = self.end - self.start + 1
        size2 = other.end - other.start + 1 
        arr1 = []
        arr2 = []
        if self.start + size1 - 1 >= self.size:
            a = size1
            for i in range(self.start, self.size):
                arr1.append(self.data[i])
                a -= 1
            for i in range(a):
                arr1.append(self.data[i])
        else:
            for i in range(self.start, self.end + 1):
                arr1.append(self.data[i])
        
        if other.start + size2 - 1 >= other.size:
            b = size2
            for i in range(other.start, other.size):
                arr2.append(other.data[i])
                b -= 1
            for i in range(b):
                arr2.append(other.data[i])
        else:
            for i in range(other.start, other.end + 1):
                arr2.append(other.data[i])

        for i in range(min(size1, size2)):
            if arr1[i] < arr2[i]:
                return True
            elif arr1[i] == arr2[i]:
                continue
            else:
                return False
        
        if size1 == size2:
            return "Equal"
        elif size1 < size2:
            return True
        else:
            return False
        

    

'''array = CirQueue(6)
print(array)
array.enqueue(0)
array.enqueue(1)
print(array)
array.enqueue(2)
array.enqueue(3)
print(array)
array.dequeue()
print(array)'''



arr1 = CirQueue(6)
arr1.enqueue(0)
arr1.enqueue(1)
arr1.enqueue(2)
arr1.enqueue(3)
arr2 = CirQueue(6)
arr2.enqueue(0)
arr2.enqueue(0)
arr2.enqueue(1)
arr2.enqueue(3)
arr2.dequeue()
x = [arr2, arr1]
x.sort()
print(x[0])