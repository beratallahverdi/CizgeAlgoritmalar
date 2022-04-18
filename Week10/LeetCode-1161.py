# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        maxSum = -(1<<31)
        maxLevel = -1
        
        Q = []
        Q.append(root)
        level = 0
        
        while len(Q) > 0:
            n = len(Q)  # Number of nodes at this level
            sum = 0     # Sum of the node values at this level
            level += 1
            for i in range(n):
                p = Q.pop(0)
                sum += p.val
                if p.left is not None: Q.append(p.left)
                if p.right is not None: Q.append(p.right)

            if sum > maxSum:
                maxSum = sum
                maxLevel = level        
        return maxLevel