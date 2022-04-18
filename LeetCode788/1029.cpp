class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int mincost = 0;

        std::sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b)
                  { return a[1] - a[0] > b[1] - b[0]; });

        for (int i = 0; i < n; i++)
            if (i >= n / 2)
                mincost += costs[i][1];
            else
                mincost += costs[i][0];
        return mincost;
    }
};