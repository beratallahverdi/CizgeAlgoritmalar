class Solution {
public:
    /// O(NlogN) algorithm with O(N) extra space
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(N) to create the temporary array
        vector<pair<int, int>> A;
        for (int i=0; i<nums.size(); i++)
            A.push_back({nums[i], i});
        
        // NlogN to sort
        std::sort(A.begin(), A.end());
        
        // O(N) to find the pair
        int i=0;
        int j=A.size()-1;
        while (i < j){
            int total = A[i].first+A[j].first;
            if (total == target) return {A[i].second, A[j].second};
            else if (total < target) i++;
            else j--;
        } // while
        
        return {-1, -1};
    } // end-twoSum
};
