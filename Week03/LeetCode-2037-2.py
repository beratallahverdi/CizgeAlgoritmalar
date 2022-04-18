class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        MAX_NUM = 101
        S = [0]*MAX_NUM
        C = [0]*MAX_NUM
 
        #Perform counting sort
        for seat in seats: C[seat] += 1
        for student in students: S[student] += 1
    
        k = 0
        for i in range(MAX_NUM):   
            while (C[i] > 0):
                seats[k] = i
                k += 1
                C[i] -= 1

        k = 0
        for i in range(MAX_NUM):   
            while (S[i] > 0):
                students[k] = i
                k += 1
                S[i] -= 1
                
        result = 0
        for student, seat in zip(students, seats):
            result += abs(student-seat)
        return result