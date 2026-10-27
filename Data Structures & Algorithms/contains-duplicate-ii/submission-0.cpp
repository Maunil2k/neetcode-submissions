class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> pos;
        for (int i = 0; i<nums.size(); i++) {
            if (pos.find(nums[i]) == pos.end()) pos[nums[i]] = i;
            else {
                if (abs(pos[nums[i]] - i) <= k) return true;
            }
        }
        return false;
    }
};