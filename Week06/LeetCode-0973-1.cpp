class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(nlogn) algorithm with O(n) extra space
        vector<pair<double, int>> dists;
        for (int i=0; i<points.size(); i++){
            double dist = sqrt(points[i][0]*points[i][0] +
                               points[i][1]*points[i][1]);

            dists.push_back({dist, i});
        } // end-for
        
        // Sort in increasing order
        std::sort(dists.begin(), dists.end());
        
        // Take the first "k" points
        vector<vector<int>> result;
        for (int i=0; i<k; i++)
            result.push_back(points[dists[i].second]);
        return result;
    } // end-kClosest
};