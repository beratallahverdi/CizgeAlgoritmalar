class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        """
        O(k+m+n) algorithm with O(1) extra space, where
        k = len(nums1), m = len(nums2), n = len(nums3)
        We make use of the fact that numbers are in between 1<=num<=100 and use a LUT
        """        
        maxNum = 100
        # We will use a LUT to mark the numbers that occur in each list
        lut1 = [0]*(maxNum+1)
        for num in nums1: lut1[num] = 1

        lut2 = [0]*(maxNum+1)
        for num in nums2: lut2[num] = 1
            
        lut3 = [0]*(maxNum+1)
        for num in nums3: lut3[num] = 1

        result = []
        for num in range(1, maxNum+1):
            count = lut1[num] + lut2[num] + lut3[num]
            if count >= 2:
                result.append(num)
        return result
                