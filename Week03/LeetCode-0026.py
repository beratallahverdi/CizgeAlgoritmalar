class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """O(N) algorithm"""
        if len(nums) <= 1: return len(nums)
        k = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[k]:
                k += 1
                nums[k] = nums[i]
        return k+1        