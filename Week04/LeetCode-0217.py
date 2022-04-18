class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        O(N) algorithm with O(N) extra space
        """
        mySet = set()
        for num in nums:
            if num in mySet:
                return True
            else:
                mySet.add(num)        
        return False
