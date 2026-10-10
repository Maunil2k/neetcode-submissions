class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if (obstacleGrid[r-1][c-1]) return 0;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        grid[r-1][c-1] = 1;
        bool flag = true;
        for (int i = c-1; i>=0; i--) {
            if (flag){
                if (obstacleGrid[r-1][i] == 0) grid[r-1][i] = 1;
                else {
                    grid[r-1][i] = 0;
                    flag = false;
                }
            }
            else grid[r-1][i] = 0;
        }
        flag = true;
        for (int i = r-1; i>=0; i--) {
            if (flag) {
                if (obstacleGrid[i][c-1] == 0) grid[i][c-1] = 1;
                else {
                    grid[i][c-1] = 0;
                    flag = false;
                }
            }
            else grid[i][c-1] = 0;
        }

        for (int i = r-2; i>=0; i--) {
            for (int j = c-2; j>=0; j--) {
                if (!obstacleGrid[i][j]) {
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
                }
                else grid[i][j] = 0;
            }
        }

        return grid[0][0];
    }
};