# Python queue class has an implementation for a FIFO Queue class
# This is useful for multi-threaded code (producer/consumer) type applications
# For details look at: https://docs.python.org/3/library/queue.html
from queue import Queue

# Test code for the Queue        
Q = Queue()
print("Adding 1 to the Q")
Q.put(1)

print("Adding 2 to the Q")
Q.put(2)

print("Adding Ali to the Q")
Q.put("Ali")

print("Adding 4.5 to the Q")
Q.put(4.5)

#print("Item at the front of the Q: {}".format(Q.peek()))  # peek does not exist in Queue
print("Removing the item at the front of the Q: {}".format(Q.get()))

print("Adding Veli to the Q")
Q.put("Veli")

print("Adding 10 to the Q")
Q.put(10)

str = "Removing all Q elements: "
while not Q.empty(): str += "{}, ".format(Q.get())
print(str)

if Q.empty(): print("Q is empty")
else: print("Q is not empty")

