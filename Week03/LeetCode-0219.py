class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        """
        O(NlogN) algorithm
        """
        A = []
        for i in range(len(nums)):
            A.append([nums[i], i])            

        # Sort A
        A.sort()
            
        # Walk over the sorted array
        for i in range(1, len(A)):
            if A[i][0] == A[i-1][0]:
                if abs(A[i][1]-A[i-1][1]) <= k:
                    return True            
        return False
        