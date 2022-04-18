class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        """
        O(N^2) algorithm: Gets Time Limit Exceeded
        """
        for i in range(len(nums)-1):
            for j in range(i+1, min(i+k+1, len(nums))):
                if abs(nums[i]-nums[j]) <= t:
                    return True        
        return False        