class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        # Handle corner case
        if len(nums) < 2: return False
        
        # O(N) to copy
        A = []
        for i in range(len(nums)): 
            A.append([nums[i], i])
                        
        # Sort: O(NlogN)
        A.sort()
        
        # Walk over A.
        for i in range(len(A)-1):
            for j in range(i+1, len(A)):
                if abs(A[i][0]-A[j][0]) > t:
                    break
                if abs(A[i][1]-A[j][1]) <= k:
                    return True        
        return False
