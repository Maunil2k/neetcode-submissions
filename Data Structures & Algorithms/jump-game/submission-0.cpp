class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        int target = n - 1;
        for (int i = n-2; i>=0; i--) {
            if (i + nums[i] >= target) {
                dp[i] = 1;
                target = i;
            }
        }
        return dp[0];
    }
};
