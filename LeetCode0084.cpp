class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 0)
            return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();
            s.push(i);
        }
        s = stack<¡nt>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                right[i] = n;
            else
                right[i] = s.top();
            s.push(i);
        }
        int max_area = 0;
        for (int i = 0; i < n; i++)
        {
            max_area = max(max_area, (right[i] - left[i] - 1) * heights[i]);
        }
        return max_area;
    }
};