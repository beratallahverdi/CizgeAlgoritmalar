class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /// This time we run the Bellmann-Ford algorithm
        int maxDist = 100*100;
        vector<int> dist(n+1, maxDist);
        dist[k] = 0;
        
        for (int iter=0; iter<n-1; iter++){
            for (int i=0; i<times.size(); i++){
                int u = times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                
                dist[v] = min(dist[v], dist[u]+w); // Relax(u, v)
            } // end-for         
        } // end-for
        
        int maxVal = *std::max_element(dist.begin()+1, dist.end());        
        return maxVal == maxDist? -1: maxVal;
    } // end-for
};