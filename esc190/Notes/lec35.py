'''priority queue has three functions:
insert(S, x): add an element with priority x
min(S)
extract_min(S): removes smallest value

if use array/linked list -> O(1) for insert and O(n) for min and extract_min
if use sorted array/LL -> O(n) for insert, O(1) for insert and extract_min

to make it better, use heaps:
a heap is a binary tree that is full (with every node with two children except the leaves and the far right on the second last level)
heap order property

if we set the parents as always smaller than the children, we can know the exact position of an item since the heap is sorted 
but in layers

if we had a tree of 1, 2, 3, 4, 5 ... in a heap,
to get the index of the parent, just do integer division of any of its children by 2  (so 7 would be a child of 3 and 3 is a child of 1)


heap operations insert -> put new value at bottom level of the heap, then fix the tree to be in order of prio again
percolate the value unti lit is at the right spot (switch it with its parent)

extract_min -> extracting removes a value, so replace the value with the last element in the heap, and then percolate the element to the correct spot



insert(x):
    k = n + 1
    pq[k] = x
    while(k > 1 and pq[k/2] > pq[k]):
        swap(pq[k], pq[k/2])
        k = k/2


        
'''

