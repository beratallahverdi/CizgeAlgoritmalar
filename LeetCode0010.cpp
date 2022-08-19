class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        for (int i = 1; i < m; i += 2)
        {
            if (p[i] == '*')
            {
                dp[0][i + 1] = true; // iguring leading X*'s
            }
            else
            {
                break;
            }
        }
        dp[0][0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                dp[i][j] = ((dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) ||                                         // if match
                            (dp[i - 1][j - 1] && p[j - 1] == '.') ||                                              // if match '.'
                            (dp[i - 1][j - 1] && p[j - 1] == '*' && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) || // the first char that matches "X*"
                            (dp[i - 1][j] && p[j - 1] == '*' && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) ||     // other char that match "X*"
                            (j > 1 && dp[i][j - 2] && p[j - 1] == '*')                                            // ignoring leading X*  //
                );
            }
        }
        return dp[n][m];
    }
};