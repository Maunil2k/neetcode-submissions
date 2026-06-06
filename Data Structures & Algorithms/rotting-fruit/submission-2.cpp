class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = -1, fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        while (!q.empty()) {
            int l = q.size();
            for (int i = 0; i<l; i++) {
                pair<int, int> tmp = q.front();
                q.pop();
                int x = tmp.first, y = tmp.second;
                if (x-1>=0 && grid[x-1][y] == 1) {
                    q.push({x-1, y});
                    grid[x-1][y] = 2;
                    fresh--;
                }
                if (y-1>=0 && grid[x][y-1] == 1) {
                    q.push({x, y-1});
                    grid[x][y-1] = 2;
                    fresh--;
                }
                if (x+1<rows && grid[x+1][y] == 1) {
                    q.push({x+1, y});
                    grid[x+1][y] = 2;
                    fresh--;
                }
                if (y+1<cols && grid[x][y+1] == 1) {
                    q.push({x, y+1});
                    grid[x][y+1] = 2;
                    fresh--;
                }
            }
            ans++;
        }
        if (fresh>0) return -1;
        return max(ans, 0);
    }
};