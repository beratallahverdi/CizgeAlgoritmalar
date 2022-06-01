// constructing stacks
#include <iostream>  // std::cout
#include <stack>     // std::stack
#include <vector>    // std::vector
#include <deque>     // std::deque
#include <string>    // std::string
#include <algorithm> // std::sort
#include <cmath>     // std::pow

class Solution
{
public:
    int calculate(std::string s)
    {
        int n = s.length();
        stack<int> items;
        int result = 0;
        int isaret = 1;
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '+')
                isaret = 1;
            else if (s[i] == '-')
                isaret = -1;
            else if (isdigit(s[i]))
            {
                long long temp = 0;

                while (i < n and isdigit(s[i]))
                {
                    temp = temp * 10 + s[i] - '0';
                    i++;
                }
                i--;
                result = result + isaret * temp;
            }
            else if (s[i] == '(')
            {
                items.push(result);
                items.push(isaret);
                result = 0;
                isaret = 1;
            }
            else if (s[i] == ')')
            {
                int cIsaret = items.top();
                items.pop();
                int cInteger = items.top();
                items.pop();

                result = cInteger + cIsaret * result;
            }
        }
        return result;
    }

};