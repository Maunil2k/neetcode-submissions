class Solution {
private:
    struct PairHash { size_t operator()(const pair<int, int>& p) const { return hash<int>()     (p.first) ^ hash<int>()(p.second); } };

    int dfs(int i, int sum, int& target, unordered_map<pair<int, int>, int, PairHash>& dp, vector<int>& nums) {
        if (i == nums.size()) return sum == target ? 1 : 0;
        if (dp.find({i, sum}) != dp.end()) return dp[{i, sum}];
        dp[{i, sum}] = dfs(i+1, sum+nums[i], target, dp, nums) + dfs(i+1, sum-nums[i], target, dp, nums);
        return dp[{i, sum}];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, PairHash> dp;
        return dfs(0, 0, target, dp, nums);
    }
};
