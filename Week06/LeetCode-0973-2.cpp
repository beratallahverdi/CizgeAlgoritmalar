class Solution {
public:
    ///-----------------------------------------------------------------
    /// Here is an O(nlogk) algorithm using a max-heap
    /// Maintain a max-heap that stores the "K" closest points seen so far
    /// If the next point is closer than the farthest point in the heap,
    /// remove that point from the heap, and insert the new point to the heap
    ///
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Store <dist, index of the point in points>
        priority_queue<pair<double, int>> PQ;

        for (int i=0; i<points.size(); i++){
            double dist = sqrt(points[i][0]*points[i][0] +
                               points[i][1]*points[i][1]);

            if (PQ.size() < K) PQ.push(make_pair(dist, i));
            else if (dist < PQ.top().first){
                PQ.pop();
                PQ.push(make_pair(dist, i));
            } //end-if
        } // end-for

        vector<vector<int>> result;
        while (!PQ.empty()){
            result.push_back(points[PQ.top().second]);
            PQ.pop();
        } //end-while

        return result;
    } //end-kClosest
};