class Solution {
public:
    static int noOneBits(int n){
        int count = 0;
//        for (int i=0; i<sizeof(n)*8; i++){
        while (n){
            if (n & 0x1) count++;
            n >>= 1;
        } //end-for

        return count;
    } //end-noOneBits
    
    vector<int> sortByBits(vector<int>& arr) {
        auto myComparator = [](int one, int two){
            int count1 = noOneBits(one);
            int count2 = noOneBits(two);

            if (count1 == count2) return one < two;
            return count1 < count2;
        }; //end-myComparator

        sort(arr.begin(), arr.end(), myComparator);
        return arr;
    } // end-sortByBits
};
