class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        O(m+n) algorithm with O(m+n) extra space
        """
        # Create two HashSets from nums1 and nums2
        set1 = set()
        for num in nums1: set1.add(num)

        set2 = set()
        for num in nums2: set2.add(num)
            
        result = []
        for num in set1:
            if num in set2:
                result.append(num)
        return result
