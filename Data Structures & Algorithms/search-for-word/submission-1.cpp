class Solution {
    bool dfs(vector<vector<bool>>& visited, vector<vector<char>>& board, string& word, int i, int j, int currChar) {
        int n = board.size(), m = board[0].size();
        if (i >= n || j >= m || i < 0 || j < 0 || visited[i][j] || board[i][j] != word[currChar]) return false;
        if (currChar == word.size() - 1) return true;
        visited[i][j] = true;
        bool o1 = dfs(visited, board, word, i + 1, j, currChar + 1);
        bool o2 = dfs(visited, board, word, i - 1, j, currChar + 1);
        bool o3 = dfs(visited, board, word, i, j + 1, currChar + 1);
        bool o4 = dfs(visited, board, word, i, j - 1, currChar + 1);
        visited[i][j] = false;
        return o1 || o2 || o3 || o4;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if (dfs(visited, board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};