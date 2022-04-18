class Solution {
public:
    bool isValid(string s) {
        // Here is an algorithm that does NOT work!
        vector<int> C(3);  // Count of each type of parenthesis
        
        for (auto ch: s){
            if      (ch == '(') C[0]++;
            else if (ch == ')') C[0]--;
            else if (ch == '[') C[1]++;
            else if (ch == ']') C[1]--;
            else if (ch == '{') C[2]++;
            else if (ch == '}') C[2]--;
        } // end-for
        
        return C[0] == 0 and C[1] == 0 and C[2] == 0;        
    } // end-isValid
};