# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    # This is the efficient O(nlogk) algorithm
        if len(lists) == 0: return None
        if len(lists) == 1: return lists[0]
        
        # Create the initial heap
        H = []
        for i in range(len(lists)):
            if lists[i] != None:
                heapq.heappush(H, [lists[i].val, i])
        
        head = tail = None 
        while len(H) > 0:
            val, index = heapq.heappop(H)
            
            if head == None:
                head = tail = lists[index]
            else:
                tail.next = lists[index]
                tail = lists[index]
            lists[index] = lists[index].next
            tail.next = None
            
            if lists[index] != None:
                heapq.heappush(H, [lists[index].val, index])
        return head
        