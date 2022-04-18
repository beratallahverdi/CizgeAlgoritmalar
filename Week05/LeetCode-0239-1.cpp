class Solution {
public:
    ///------------------------------------------------------
    /// O(nlogk) solution using a TreeMap
    ///
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> window;

        vector<int> result;
        // Insert the first k-1 numbers into the map
        for (int i=0; i<k-1; i++) window[nums[i]]++;

        // Find the max. for the rest of the numbers
        for (int left=0, right=k-1; right<nums.size(); left++, right++){
            // Add the new number to the window
            window[nums[right]]++;

            // Push the max. value to the result
            result.push_back(window.rbegin()->first);

            // Remove the first number from the window
            auto iter = window.find(nums[left]);
            if (iter->second > 1) iter->second--;
            else window.erase(iter);
        } //end-for

        return result;
    } // end-maxSlidingWindow
};