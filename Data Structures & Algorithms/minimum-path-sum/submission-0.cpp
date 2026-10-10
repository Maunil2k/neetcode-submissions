class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> mincost(r, vector<int>(c, 0));
        mincost[r-1][c-1] = grid[r-1][c-1];
        for (int i = r-2; i>=0; i--) mincost[i][c-1] = grid[i][c-1] + mincost[i+1][c-1];
        for (int i = c-2; i>=0; i--) mincost[r-1][i] = grid[r-1][i] + mincost[r-1][i+1];
        for (int i = r-2; i>=0; i--) for (int j = c-2; j>=0; j--) mincost[i][j] = min(mincost[i+1][j], mincost[i][j+1]) + grid[i][j];
        return mincost[0][0];
    }
};