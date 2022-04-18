class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        students.sort()
        seats.sort()
        result = 0
        for student, seat in zip(students, seats):
            result += abs(student-seat)
        return result