class DLinkedListNode:
    def __init__(self, item):
        self.item = item
        self.prev = None
        self.next = None
        
class DLinkedList:
    def __init__(self):
        self.head = self.tail = None
    
    def addFront(self, item):
        node = DLinkedListNode(item)
        if self.head == None:
            self.head = self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node
        return node
        
    def append(self, item):
        node = DLinkedListNode(item)
        if self.head == None:
            self.head = self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
        return node

    def remove(self, node):
        if node == self.head:
            self.head = self.head.next
            if self.head == None:
                self.tail = None
            else:
                self.head.prev = None
        elif node == self.tail:
            self.tail = self.tail.prev
            self.tail.next = None
        else:
            node.prev.next = node.next
            node.next.prev = node.prev
        del node
        
    def removeLast(self):
        self.remove(self.tail)

class LRUCache:
    def __init__(self, capacity: int):
        self.keys = dict()          # Stores [key, node] pairs
        self.values = DLinkedList() # Stores [key, value] pairs
        self.capacity = capacity                

    def get(self, key: int) -> int:
        if key not in self.keys: return -1   # Not found

        # Move the node storing the value to the beginning of the list
        # This is the most recently used key now
        node = self.keys[key]
        item = node.item
        self.values.remove(node)
        node = self.values.addFront(item)
        self.keys[key] = node
        return item[1]

    def put(self, key: int, value: int) -> None:
        if key not in self.keys:
            # The key does not exist. Insert it to the front of the list & also to the keys
            # If the capacity is full, then remove the LRU key first
            if len(self.keys) == self.capacity:
                oldKey, _ = self.values.tail.item
                self.values.removeLast()
                self.keys.pop(oldKey)

            # Insert the new <key, value> pair at the front of the values list
            node = self.values.addFront([key, value])
            self.keys[key] = node

        else:            
            # Update the value & move the node storing the value to the beginning of the list
            node = self.keys[key]
            self.values.remove(node)
            node = self.values.addFront([key, value])
            self.keys[key] = node
            
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

