class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        // BFS
        queue<pair<int, int>> q;
        for (int i = 0; i<cols; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'T';
            }
        }

        for (int i = 1; i<rows; i++) {
            if (board[i][cols-1] == 'O') {
                q.push({i, cols-1});
                board[i][cols-1] = 'T';
            }
        }

        for (int i = cols-2; i>=0; i--) {
            if (board[rows-1][i] == 'O') {
                q.push({rows-1, i});
                board[rows-1][i] = 'T';
            } 
        }

        for (int i = rows-2; i>0; i--) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'T';
            }
        }

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            int x = tmp.first, y = tmp.second;
            q.pop();
            if (x-1>=0 && board[x-1][y] == 'O') {
                q.push({x-1, y});
                board[x-1][y] = 'T';
            }
            if (x+1<rows && board[x+1][y] == 'O') {
                q.push({x+1, y});
                board[x+1][y] = 'T';
            }
            if (y-1>=0 && board[x][y-1] == 'O') {
                q.push({x, y-1});
                board[x][y-1] = 'T';
            }
            if (y+1<cols && board[x][y+1] == 'O') {
                q.push({x, y+1});
                board[x][y+1] = 'T';
            }
        }

        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
