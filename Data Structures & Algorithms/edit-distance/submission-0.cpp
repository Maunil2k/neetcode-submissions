class Solution {
private:
    int dfs(
        string& word1,
        string& word2,
        int i,
        int j,
        vector<vector<int>>& dp
    ) {
        // word1 is exhausted
        if (i == word1.size()) {
            return word2.size() - j;
        }

        // word2 is exhausted
        if (j == word2.size()) {
            return word1.size() - i;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters already match
        if (word1[i] == word2[j]) {
            dp[i][j] = dfs(
                word1,
                word2,
                i + 1,
                j + 1,
                dp
            );

            return dp[i][j];
        }

        // Characters are different:
        //
        // Delete  -> dfs(i + 1, j)
        // Insert  -> dfs(i, j + 1)
        // Replace -> dfs(i + 1, j + 1)

        dp[i][j] = 1 + min({
            dfs(word1, word2, i + 1, j, dp),
            dfs(word1, word2, i, j + 1, dp),
            dfs(word1, word2, i + 1, j + 1, dp)
        });

        return dp[i][j];
    }

public:
    int minDistance(
        string word1,
        string word2
    ) {
        vector<vector<int>> dp(
            word1.size(),
            vector<int>(word2.size(), -1)
        );

        return dfs(word1, word2, 0, 0, dp);
    }
};