class Solution {
public:
    ///----------------------------------------------------------------
    /// The version using priority_queue
    ///
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {       
        vector<vector<pair<int, double>>> G(n);
        for (int i=0; i<edges.size(); i++){
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        } // end-for
        
        // Run Dijkstra's algo with relaxation: cost[u, v] = weight(u, w)*cost[w, v]
        #define BLACK 0
        #define WHITE 1
        vector<int> color(n, WHITE);
        priority_queue<pair<double, int>, vector<pair<double, int>>, 
                       std::less<pair<double, int>>> Q;                           
        vector<double> costs(n, 0);
            
        costs[start] = 1.0;
        Q.push({1.0, start});
        
        while (Q.size() > 0){
            // Get the vertex with the highest probability
            auto [cost, u] = Q.top(); Q.pop();
            if (u == end) return cost;
            if (color[u] == BLACK) continue;

            color[u] = BLACK;
            
            // Perform relaxation for "u"s neighbors
            for (auto [v, w]: G[u]){
                double newCost = cost*w;
                if (newCost > costs[v]){
                    costs[v] = newCost;
                    Q.push({newCost, v});                    
                } // end-if
            } // end-for
        } // end-while
        
        return 0.0;
    } // end-maxProbability
};