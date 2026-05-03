class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx_map;
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if (val_idx_map.find(diff) != val_idx_map.end())
                return {val_idx_map[diff], i};
            
            else
                val_idx_map.insert({nums[i], i});
        }
        return {};
    }
};
