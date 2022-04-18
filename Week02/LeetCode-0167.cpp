class Solution {
public:
    // Simple O(N) algorithm
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while (i<j){
            int sum = numbers[i] + numbers[j];
            if (sum == target) return vector<int>{i+1, j+1};
            if (sum < target) i++;
            else              j--;
        } // end-while

        return vector<int>{-1, -1};  // No pair adds up to the target        
    } // end-twoSum
};