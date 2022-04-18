class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        O(N^2) solution        
        """
        result = []
        for num1 in nums1:
            if num1 in nums2:
                if num1 not in result:
                    result.append(num1)
        return result
