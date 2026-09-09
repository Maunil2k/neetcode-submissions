class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (auto &t: nums) target+=t;
        if (target % 2 != 0) return false;
        target = target / 2;
        set<int> dp;
        dp.insert(0);
        dp.insert(nums.back());
        int n = nums.size();

        for (int i = n-2; i>=0; i--) {
            set<int> tmp = dp;
            for (auto t: tmp) dp.insert(t+nums[i]);
        }

        return dp.find(target) == dp.end() ? false : true;
    }
};
