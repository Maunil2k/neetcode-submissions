class Solution {
private:
    vector<vector<int>> ans;
    void recursion(int idx, vector<int>& curr, vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx == nums.size() || target < 0) return;

        // re-take
        curr.push_back(nums[idx]);
        recursion(idx, curr, nums, target - nums[idx]);

        // delete 
        curr.pop_back();
        recursion(idx+1, curr, nums, target);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        recursion(0, curr, nums, target);
        return ans;
    }
};
