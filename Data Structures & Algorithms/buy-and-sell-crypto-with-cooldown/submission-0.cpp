class Solution {
private:
    struct PairHash { size_t operator()(const pair<int, bool>& p) const { return hash<int>()(p.first) ^ hash<bool>()(p.second); } };

    int dfs(
        int day,
        bool canbuy,
        vector<int>& prices,
        unordered_map<pair<int, bool>, int, PairHash>& dp
    ) {
        if (day >= prices.size()) return 0;
        if (dp.find({day, canbuy}) != dp.end()) return dp[{day, canbuy}];

        if (canbuy) 
            dp[{day, canbuy}] = max(
                dfs(day+1, !canbuy, prices, dp) - prices[day],
                dfs(day+1, canbuy, prices, dp)
            );

        else 
            dp[{day, canbuy}] = max(
                dfs(day+2, !canbuy, prices, dp) + prices[day],
                dfs(day+1, !canbuy, prices, dp)
            );

        return dp[{day, canbuy}];
    }

public:
    int maxProfit(vector<int>& prices) {
        unordered_map<pair<int, bool>, int, PairHash> dp;
        return dfs(0, true, prices, dp);
    }
};
