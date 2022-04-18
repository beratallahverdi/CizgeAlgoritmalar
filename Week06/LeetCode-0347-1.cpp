class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /// This is an O(nlogn) solution
        std::sort(nums.begin(), nums.end());

        vector<pair<int, int>> freqs;
        int num = nums[0];
        int freq = 1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] == num) freq++;
            else {
                freqs.push_back({freq, num});
                num = nums[i];
                freq = 1;
            } //end-else
        } //end-for
        freqs.push_back({freq, num});
        
        // Sort freqs array wrt the frequencies in descending order
        std::sort(freqs.begin(), freqs.end(), std::greater());
                
        //Take the first "k" numbers
        vector<int> result;
        for (int i=0; i<k; i++)
            result.push_back(freqs[i].second);
        return result;
    } // end-topKFrequent
};