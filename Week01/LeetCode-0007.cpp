class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool negative = x < 0;        
        if (negative) x = -x;

        int result = 0;
        while (x > 0){
            int digit = x % 10;
            // Check for overflow
            if (result > (INT_MAX-digit)/10)                
                return 0;
            result = result * 10 + digit;
            x /= 10;
        } //end-while

        return negative? -result: result;
    } // end-reverse
};