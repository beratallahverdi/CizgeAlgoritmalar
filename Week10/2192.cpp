
class Solution
{
public:
    set<int> s;
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> graph(n);
        map<int, set<int>> m;

        vector<vector<int>> result(n);
        vector<int> indegree(n, 0);

        for (auto &it : edges)
        {
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> Q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                Q.push(i);
        while (!Q.empty())
        {
            int parent = Q.front();
            Q.pop();

            for (auto &child : graph[parent])
            {
                m[child].insert(parent);
                for (auto &x : m[parent])
                    m[child].insert(x);
                indegree[child]--;
                if (indegree[child] == 0)
                    Q.push(child);
            }
        }
        for (int i = 0; i < n; i++)
            if (m.count(i) == 1)
            {
                vector<int> t(m[i].begin(), m[i].end());
                result[i] = t;
            }
        return result;
    }
};