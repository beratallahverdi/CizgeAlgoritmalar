class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        O(NlogN) algorithm with O(N) extra space
        """
        # O(N) to create the temporary array
        A = []
        for i in range(len(nums)):
            A.append([nums[i], i])
        
        # NlogN to sort
        A.sort()
        
        # O(N) to find the pair
        i = 0
        j = len(A)-1
        while i < j:
            total = A[i][0] + A[j][0]
            if total == target: 
                return [A[i][1], A[j][1]]
            elif total < target:
                i += 1
            else:
                j -= 1        
        return [-1, -1]  # No such pair
        