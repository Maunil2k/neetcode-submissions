class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> n(nums.size(), 0);
        for (auto i: nums) {
            if (n[i] >= 1) return i;
            else n[i]++;
        }
        return -1;
    }
};
