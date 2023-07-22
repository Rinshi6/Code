class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
  
# /* Function to find the only person left
#    after one in every m-th node is killed
#    in a circle of n nodes */
def getJosephusPosition(m, n):
    
    # Create a circular linked list of
    # size N.
    head = Node(1)
    prev = head
    for i in range(2, n + 1):
        prev.next = Node(i)
        prev = prev.next
    prev.next = head # Connect last
                       #node to first
  
    #/* while only one node is left in the
    #linked list*/
    ptr1 = head
    ptr2 = head
    p = []
    while (ptr1.next != ptr1):
        # Find m-th node
        count = 1
        while (count != m):
            ptr2 = ptr1
            ptr1 = ptr1.next
            count += 1
  
        # /* Remove the m-th node */
        ptr2.next = ptr1.next
        p.append(ptr2.data)
        # free(ptr1)
        ptr1 = ptr2.next
  
    print( ptr1.data)
    for i in range(1, n-1):
        print (p[i])
  
# /* Driver program to test above functions */
if __name__ == '__main__':
    n = int(input()) # specific n and k  values for original josephus problem
    k = int(input())
    getJosephusPosition(k, n)