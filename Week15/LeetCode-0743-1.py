import heapq
class Solution:
    # Simply run Dijkra's shortest path algorithm & take the distance
    # to the farthest node as the solution
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # Convert times to an adjacency list
        G = []
        for i in range(n+1): G.append([])
            
        for i in range(len(times)):
            G[times[i][0]].append([times[i][1], times[i][2]])

        # Run Dijktra's algorithm
        BLACK = 0
        WHITE = 2
        color = [WHITE]*(n+1)
        dist = [20000]*(n+1)

        dist[0] = 0      # There is no node with id=0. So, make its distance 0
        dist[k] = 0
        Q = [(0, k)]
        
        while (len(Q) > 0):
            # Get the node with the smallest distance
            d, u = heapq.heappop(Q)
            
            if color[u] == BLACK: continue  # Already processed
            
            color[u] = BLACK # Mark as processed

            for v, w in G[u]:            
                if (color[v] == BLACK): continue
                    
                newDist = d + w
                if (newDist < dist[v]):                    
                    dist[v] = newDist
                    heapq.heappush(Q, [newDist, v])

        for u in range(1, n+1):                    
            if (color[u] == WHITE):
                return -1
        
        return max(dist)        
        
        