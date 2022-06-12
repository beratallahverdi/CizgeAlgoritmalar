class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        int result = 0;
        unordered_map<int, vector<int>> graph;
        vector<int> degree(n + 1, 0), prevTime(n + 1, 0);
        queue<int> q;
        for (auto p : relations)
        {
            graph[p[0]].push_back(p[1]);
            degree[p[1]]++;
        }
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0) // add outer nodes in queue
                q.push(i);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result = max(result, prevTime[node] + time[node - 1]); // keep track of how much time has used till now. Till the end. you will get the result.
            for (auto child : graph[node])
            {
                prevTime[child] = max(prevTime[child], prevTime[node] + time[node - 1]);
                if (--degree[child] == 0)
                    q.push(child);
            }
        }
        return result;
    }
};