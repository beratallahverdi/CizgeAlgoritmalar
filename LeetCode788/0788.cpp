class Solution
{
public:
    int rotatedDigits(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            bool state = false;
            int number = i;
            while (number > 0)
            {
                int digit = number % 10;
                if (digit == 3 || digit == 4 || digit == 7)
                {
                    state = false;
                    break;
                }

                if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                    state = true;
                number /= 10;
            }
            if (state)
                count++;
        }
        return count;
    }
};