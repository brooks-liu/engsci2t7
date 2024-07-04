class CircularQueue:
    def __init__(self):
        self.data = [None] * 200
        self.size = 200
        self.begin = 0
        self.end = -1

    def enqueue(self, item):
        self.end = (self.end + 1) % self.size
        self.data[self.end] = item
        

    def dequeue(self):
        ret_val = self.data[self.begin]
        self.begin = (self.begin + 1) % self.size
        return ret_val


    def to_list(self):
        L = []
        i = self.begin
        while i != self.end:
            L.append(self.data[i])
            i = (i + 1) % self.size


        return L



    def __str__(self):
        return str(self.to_list())
    

    def __lt__(self, other):
        L1 = self.to_list()
        L2 = other.to_list()
        # return L1 < L2
        for i in range(min(len(L1), len(L2))):
            if L1[i] < L2[i]:
                return True
            elif L1[i] > L2[i]:
                return False
        return len(L1) < len(L2)
