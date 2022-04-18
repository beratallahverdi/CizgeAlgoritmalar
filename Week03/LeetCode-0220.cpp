class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /// Handle corner case
        if (nums.size() < 2) return false;
        
        /// O(NlogN) to copy
        vector<pair<int, int>> A;
        for (int i=0; i<nums.size(); i++)
            A.push_back({nums[i], i});

        // Sort: O(NlogN)
        std::sort(A.begin(), A.end());
        
        // Walk over A
        for (int i=0; i<A.size()-1; i++){
            for (int j=i+1; j<A.size(); j++){
                if (abs((int64_t)A[i].first - (int64_t)A[j].first) > t)
                    break;
                if (std::abs(A[i].second-A[j].second) <= k)
                    return true;
            } // end-for
        } // end-for
        
        return false;
    } // end-containsNearbyAlmostDuplicate
};