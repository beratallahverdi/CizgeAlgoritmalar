class Solution
{
    bool sinirdisi(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int max_nearestWaterCell(vector<vector<int>> &grid, queue<pair<int, int>> &Q)
    {
        vector<pair<int, int>> neighs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int maxDist = 0;
        while (!Q.empty())
        {
            int size = Q.size();
            bool isFound = false;

            for (int i = 0; i < size; i++)
            {
                pair<int, int> coord = Q.front();
                Q.pop();

                int x = coord.first, y = coord.second;

                for (auto [diffX, diffY] : neighs)
                {
                    int nr = diffX + x, nc = diffY + y;
                    if (!sinirdisi(grid, nr, nc) || grid[nr][nc] == 1)
                        continue;

                    Q.push({nr, nc});
                    grid[nr][nc] = 1;
                    isFound = true;
                }
            }

            maxDist += isFound ? 1 : 0;
        }

        return maxDist != 0 ? maxDist : -1;
    }

public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> Q;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    Q.push({i, j});

        return max_nearestWaterCell(grid, Q);
    }
};