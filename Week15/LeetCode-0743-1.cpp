class Solution {
public:
    /// Simply run Dijkra's shortest path algorithm & take the distance
    /// to the farthest node as the solution
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Convert times to an adjacency list
        vector<vector<pair<int, int>>> G(n+1);
        for (int i=0; i<times.size(); i++)
            G[times[i][0]].push_back({times[i][1], times[i][2]});

        // Run Dijktra's algorithm
        #define BLACK 0
        #define WHITE 1
        vector<char> color(n+1, WHITE);
        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       std::greater<pair<int, int>>> Q;
        Q.push({0, k});
        
        while (Q.size() > 0){
            // Find the node with the min distance
            auto [d, u] = Q.top(); Q.pop();
            if (color[u] == BLACK) continue;

            color[u] = BLACK;  // Mark as processed
                
            for (auto [v, w]: G[u]){
                if (color[v] == BLACK) continue;
                    
                int newDist = d + w;
                if (newDist < dist[v]){
                    dist[v] = newDist;
                    Q.push({newDist, v});                    
                } // end-if
            } // end-for
        } // end-while

        for (int u=1; u<=n; u++){
            if (color[u] == WHITE)
                return -1;
        } // end-for
        
        return *std::max_element(dist.begin()+1, dist.end());        
    } // end-networkDelayTime
};