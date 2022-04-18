#include <algorithm>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /// O(NlogN) algorithm
        vector<pair<int, int>> A;
        for (int i=0; i<nums.size(); i++)
            A.push_back({nums[i], i});

        // Sort: O(NlogN)
        std::sort(A.begin(), A.end());
        
        // Walk over A
        for (int i=1; i<A.size(); i++){
            if (A[i].first == A[i-1].first)
                if (std::abs(A[i].second-A[i-1].second) <= k)
                    return true;
        } // end-for
        
        return false;
    } // end-containsNearbyDuplicate
};