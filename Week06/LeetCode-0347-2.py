import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        """This is an O(nlogk) solution"""
        myMap = dict()

        # Count the occurrence of each number
        for num in nums: 
            if num in myMap:
                myMap[num] += 1
            else:
                myMap[num] = 1
                        
        # Min-heap
        PQ = []
        for num, freq in myMap.items():
            if len(PQ) < k:
                heapq.heappush(PQ, [freq, num])
            elif freq > PQ[0][0]:
                heapq.heappop(PQ)
                heapq.heappush(PQ, [freq, num])
        
        # Copy the "k" values from the PQ to the result
        result = []
        for freq, num in PQ:
            result.append(num)
        return result 