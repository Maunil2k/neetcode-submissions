class Solution {
public:
    bool dfs(string &word, int idx, vector<vector<int>> taken, int x, int y, int &lim_x, int &lim_y, vector<vector<char>> &board) {
        if (idx >= word.size()) return true;

        if (x<0 || x>=lim_x || y<0 || y>=lim_y || taken[x][y] || word[idx] != board[x][y]) return false;
        taken[x][y] = 1;
        return (dfs(word, idx+1, taken, x-1, y, lim_x, lim_y, board) ||
                    dfs(word, idx+1, taken, x, y-1, lim_x, lim_y, board) ||
                    dfs(word, idx+1, taken, x, y+1, lim_x, lim_y, board) ||
                    dfs(word, idx+1, taken, x+1, y, lim_x, lim_y, board));
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int lim_x = board.size();
        int lim_y = board[0].size();
        vector<string> ans;
        for (auto word: words) {
            bool found = false;
            for(int i = 0; i<lim_x; i++) {
                for (int j = 0; j<lim_y; j++) {
                    if (board[i][j] == word[0]) {
                        vector<vector<int>> taken(lim_x, vector<int>(lim_y, 0));
                        if (dfs(word, 0, taken, i, j, lim_x, lim_y, board)) {
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
