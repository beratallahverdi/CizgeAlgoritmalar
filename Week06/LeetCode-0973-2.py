import heapq
from math import sqrt
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        """ 
        Here is an O(nlogk) algorithm using a max-heap
        Maintain a max-heap that stores the "K" closest points seen so far
        If the next point is closer than the farthest point in the heap,
        remove that point from the heap, and insert the new point to the heap
        """
        # Store <dist, index of the point> in a max-heap
        PQ = []
        for i in range(len(points)):
            dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])

            if len(PQ) < k:
                heapq.heappush(PQ, [-dist, i])
            elif dist < -PQ[0][0]:
                heapq.heappop(PQ)
                heapq.heappush(PQ, [-dist, i])

        result = []                
        while len(PQ) > 0:
            index = heapq.heappop(PQ)[1]
            result.append(points[index])
        return result