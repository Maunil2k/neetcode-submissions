class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int n = nums.size();
        for (int i = n-1; i>=0; i--) {
            for (int j = i; j<=n-1; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int ans = dp[0];
        for (auto &i: dp) {
            if (ans < i) ans = i;
        }
        return ans;
    }
};
