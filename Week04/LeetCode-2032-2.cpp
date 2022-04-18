class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        /*
        O(k+m+n) algorithm with O(1) extra space, where
        k = len(nums1), m = len(nums2), n = len(nums3)
        We make use of the fact that numbers are in between 1<=num<=100 and use a LUT
        */        
        int maxNum = 100;
        
        // We will use a LUT to mark the numbers that occur in each list
        vector<int> lut1(maxNum+1);
        for (auto num: nums1) lut1[num]=1;

        vector<int> lut2(maxNum+1);
        for (auto num: nums2) lut2[num]=1;

        vector<int> lut3(maxNum+1);
        for (auto num: nums3) lut3[num]=1;
        
        vector<int> result;
        for (int num=1; num<=maxNum; num++){
            int count = lut1[num] + lut2[num] + lut3[num];
            if (count >= 2)
                result.push_back(num);
        } //end-for
        
        return result;        
    } // end-twoOutOfThree
};