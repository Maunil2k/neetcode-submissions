class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (grid[i][j]) {
                    if (i-1<0 || !grid[i-1][j]) ans++;
                    if (i+1>=rows || !grid[i+1][j]) ans++;
                    if (j-1<0 || !grid[i][j-1]) ans++;
                    if (j+1>=cols || !grid[i][j+1]) ans++;
                }
            }
        }
        return ans;
    }
};