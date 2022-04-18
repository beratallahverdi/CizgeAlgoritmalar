class Solution {
public:
    /// O(N) algorithm with O(N) extra space
    vector<int> twoSum(vector<int>& nums, int target) {
        //           <num, index>
        unordered_map<int, int> myMap;

#if 0        
        for (int i=0; i<nums.size(); i++){
            int otherNum = target-nums[i];
            auto iter = myMap.find(otherNum);
            if (iter != myMap.end())
                return {iter->second, i};
            else
                myMap.insert({nums[i], i});
        } // end-for
#else
        for (int i=0; i<nums.size(); i++){
            int otherNum = target-nums[i];
            if (myMap.count(otherNum) != 0)
                return {myMap[otherNum], i};
            else
                myMap[nums[i]] = i;
        } // end-for        
#endif        
        return {-1, -1};
    } // end-twoSum
};
