#include <algorithm>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /// O(N^2) algorithm: Gets Time Limit Exceeded
        for (int i=0; i<nums.size()-1; i++){
            for (int j=i+1; j<std::min(i+k+1, (int)nums.size()); j++)
                if (nums[i] == nums[j])
                    return true;
        } // end-containsNearbyDuplicate
        
        return false;
    } // end-containsNearbyDuplicate
};