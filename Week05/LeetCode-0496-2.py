class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        O(m+n) algorithm with O(n) extra space
        """
        S = []
        myMap = dict()
        for num in nums2[-1::-1]:
            while len(S) != 0 and num > S[-1]:
                S.pop()
             
            if len(S) == 0:
                myMap[num] = -1
            else:
                myMap[num] = S[-1]
            S.append(num)
        
        result = []
        for num in nums1:
            result.append(myMap[num])
        return result