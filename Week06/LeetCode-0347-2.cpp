class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // This is an O(nlogk) solution
        unordered_map<int, int> map;

        // Count the occurrence of each number
        for (auto num: nums) map[num]++;
        
        // Insert <freq, num> into a min-heap
        auto cmp = [](pair<int, int> &left, pair<int, int> &right) {
            return (left.first >= right.first);
        };
	    priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(cmp)> PQ(cmp);
        for (auto [num, freq]: map){
            if (PQ.size() < k) PQ.push({freq, num});
            else if (freq > PQ.top().first){
                PQ.pop();
                PQ.push({freq, num});
            } // end-else
        } // end-for
        
        // Copy the "k" values from the PQ to the result
        vector<int> result;
        while (!PQ.empty()){
            auto [freq, num] = PQ.top();
            PQ.pop();
            result.push_back(num);
        } //end-while
        return result;
    } // end-topKFrequent
};