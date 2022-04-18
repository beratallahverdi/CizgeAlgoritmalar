class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        O(N^2) algorithm
        """
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] == nums[j]:
                    return True
        return False