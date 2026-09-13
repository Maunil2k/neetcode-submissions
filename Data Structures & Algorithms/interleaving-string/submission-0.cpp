class Solution {
private:
    bool dfs(
        string& s1,
        string& s2,
        string& s3,
        int i,
        int j,
        vector<vector<int>>& dp
    ) {
        if (i>=s1.size() && j>=s2.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        bool res = false;
        if (i<s1.size() && s1[i] == s3[i+j]) res = dfs(s1, s2, s3, i+1, j, dp);
        if (!res && j<s2.size() && s2[j] == s3[i+j]) res = dfs(s1, s2, s3, i, j+1, dp);
        dp[i][j] = res ? 1 : 0;
        return res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }
};
