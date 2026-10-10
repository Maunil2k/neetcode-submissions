class Solution {
private:
    struct PairHash { size_t operator()(const pair<int, int>& p) const { return hash<int>()     (p.first) ^ hash<int>()(p.second); } };

    int dfs(int i, int target, unordered_map<pair<int, int>, int, PairHash> &dp, vector<int> &nums) {
        if (i==nums.size()) return target ? 0 : 1;
        if (dp.find({i, target}) != dp.end()) return dp[{i, target}];
        
        // add and subtract
        dp[{i, target}] = dfs(i+1, target-nums[i], dp, nums) + dfs(i+1, target+nums[i], dp, nums);
        return dp[{i, target}];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, PairHash> dp;
        return dfs(0, target, dp, nums);
    }
};
