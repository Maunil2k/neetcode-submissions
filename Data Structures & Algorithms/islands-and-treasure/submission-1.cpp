class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (grid[i][j] == 0) q.push({{i, j}, 0});
            }
        } 

        while(!q.empty()) {
            pair<pair<int, int>, int> tmp = q.front();
            q.pop();
            int x = tmp.first.first, y = tmp.first.second, d = tmp.second;
            if (x-1>=0 && grid[x-1][y] != 0 && grid[x-1][y]!=-1 && grid[x-1][y]>d+1) {
                grid[x-1][y] = d+1;
                q.push({{x-1, y}, d+1});
            }
            if (y-1>=0 && grid[x][y-1] != 0 && grid[x][y-1]!=-1 && grid[x][y-1]>d+1) {
                grid[x][y-1] = d+1;
                q.push({{x, y-1}, d+1});
            }
            if (x+1<rows && grid[x+1][y] != 0 && grid[x+1][y] != -1 && grid[x+1][y]>d+1) {
                grid[x+1][y] = d+1;
                q.push({{x+1, y}, d+1});
            }
            if (y+1<cols && grid[x][y+1] != 0 && grid[x][y+1] != -1 && grid[x][y+1]>d+1) {
                grid[x][y+1] = d+1;
                q.push({{x, y+1}, d+1});
            }
        }
    }
};
