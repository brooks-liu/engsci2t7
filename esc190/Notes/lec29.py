# consider something like adjacency_matric_with_hashgraph
# to traverse a large graph

# if we want to print each vertex exactly once we'd visit neighboursof the starting node, then visit the neighbours of those
# unless they've already been visited, and then we'd get to the entire list (assuming connected)

'''
while (there are non-visited nodes)
    initialize a data structure DS
    add nonvisited vertex vi to DS
    mark vi as visited (take it out and put in the visited list)
    put vi's neighbours in DS


    
DS: [1]   #for storing nodes that have been seen but neighbours havent been visited

keep 
(1) taking out nodes from DS
(2) adding neighbours to DS if not alr visited or in DS

while DS not empty:
    take out n from DS
    add n's neighbours (if not visited alr)

probably good to use a queue here, where the first in the queue is next to be visited
CALLED BREADTH FIRST SEARCH

instead if you made it a stack, youd traverse one option to the end (last thing you added is where you go next)
go as deep in the graph as possible
called DEPTH FIRST SEARCH
'''