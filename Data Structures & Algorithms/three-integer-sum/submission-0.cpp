class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            int target = 0 - nums[i];
            unordered_map <int, int> diff;
            for (int j=i+1; j<nums.size(); j++) {
                if (diff.find(nums[j]) != diff.end()) {
                    vector <int> comb = {nums[i], nums[j], nums[diff[nums[j]]]};
                    sort(comb.begin(), comb.end());
                    res.insert(comb);
                }
                diff.insert({target-nums[j], j});
            }
        }
        vector<vector<int>> final_res; 
        for (auto& item: res) final_res.push_back(item);
        return final_res;
    }
};
