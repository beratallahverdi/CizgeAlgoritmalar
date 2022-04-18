from functools import cmp_to_key
def compare(a, b):
    return b[1]-a[1]    # Decreasing order

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        # Sort the boxes in decreasing oder with respecto to their units
        boxTypes.sort(key=cmp_to_key(compare))
        
        total = 0
        for noBoxes, noUnits in boxTypes:
            taken = min(noBoxes, truckSize)
            total += taken*noUnits
            truckSize -= taken
            if truckSize == 0: break
        return total
            