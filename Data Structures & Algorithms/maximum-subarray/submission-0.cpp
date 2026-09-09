class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = nums[0], n = nums.size();
        for (int i = 1; i<n; i++) {
            sum += nums[i];
            if (sum < 0) sum = 0;
            ans = max(ans, sum);
        }
        return ans;
    }
};
