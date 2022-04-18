class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        O(N^2) algorithm
        """
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return [-1, -1]  # No such pair
        