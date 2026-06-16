class Solution {
private:
    int house_robber_1(vector<int> &nums) {
        int r1 = 0, r2 = 0;
        for (auto n: nums) {
            int tmp = max(n+r2, r1);
            r2 = r1;
            r1 = tmp;
        }
        return max(r1, r2);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(house_robber_1(v1), house_robber_1(v2));
    }
};
