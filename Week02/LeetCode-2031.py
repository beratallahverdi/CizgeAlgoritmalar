class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        result = []
        for num1 in nums1:
            if num1 in nums2 or num1 in nums3:
                if num1 not in result:
                    result.append(num1)
                    
        for num2 in nums2:
            if num2 in nums3:
                if num2 not in result:
                    result.append(num2)
                    
        return result