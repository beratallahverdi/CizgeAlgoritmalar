class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        int max_len = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = 2 + (i > 1 ? dp[i - 2] : 0);
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 > 0 ? dp[i - dp[i - 1] - 2] : 0);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};