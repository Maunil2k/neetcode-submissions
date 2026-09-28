class Solution {
private:
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& curr) {
        if (idx >= nums.size()) {
            res.push_back(curr);
            return;
        }
        // take
        curr.push_back(nums[idx]);
        dfs(nums, idx+1, res, curr);

        // skip
        curr.pop_back();
        dfs(nums, idx+1, res, curr);
        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, res, curr);
        return res;
    }
};
