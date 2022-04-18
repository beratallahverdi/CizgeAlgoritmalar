# We can also use the deque class from collections
from collections import deque

# Test code for the stack        
S = deque()
print("Adding 1 to the Stack")
S.append(1)

print("Adding 2 to the Stack")
S.append(2)

print("Adding Ali to the Stack")
S.append("Ali")

print("Adding 4.5 to the Stack")
S.append(4.5)

print("Item at the top of the stack: {}".format(S[-1]))
print("Removing the item at the top of the stack: {}".format(S.pop()))

print("Adding Veli to the Stack")
S.append("Veli")

print("Adding 10 to the Stack")
S.append(10)

str = "Popping off all stack elements: "
while S: str += "{}, ".format(S.pop())
print(str)
