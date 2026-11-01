class Solution {
private:
    vector<vector<int>> ans;
    void recursion(int idx, vector<int>& curr, vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (idx >= nums.size() || target < 0) return;

        // take
        curr.push_back(nums[idx]);
        recursion(idx+1, curr, nums, target - nums[idx]);

        // skip 
        curr.pop_back();
        while(idx+1<nums.size() && nums[idx+1] == nums[idx]) idx++;
        recursion(idx+1, curr, nums, target);

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // set<int> u(candidates.begin(), candidates.end());
        // vector<int> final(u.begin(), u.end()), curr;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        recursion(0, curr, candidates, target);
        return ans;
    }
};
