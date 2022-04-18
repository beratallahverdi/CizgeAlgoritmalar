using namespace:std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort the boxes in decreasing order with respect to to their units
        sort(boxTypes.begin(), boxTypes.end(), 
                  [](vector<int> &a, vector<int> &b){
                            return a[1] > b[1];});
        int total = 0;
        for (int i=0; i<boxTypes.size(); i++){
            int noBoxes = boxTypes[i][0];
            int noUnits = boxTypes[i][1];            
            int taken = min(noBoxes, truckSize);
            total += taken*noUnits;
            truckSize -= taken;
            if (truckSize == 0) break;
        } // end-for
        
        return total;        
    } // end-maximumUnits
};