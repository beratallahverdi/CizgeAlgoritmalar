class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        """
        O(N) algorithm with O(N) extra space
        """
        myMap = dict()
        for i in range(len(nums)):
            if nums[i] in myMap:                
                if i-myMap[nums[i]] <= k:
                    return True
            myMap[nums[i]] = i        
        return False
        