class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, vector<int> &curr, int i) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, curr, i+1);

        curr.pop_back();
        while(i+1<nums.size() && nums[i] == nums[i+1]) i++;
        dfs(nums, curr, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return res;
    }
};
