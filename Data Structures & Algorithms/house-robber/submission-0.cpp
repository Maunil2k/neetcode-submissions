class Solution {
public:
    int rob(vector<int>& nums) {
       int a1 = 0, a2 = 0;
       for (int i = 0; i<nums.size(); i+=2) a1+=nums[i];
       for (int i = 1; i<nums.size(); i+=2) a2+=nums[i];
       return max(a1, a2);
    }
};
