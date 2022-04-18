class Solution:
    def countFreqs(self, nums, freq):
        mySet = set()        # numbers with no duplicates
        for num in nums:
            if num in mySet: continue
            mySet.add(num)
            if num in freq: freq[num] += 1
            else: freq[num] = 1

    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        """
        O(max(k, m, n)) algorithm with O(k, m, n) extra space, where
        k = len(nums1), m = len(nums2), n = len(nums3)
        """        
        freq = dict()
        self.countFreqs(nums1, freq)
        self.countFreqs(nums2, freq)
        self.countFreqs(nums3, freq)
                        
        result = []
        for num, count in freq.items():
            if count >= 2:
                result.append(num)
        return result
                