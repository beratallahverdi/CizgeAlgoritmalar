class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        #define MAX_NUM 101
        vector<int> S(MAX_NUM, 0);
        vector<int> C(MAX_NUM, 0);

        // Perform counting sort
        for (auto seat: seats) C[seat]++;
        for (auto student: students) S[student]++;
        
        for (int i=0, k=0; i<MAX_NUM; i++)
            while (C[i]-- > 0)
                seats[k++] = i;

        for (int i=0, k=0; i<MAX_NUM; i++)
            while (S[i]-- > 0)
                students[k++] = i;
        
        int result = 0;
        for (int i=0; i<students.size(); i++)
            result += std::abs(students[i]-seats[i]);
        return result;
    } // end-minMovesToSeat
};