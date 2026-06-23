class Solution {
public:
    void dfs(int &amount, vector<int>& coins, int &ans, int i, int curr_sum) {
        if (curr_sum == amount) {
            ans++;
            return;
        }
        if (i>=coins.size() || curr_sum > amount) return;
        dfs(amount, coins, ans, i, curr_sum+coins[i]);
        dfs(amount, coins, ans, i+1, curr_sum);
        return;
    }
    int change(int amount, vector<int>& coins) {
        int ans = 0;
        dfs(amount, coins, ans, 0, 0);
        return ans;
    }
};
