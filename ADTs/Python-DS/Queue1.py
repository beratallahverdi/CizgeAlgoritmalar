# We can easily implement our own Queue class using a list
class Queue:
  def __init__(self):
    self.Q = []         # Queue list

  # Enqueue an object to the end of the Queue 
  def add(self, item): self.Q.append(item)

  # Return the item at the front of the queue without removing it
  def front(self):
    if len(self.Q) == 0: return None
    else:                return self.Q[0]

  # Removes the item at the front of the queue and returns it     
  def remove(self):
    if len(self.Q) == 0: return None
    else:                
       item = self.Q[0]
       self.Q.remove(item)
       return item
    
  # Returns true if the queue is empty, false otherwise
  def isEmpty(self):
    if len(self.Q) == 0: return True
    else               : return False
    
       
# Test code for the Queue        
Q = Queue()
print("Adding 1 to the Q")
Q.add(1)

print("Adding 2 to the Q")
Q.add(2)

print("Adding Ali to the Q")
Q.add("Ali")

print("Adding 4.5 to the Q")
Q.add(4.5)

print("Item at the front of the Q: {}".format(Q.front()))
print("Removing the item at the front of the Q: {}".format(Q.remove()))

print("Adding Veli to the Q")
Q.add("Veli")

print("Adding 10 to the Q")
Q.add(10)

str = "Removing all Q elements: "
while Q.isEmpty() == False: str += "{}, ".format(Q.remove())
print(str)

if Q.isEmpty(): print("Q is empty")
else: print("Q is not empty")

