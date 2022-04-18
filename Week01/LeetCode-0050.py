class Solution:
    def myPow2(self, x: float, n: int) -> float:    
        if (n == 0): return 1.0
        if (n == 1): return x
        
        partialResult = self.myPow2(x, n//2)
        result = partialResult*partialResult
        if (n%2 == 1): result *= x        
        return result
        
    def myPow3(self, x, n):
        result = 1.0
        powX = x
        while (n > 0):
            if (n&0x1 == 1): result *= powX
            n >>= 1
            powX *= powX                        
        return result
    
    def myPow(self, x: float, n: int) -> float:    
        if (x == 1): return 1.0
        if (x == -1):
            return 1 if n%2==0 else -1        
        if (n == 0): return 1.0
        
        isNegative = False
        if (n < 0):
            n = -(1+n)
            isNegative = True
            
#        p = self.myPow2(x, n)
        p = self.myPow3(x, n)
                
        return 1.0/(x*p) if isNegative else p
