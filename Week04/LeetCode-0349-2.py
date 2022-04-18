class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        O(m+n) algorithm with O(1) extra space using a LUT
        """
        maxNum = 1000
        lut1 = [0]*(maxNum+1)
        for num in nums1: lut1[num] = 1

        result = []
        for num in nums2:
            if lut1[num] == 1:
                result.append(num)
                lut1[num] = 0  # To avoid duplicates in the result
        return result        
        