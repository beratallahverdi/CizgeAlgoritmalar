class Solution {
public:
    void InsersectSet(vector<int> &nums1, vector<int> &nums2, vector<int> &result){
        int i=0, j=0;
        while (i<nums1.size() and j<nums2.size()){
            if (nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
                                
            } else if (nums1[i] < nums2[j]) i++;
            else j++;
        } // end-while
    } // end-InsersectSet

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        // Sort all arrays
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::sort(nums3.begin(), nums3.end());
        
        vector<int> result;
        InsersectSet(nums1, nums2, result);
        InsersectSet(nums1, nums3, result);
        InsersectSet(nums2, nums3, result);
        
        if (result.size() <= 1) return result;
        
        // Eliminate the duplicates from the result
        std::sort(result.begin(), result.end());
        auto iter = std::unique(result.begin(), result.end());
        result.resize(iter-result.begin());
        
        return result;                
    } // end-twoOutOfThree
};