class Solution {
public:
    double myPow1(double x, int n){
        double result = 1;
        for (int i=1; i<=n; i++)
            result *= x;
        return result;
    } // end-myPow1

    double myPow2(double x, int n){
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        double partialResult = myPow2(x, n/2);
        double result = partialResult*partialResult;
        if (n%2 == 1) result *= x;
        
        return result;
    } // end-myPow2

    double myPow3(double x, int n){
        double result = 1.0;
        double powX = x;
        while (n > 0){
            if (n&0x1) result *= powX;
            n >>= 1;
            powX *= powX;
        } // end-while
                        
        return result;
    } // end-myPow3
    
    double myPow(double x, int n) {
        if (x == 1) return 1.0;
        if (x == -1)
            return n%2==0? 1: -1;        
        if (n == 0) return 1.0;
        
        bool isNegative = false;
        if (n < 0){ n = -(1+n); isNegative = true;}
        double p = myPow1(x, n);
//        double p = myPow2(x, n);
//        double p = myPow3(x, n);
                
        return isNegative? 1.0/(x*p): p;
    } // end-myPow
};