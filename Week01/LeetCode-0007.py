class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 1<<31
        INT_MIN = -INT_MAX - 1
        if (x == INT_MIN): return 0
        negative = x < 0
        if negative: x = -x

        result = 0
        while (x > 0):
            digit = x%10
            
            # Check for overflow
            if result > (INT_MAX-digit)//10: return 0
            
            result = result * 10 + digit
            x //= 10

        return -result if negative else result
