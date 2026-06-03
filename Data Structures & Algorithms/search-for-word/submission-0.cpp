class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, vector<vector<int>> &visited, string &word, int x, int y, int &lim_x, int &lim_y) {
        if (i == word.size()) return true;

        if (x == lim_x || y == lim_y || x < 0 || y < 0 || board[x][y] != word[i] || visited[x][y]) return false;

        visited[x][y] = 1;

        bool res = dfs(board, i+1, visited, word, x-1, y, lim_x, lim_y) || dfs(board, i+1, visited, word, x, y-1, lim_x, lim_y) || dfs(board, i+1, visited, word, x+1, y, lim_x, lim_y) || dfs(board, i+1, visited, word, x, y+1, lim_x, lim_y);
        if (res) return true;

        visited[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        int lim_x = board.size();
        int lim_y = board[0].size();

        for (int i = 0; i<lim_x; i++) {
            for (int j = 0; j<lim_y; j++) {
                bool res = dfs(board, 0, visited, word, i, j, lim_x, lim_y);
                if (res) return true;
            }
        }
        return false;
    }
};
