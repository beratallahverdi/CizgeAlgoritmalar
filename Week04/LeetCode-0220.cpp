class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        /// This is an O(nlogk) algorithm        
        #define DIFF(a, b)(abs((int64_t)a - (int64_t)b))

        // Handle corner cases first
        if (nums.size() <= 1) return false;
        if (t < 0) return false;
        if (k <= 0) return false; // indices must be distinct

        // The ordered set maintains the last k elements in sorted order
        // Idea is the following: Say we are at nums[i]
        // We search nums[i] inside the sorted set
        // In sorted order, we will have: prev < nums[i] < next
        // To get next, we use upper_bound method
        // To get previous, we simply decrement the returned iterator
        set<int> mySet;

        mySet.insert(nums[0]);
        for (int i=1; i<(int)nums.size(); i++){            
            // Returns an iterator to the element that is either equal to nums[i]
            // or the next element in sorted order (i.e., *iter >= nums[i])
            auto iter = mySet.upper_bound(nums[i]);
            if (iter != mySet.end() && DIFF(nums[i], *iter) <= t) return true;

            // Also look at the previous element
            if (--iter != mySet.end() && DIFF(nums[i], *iter) <= t) return true;

            // Erase nums[i-k] from the set
            if (i-k >= 0) mySet.erase(nums[i-k]);
            
            // Add this number to the set
            mySet.insert(nums[i]);
        } //end-for

        return false;
    } // end-containsNearbyAlmostDuplicate
};