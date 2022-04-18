from functools import cmp_to_key

def noOneBits(n):
    count = 0
    while n > 0:
        if n & 0x1 == 1:
            count += 1
        n >>= 1                
    return count

def myComparator(one, two):
    count1 = noOneBits(one)
    count2 = noOneBits(two)

    if count1 == count2:
        return one-two
    else:
        return count1-count2

class Solution:    
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key=cmp_to_key(myComparator))
        return arr
