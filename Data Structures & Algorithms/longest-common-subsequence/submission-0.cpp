class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> lcs(m, vector<int>(n, 0));
        if (text1[m-1] == text2[n-1]) lcs[m-1][n-1] = 1;
        for (int i = m-1; i>=0; i--) {
            for (int j = n-1; j>=0; j--) {
                if (i+1<=m-1 && j+1<=n-1 && text1[i+1] == text2[j+1]) lcs[i][j] = 1 + lcs[i+1][j+1];
                else if (i+1<=m-1 && j+1<=n-1) lcs[i][j] = max(lcs[i][j+1], lcs[i+1][j]);
                else if (i+1<=m-1) lcs[i][j] = lcs[i+1][j];
                else if (j+1<=n-1) lcs[i][j] = lcs[i][j+1];
            }
        }
        return lcs[0][0];
    }
};