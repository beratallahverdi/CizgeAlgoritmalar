class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # Create DAG from prerequisites
        G = []
        for i in range(numCourses): G.append([])
        inDegree = [0]*numCourses
        
        # Edge: prerequisites[i][1]-->prerequisites[i][0]
        for i in range(len(prerequisites)):
            G[prerequisites[i][1]].append(prerequisites[i][0])
            inDegree[prerequisites[i][0]] += 1

        Q = []  # Queue of nodes with in-degree == 0
        for i in range(numCourses):
            if inDegree[i] == 0:
                Q.append(i)

        result = []
        while len(Q) > 0:
            u = Q.pop(0)
            result.append(u)
            
            # Reduce In-Degree of all vertices adjacent to u by 1
            for v in G[u]:
                inDegree[v] -= 1
                if inDegree[v] == 0:
                    Q.append(v)        
        return result if len(result) == numCourses else []
                