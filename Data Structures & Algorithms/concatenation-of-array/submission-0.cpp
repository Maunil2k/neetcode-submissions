class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.reserve(2*nums.size());
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};