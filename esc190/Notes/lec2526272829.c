// project2:
// intensity goes from 0 to 255 --- 0 0 0 is black (zero red, zero green, zero blue)
// if r~g~b then its a greyish colour
// 10 200 10 is green
// a seam is where it looks the same on the left and the right
// if image changes a lot in brightness it is higher energy (so for a low energy seam)
// R(X) is energy of red at x+1 - energy of red at x-1 for the same y value

/*use indices to simulate an n-dimensional table

store image as 1-D array, reading everything top-bottom, left-right

im_flat = [10, 20, 20, 50....., 10]

want to access pixel (2, 0)
skip 2 rows, then skip 0 columns
so 2 * (3 * 2) + 0 * 3  is the location of the pixel (since 2 rows down and 2 sets of rgb numbers in each row and zero columsn across in this example)

to access G channel, add 1 to that.
to access B, add 2.

channel k (colour, R = 0, G = 1, B = 2) of pixel (i, j):
width w, number of channels c
we have i * (w * c) + j * c + k  as the location of the pixel in the array

*/


/*file IO for binary datawant to write an image to a file
an image is just a block of numbers, and we made it an array as above
could store the raster as text, but needs to split at commas, [], ignore spaces, etc.
if all numbers have at most three digits, no need for commas
if all numbers are between 0 and 255 then can store it more efficiently in binary (you need more bytes for each digit rather than just 1's and 0's)

to write a block of memory to a file:
fwrite(block, sizeof(__UINT8_C), num_elements, FP);
this writes the block of memory, consistent of num_elements of size sizeof(...) to the file pointed to by fp

to read a block of memory from a file:
fread(block, sizeof(...), num_elements, fp);

to read/write images, need meta-data:
# of channels (like maybe RGB + alpha, meaning with transparency), width, height, colour depth (above 255)


*/


/*graphs

graph G = (V, E)  with vertices V and edges E
e1 would be the connection between v1 and v2, for example (its a pair of vertices that it connects)
if theres nothing connected to one of the vertices, can safely remove it (if want to)

you can also have directed graphs -- "digraphs", ie. you can go from one to the other but not necessarily go back
these have pairs st. the first is the predessecor and the second is the successor

could also have weighted graphs (with weight representing cost, time, etc.)

v1 and v2 are adjacent if there exists an edge between them
a path is a sequence of vertices in which each vertice is adjacent to the next
length of a path is the number of edges in it (not vertices)
a cycle in a path is a path that is connected at the end
a graph without cycles is acyclic
a DAG is acyclic and now directed graphs
simple path has no repetition of vertices
simple cycle has no reptition of vertices
two vertices are connected if theres a path between them
a subset of vertices is a connected component of G if each pair of the vertices in the subset are connected
degree of vertex v is number of edges associated with v

implementation:
use an nxn (number of vertices) matrix M called the adjacency matrix and M[i][j] = 1 if theres an edge there, 0 if not
could also store the weight or the directionality (store the weights as infinity if not defined)
OR
for n = v vertices, have n linked lists, with the i-th list being the vertices adjacent to vi (called adjacency list)
can also store weight or diretionality

a linked list is kind of a graph

for an adjacency list (linked list storage type for a graph)
the max time taken to see if theres a connection between vi and vf, 
traverse a linked list that stores connections to a node, need at most O(d) time
where d is the max degree of the graph


find all adjacent vertices:
adjacency matrix is O(V) - number of vertices on the graph
adjacency list - O(d)

space requirements:
Adjacency matrix is O(V^2) because there are v^2 entries
adjacency list O(|E|+|V|) where |V| is the space of the linked lists, |E| is the number of entires in all lists

also see graph.py and graphs_hash.py and adjacency_matric_with_hashgraph.py

*/

