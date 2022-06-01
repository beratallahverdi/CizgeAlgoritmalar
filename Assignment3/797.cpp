class Solution
{
    vector<vector<int>> result;
    void dfs(int curr, vector<int> list[], vector<int> &path, vector<vector<int>> &graph)
    {
        path.push_back(curr);
        if (curr == graph.size() - 1) // if got the last node, push into ans vector
            result.push_back(path);
        else
            for (auto node : list[curr]) // explore the current node too
                dfs(node, list, path, graph);
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int i = 0;
        vector<int> list[n];
        for (int i = 0; i < n; i++)
        {
            int m = graph[i].size();
            for (int j = 0; j < m; j++)
                list[i].push_back(graph[i][j]);
        }
        vector<int> path;
        dfs(0, list, path, graph);
        return result;
    }
};