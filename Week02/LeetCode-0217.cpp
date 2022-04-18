class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // O(N^2) algorithm: Gets "Time Limit Exceeded" error
        for (size_t i=1; i<nums.size(); i++){
            for (int j=i-1; j>=0; j--){
                if (nums[j] == nums[i]) return true;
            } //end-for
        } // end-for

        return false;        
    } // end-containsDuplicate
};