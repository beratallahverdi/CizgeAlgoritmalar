class Solution {
public:
    /// O(N^2) algorithm
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size()-1; i++){
            for (int j=i+1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return vector<int>{i, j};
                } //end-if
            } //end-for
        } //end-for

        return {-1, -1};  // No pair adds up to the target        
    } // end-twoSum
};
