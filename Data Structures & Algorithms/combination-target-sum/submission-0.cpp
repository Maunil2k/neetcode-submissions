class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(int i, vector<int> &curr, int total, vector<int> &nums) {
        if (!total) {
            res.push_back(curr);
            return;
        }

        if (i >= nums.size() || total < 0) return;

        curr.push_back(nums[i]);
        dfs(i, curr, total-nums[i], nums);

        curr.pop_back();
        dfs(i+1, curr, total, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int total = target;
        vector<int> curr;
        dfs(0, curr, total, nums);
        return res;
    }
};
