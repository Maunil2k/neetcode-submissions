class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 0));
        ways[m-1][n-1] = 1;
        for (int i = m-1; i>=0; i--) {
            for (int j = n-1; j>=0; j--) {
                if (i+1<=m-1 && j+1<=n-1) {
                    ways[i][j] = ways[i][j+1] + ways[i+1][j];
                }
                else if (i+1<=m-1) ways[i][j] = ways[i+1][j];
                else if (j+1<=n-1) ways[i][j] = ways[i][j+1];
            }
        }
        return ways[0][0];
    }
};
