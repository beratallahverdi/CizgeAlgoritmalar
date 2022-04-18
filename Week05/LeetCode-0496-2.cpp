class Solution {
public:
    ///-------------------------------------------------------------------------
    /// This is an O(n+m) algorithm that uses O(m) extra space
    ///
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> S;

        for (int i=(int)nums2.size()-1; i>=0; i--){
            while (!S.empty() && nums2[i] >= S.top()) S.pop();

            if (S.empty()) nextGreater[nums2[i]] = -1;
            else           nextGreater[nums2[i]] = S.top();

            S.push(nums2[i]);
        } //end-for

        // Find nums1[i] in the map & push the next greater to the result
        vector<int> result;
        for (int i=0; i<nums1.size(); i++){
            result.push_back(nextGreater[nums1[i]]);
        } //end-for

        return result;
    } //end-nextGreaterElement
};