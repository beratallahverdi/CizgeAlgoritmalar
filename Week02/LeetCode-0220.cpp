class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i=0; i<(int)nums.size()-1; i++){
            for (int j=i+1; j<std::min(i+k+1, (int)nums.size()); j++)
                if (std::abs((int64_t)nums[i]-(int64_t)nums[j]) <= t)
                    return true;
        } // end-for        
        return false;        
    } // end-containsNearbyAlmostDuplicate
};