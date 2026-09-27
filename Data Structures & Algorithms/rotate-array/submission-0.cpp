class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        
        // 1. Reverse the entire vector
        std::reverse(nums.begin(), nums.end());
        // 2. Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);
        // 3. Reverse the remaining n - k elements
        std::reverse(nums.begin() + k, nums.end());
    }
};
