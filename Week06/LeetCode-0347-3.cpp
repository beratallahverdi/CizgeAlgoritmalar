class Solution {
public:
    ///-------------------------------------------------------------
    /// Here is an O(n) solution
    ///
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        // Count the occurrence of each number
        for (auto num: nums) map[num]++;

        // Find the freq. of the number that occurs the most
        int maxCount = 0;
        for (auto p: map) if (p.second > maxCount) maxCount = p.second;

        // Create a LUT with the most freq. numbers (assumes INT_MINT is not a valid number)
        vector<vector<int>> freq(maxCount+1);
        for (auto [f, num]: map) freq[f].push_back(num);

        // Copy the numbers from the freq. list to the result
        vector<int> result;
        for (int index=maxCount; k>0 && index >= 0; index--){
            for (int i=0; i<freq[index].size() && k>0; i++, k--){
                result.push_back(freq[index][i]);
            } //end-for
        } //end-while

        return result;
    } //end-topKFrequent
};
