class Solution {
public:
    void recursion(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        // take condition
        curr.push_back(nums[i]);
        recursion(nums, curr, res, i+1);

        // pass condition
        curr.pop_back();
        recursion(nums, curr, res, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int i = 0;
        recursion(nums, curr, res, i);
        return res; 
    }
};
