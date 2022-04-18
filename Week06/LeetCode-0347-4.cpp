class Solution {
    int Partition(vector<pair<int, int>> &A, int left, int right){
        if (left == right) return left;
        
        int pivot = A[right].first;
        int k = left;
        for (int i=left; i<right; i++){
            if (A[i].first >= pivot)
                std::swap(A[i], A[k++]);
        } // end-for
        std::swap(A[k], A[right]);
        return k;
    } // end-Partition
    
    int Select(vector<pair<int, int>> &A, int left, int right, int k){
        if (left == right) return left;
        
        int index = Partition(A, left, right);
        if (index == k) return index;
        if (k < index)
            return Select(A, left, index-1, k);
        else
            return Select(A, index+1, right, k);
    } // end-Select
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // This is an O(nlogk) solution
        unordered_map<int, int> map;

        // Count the occurrence of each number
        for (auto num: nums) map[num]++;
        
        vector<pair<int, int>> A;
        for (auto [num, f]: map)
            A.push_back({f, num});
        
        int index = std::min(k-1, (int)A.size()-1);
        int f = A[Select(A, 0, A.size()-1, index)].first;
        
        vector<int> result;
        for (int i=0; i<A.size() and k>0; i++, k--)
            if (A[i].first >= f)
                result.push_back(A[i].second);
        return result;
    } // end-topKFrequent
};