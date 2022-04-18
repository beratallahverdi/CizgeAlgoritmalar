import heapq
from math import sqrt
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # O(nlogn) algorithm with O(n) extra space
        dists = []
        for i in range(len(points)):
            dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1])
            dists.append([dist, i])
            
        # Sort in increasing order
        dists.sort()
        
        # Take the first "k" points
        result = []
        for i in range(k):
            result.append(points[dists[i][1]])
        return result
