class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n -1;
        int ans = 0;
        while (l<r) {
            if (nums[l] > nums[r]) ans += nums[l] - nums[r];
            else ans += nums[r] - nums[l];
            l++;
            r--;
        }
        return ans + nums[l];
    }
};
