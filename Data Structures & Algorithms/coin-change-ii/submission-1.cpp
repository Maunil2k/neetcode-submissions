class Solution {
private:
    int dfs(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (i>=coins.size() || amount < 0) return 0;
        if (amount == 0) return 1;
        if (dp[i][amount] != -1) return dp[i][amount];
        // Take + Skip
        dp[i][amount] = dfs(i, amount-coins[i], coins, dp) + dfs(i+1, amount, coins, dp);
        return dp[i][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, dp);  
    }
};
