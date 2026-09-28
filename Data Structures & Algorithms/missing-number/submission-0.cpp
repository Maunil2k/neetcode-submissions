class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint32_t n = nums.size();
        uint32_t sum = n * (n+1) / 2;
        return (int) (sum - (uint32_t) accumulate(nums.begin(), nums.end(), 0));
    }
};
