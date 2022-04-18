class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(students.begin(), students.end());
        std::sort(seats.begin(), seats.end());
        int result = 0;
        for (int i=0; i<students.size(); i++)
            result += std::abs(students[i]-seats[i]);
        return result;
    } // end-minMovesToSeat
};