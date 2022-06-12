class Solution
{
    queue<int> Q;
    vector<bool> visited;
    unordered_map<string, int> map;
    vector<pair<int, string>> result;
    vector<string> answers;

public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        visited.resize(n, false);
        Q.push(id);
        visited[id] = true;

        while (level--)
        {
            int size = Q.size();
            while (size--)
            {
                int node = Q.front();
                Q.pop();
                for (auto child : friends[node])
                {
                    if (!visited[child])
                    {
                        visited[child] = true;
                        Q.push(child);
                    }
                }
            }
        }
        while (!Q.empty())
        {
            vector<string> temp = watchedVideos[Q.front()];
            Q.pop();
            for (auto i : temp)
                map[i]++;
        }

        for (auto &[key, value] : map)
            result.push_back({value, key});

        std::sort(result.begin(), result.end());

        for (auto &[key, value] : result)
            answers.push_back(value);

        return answers;
    }
};