class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (!nums.size()) return {{}};
        vector<int> tmp(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(tmp);
        vector<vector<int>> res;
        for (const auto &comb: perms) {
            for (int i = 0; i<=comb.size(); i++) {
                vector<int> tmp = comb;
                tmp.insert(tmp.begin() + i, nums[0]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
