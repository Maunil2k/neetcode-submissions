class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0], currmin=nums[0], currmax=nums[0];
        int n = nums.size();
        for (int i = 1; i<n; i++) {
            int tmpmax = currmax;

            currmax = max({
                nums[i],
                tmpmax * nums[i],
                currmin * nums[i]
            });

            currmin = min({
                nums[i],
                tmpmax * nums[i],
                currmin * nums[i]
            });

            ans = max(ans, currmax);
        }
        return ans;
    }
};
