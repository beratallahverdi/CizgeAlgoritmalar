class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        """This is an O(nlogn) solution"""
        nums.sort()
        
        freqs = []
        num = nums[0]
        freq = 1
        for i in range(1, len(nums)):
            if nums[i] == num:
                freq += 1
            else:
                freqs.append([freq, num])
                num = nums[i]
                freq = 1
        freqs.append([freq, num])
        
        # Sort freqs array wrt the frequencies in descending order
        freqs.sort(reverse=True)
        
        # Take the first "k" numbers
        result = []
        for i in range(k):
            result.append(freqs[i][1])
        return result
