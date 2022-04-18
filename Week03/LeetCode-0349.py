class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        O(NlogN) solution        
        """
        nums1.sort()
        nums2.sort()
        result = []
        
        i = 0
        j = 0
        while i<len(nums1) and j<len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
                
                # Walk over duplicates
                while i<len(nums1) and nums1[i] == nums1[i-1]:
                    i += 1

                while j<len(nums2) and nums2[j] == nums2[j-1]:
                    j += 1
                    
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return result