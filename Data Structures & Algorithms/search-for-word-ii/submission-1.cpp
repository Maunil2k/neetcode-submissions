class Solution {
public:
    bool dfs(string &word, int idx, vector<vector<int>> taken, int x, int y, int &n, vector<vector<char>> &board) {
        if (idx >= word.size()) return true;

        if (x<0 || x>=n || y<0 || y>=n || taken[x][y] || word[idx] != board[x][y]) return false;
        taken[x][y] = 1;
        return (dfs(word, idx+1, taken, x-1, y, n, board) ||
                    dfs(word, idx+1, taken, x, y-1, n, board) ||
                    dfs(word, idx+1, taken, x, y+1, n, board) ||
                    dfs(word, idx+1, taken, x+1, y, n, board));
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        vector<string> ans;
        for (auto word: words) {
            bool found = false;
            for(int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    if (board[i][j] == word[0]) {
                        vector<vector<int>> taken(n, vector<int>(n, 0));
                        if (dfs(word, 0, taken, i, j, n, board)) {
                            ans.push_back(word);
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
        }
        return ans;
    }
};
