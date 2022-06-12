class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {

        int n = edges.size();
        vector<int> degree(n + 1, 0);
        vector<vector<int>> nexts(n + 1);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            nexts[u].push_back(v);
            nexts[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> Q;
        for (int i = 1; i <= n; i++)
            if (degree[i] == 1)
                Q.push(i);

        while (!Q.empty())
        {

            int node = Q.front();
            Q.pop();

            for (auto next : nexts[node])
            {
                if (degree[next] == 1)
                    continue;
                degree[next]--;
                if (degree[next] == 1)
                    Q.push(next);
            }
        }

        for (int i = n - 1; i >= 0; i--)
            if (degree[edges[i][0]] > 1 && degree[edges[i][1]] > 1)
                return edges[i];
        return {};
    }
};