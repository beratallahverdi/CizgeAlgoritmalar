class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(NlogN) algorithm
        std::sort(nums.begin(), nums.end());
        
        // Walk over the list & compare consecutive numbers
        for (int i=1; i<nums.size(); i++)
            if (nums[i] == nums[i-1])
                return true;

        return false;        
    } // end-containsDuplicate
};