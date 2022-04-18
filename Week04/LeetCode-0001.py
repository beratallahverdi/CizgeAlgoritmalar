class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        O(N) algorithm with O(N) extra space
        """
        myMap = dict()
        
        for i in range(len(nums)):
            otherNum = target-nums[i]
            if otherNum in myMap:
                return {myMap[otherNum], i}
            else:
                myMap[nums[i]] = i
        return {-1, -1}

        