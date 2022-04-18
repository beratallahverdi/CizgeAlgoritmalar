class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        """
        This time we run the Bellmann-Ford algorithm
        """        
        maxDist = 100*100
        dist = [maxDist]*(n+1)
        dist[0] = 0      # There is no node with id=0. So, make its distance 0
        dist[k] = 0
        
        for ite in range(n-1):
            for u, v, w in times:
                dist[v] = min(dist[v], dist[u]+w) # Relax(u, v)
        
        maxVal = max(dist)
        return -1 if maxVal == maxDist else maxVal
