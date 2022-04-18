class Solution:
    def InsersectSet(self, nums1, nums2, result):
        i, j = 0, 0
        while i<len(nums1) and j<len(nums2):
            if (nums1[i] == nums2[j]):
                result.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]: i+= 1
            else: j += 1

    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        # Sort the arrays
        nums1.sort()
        nums2.sort()
        nums3.sort()
        
        result = []
        self.InsersectSet(nums1, nums2, result)
        self.InsersectSet(nums1, nums3, result)
        self.InsersectSet(nums2, nums3, result)
                        
        if len(result)<=1: return result
        
        # Eliminate the duplicates from the result
        result.sort()
        k = 0
        for i in range(1, len(result)):
            if result[i] != result[k]:
                k += 1
                result[k] = result[i]
        return result[:k+1]