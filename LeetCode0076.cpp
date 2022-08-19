class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (n < m)
            return "";
        vector<int> count(128, 0);
        for (int i = 0; i < m; i++)
            count[t[i]]++;
        int left = 0, right = 0;
        int min_len = n + 1;
        int min_left = 0, min_right = 0;
        while (right < n)
        {
            if (count[s[right]]-- > 0)
                m--;
            right++;
            while (m == 0)
            {
                if (right - left < min_len)
                {
                    min_len = right - left;
                    min_left = left;
                    min_right = right;
                }
                if (count[s[left]]++ == 0)
                    m++;
                left++;
            }
        }
        if (min_len == n + 1)
            return "";
        return s.substr(min_left, min_len);
    }
};