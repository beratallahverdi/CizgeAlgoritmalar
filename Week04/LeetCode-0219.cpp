class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /// O(N) algorithm with O(N) extra space
        ///          <num, index>
        unordered_map<int, int> myMap;
        for (int i=0; i<nums.size(); i++){
            if (myMap.count(nums[i]) != 0)
                if (i-myMap[nums[i]] <= k)
                    return true;
            myMap[nums[i]] = i;
        } // end-for
        
        return false;
    } // end-containsNearbyDuplicate
};