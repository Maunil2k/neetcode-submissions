class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> max_vals(nums.size(), -1);
        max_vals[n-1] = nums[n-1];
        max_vals[n-2] = max(nums[n-2], nums[n-1]);
        for (int i = n-3; i>=0; i--) {
            max_vals[i] = max(max_vals[i+1], nums[i]+max_vals[i+2]);
        }
        return max_vals[0];
    }
};
