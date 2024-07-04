'''
a heap is not necessarily sorted (only in terms of parent < children)



'''

class Heap:
    def __init__(self) -> None:
        pass

    def parent(self, index):
        return self.heap[self.get_parent_index[index]]