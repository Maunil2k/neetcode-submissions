class Solution {
private:
    vector<vector<int>> ans;
    void recursion(int idx, vector<int>& curr, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // take
        curr.push_back(nums[idx]);
        recursion(idx+1, curr, nums);

        // skip
        curr.pop_back();
        recursion(idx+1, curr, nums);

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        recursion(0, curr, nums);
        return ans;
    }
};
