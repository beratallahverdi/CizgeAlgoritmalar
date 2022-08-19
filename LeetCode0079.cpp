class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, 0, i, j, visited))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int index, int i, int j, vector<vector<bool>> &visited)
    {
        if (index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
            return false;
        visited[i][j] = true;
        if (dfs(board, word, index + 1, i + 1, j, visited) || dfs(board, word, index + 1, i - 1, j, visited) || dfs(board, word, index + 1, i, j + 1, visited) || dfs(board, word, index + 1, i, j - 1, visited))
            return true;
        visited[i][j] = false;
        return false;
    }
};