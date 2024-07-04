'''binary search tree
implement as a set -> insert, delete, is element? are the functions

left descendents are smaller than parents, right is larger than parent (everything to the left is smaller, everything to right is larger)
at most two children

search is intuitive, and it is O(logn)

tree does not have to be complete
'''

class Node:
  def __init__(self, key):
      self.left = None
      self.right = None
      self.val = key


def make_tree():
  root = Node(3)
  root.left = Node(2)
  root.right = Node(5)
  root.left.left = Node(0)
  root.left.right = Node(2)
  return root
   #     3
  #    /  \
  #   1   5
  # / \
  # 0  2
    
tree = make_tree()

def search(root, key):
   #return true iff key (think: value) is in tree with root root
   if root is None:
      return False  # tree is empty
   if root.val == key:
      return True
   
   if key < root.val:
      return search(root.left, key)
   else:
      return search(root.right, key)
   


'''hash tables
Map ADT is a dictionary  (key: value pairs, where keys must be unique)

implementation is similar to Node above, just with a self.value variable (for key->value pair)

how to make it fast:
use an array of values -> O(1) access, but the array may need to be massive


say want to convert charlie into an integer, Charlie in ASCII is 67 104 97 114 108 105 101
ord(c) to get ASCII value of letter


'''

