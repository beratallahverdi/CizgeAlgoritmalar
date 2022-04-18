class Solution:
    BLACK = 0
    GRAY = 1
    WHITE = 2

    #--------------------------------------------------------------
    # Do DFS & look for back edges (loops)
    #
    def dfs(self, u, G, color, result):
        color[u] = Solution.GRAY
        
        for v in G[u]:
            if (color[v] == Solution.GRAY):
                return False         # Backedge
            if (color[v] == Solution.WHITE):
                if (not self.dfs(v, G, color, result)):
                    return False

        color[u] = Solution.BLACK        
        result.append(u)        
        return True
    
    #-----------------------------------------------------------------
    # Convert the prerequisites to a graph. 
    # Then do a DFS & look for a backedge (llop) 
    #                    
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Create DAG from prerequisites
        G = []
        for i in range(numCourses): G.append([])
            
        for i in range(len(prerequisites)):
            G[prerequisites[i][1]].append(prerequisites[i][0])
                
        # Do DFS & look for cycles (back edges)        
        color = [Solution.WHITE]*numCourses

        result = []
        for u in range(numCourses):
            if (color[u] == Solution.WHITE):
                if (not self.dfs(u, G, color, result)):
                    return []
        
        result.reverse()
        return result
