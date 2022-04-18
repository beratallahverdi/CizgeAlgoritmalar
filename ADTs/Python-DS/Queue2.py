# Python collections library has a deque implementation that can be used as a Queue
from collections import deque

# Test code for the Queue        
Q = deque()
print("Adding 1 to the Q")
Q.append(1)

print("Adding 2 to the Q")
Q.append(2)

print("Adding Ali to the Q")
Q.append("Ali")

print("Adding 4.5 to the Q")
Q.append(4.5)

print("Item at the front of the Q: {}".format(Q[0]))  # peek does not exist in Queue
print("Removing the item at the front of the Q: {}".format(Q.popleft()))

print("Adding Veli to the Q")
Q.append("Veli")

print("Adding 10 to the Q")
Q.append(10)

str = "Removing all Q elements: "
while Q: str += "{}, ".format(Q.popleft())
print(str)

if Q: print("Q is not empty")
else: print("Q is empty")

