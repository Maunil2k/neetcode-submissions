class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        int n = nums.size();
        for (int i = 0; i<n; i++) {
            int d = target - nums[i];
            if (diff.find(d) != diff.end()) return {diff[d], i};
            diff[nums[i]] = i;
        }
    }
};
