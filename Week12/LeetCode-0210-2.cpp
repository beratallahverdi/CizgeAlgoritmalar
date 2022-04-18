class Solution {
#define BLACK 0
#define GRAY  1
#define WHITE 2

public:
    ///--------------------------------------------------------------
    /// Do DFS & look for back edges (loops)
    ///
    bool dfs(int u, vector<vector<int>>& G, vector<int> &color, vector<int> &result){
        color[u] = GRAY;
        
        for (int v: G[u]){
            if (color[v] == GRAY) 
                return false;  // Backedge
            if (color[v] == WHITE){
                if (!dfs(v, G, color, result))
                    return false;
            } //end-if
        } // end-for

        color[u] = BLACK;
        result.push_back(u);
        
        return true;
    } //end-dfs
    
    ///-----------------------------------------------------------------
    /// Convert the prerequisites to a graph. 
    /// Then do a DFS & look for a backedge (llop) 
    ///
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create DAG from prerequisites
        vector<vector<int>> G(numCourses);        
        
        for (int i=0; i<prerequisites.size(); i++)
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        // Do DFS & look for cycles (back edges)        
        vector<int> color(numCourses, WHITE);

        vector<int> result;      
        
        for (int i=0; i<numCourses; i++)
            if (color[i] == WHITE)
                if (!dfs(i, G, color, result))
                    return vector<int>{};
        
        std::reverse(result.begin(), result.end());            
        return result;    
    } // end-findOrder
};
