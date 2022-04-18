class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        """Here is an O(n) solution"""
        myMap = dict()
        
        # Count the occurrence of each number
        for num in nums:
            if num not in myMap: myMap[num] = 1
            else: myMap[num] += 1

        # Find the freq. of the number that occurs the most
        maxCount = 0
        for freq in myMap.values():
            maxCount = max(maxCount, freq)

        # Create a LUT with the most freq. numbers        
        freqList = []
        for i in range(maxCount+1): freqList.append([])
        for num, freq in myMap.items():
            freqList[freq].append(num)

        # Copy the numbers from the freq. list to the result
        result = []
        index = maxCount
        while k > 0 and index >= 0:
            for i in range(len(freqList[index])):
                if k == 0: break
                result.append(freqList[index][i])                    
                k -= 1
            index -= 1
        return result
        