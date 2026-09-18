class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_idx = -1, zero_counts = 0;
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                zero_idx = i;
                zero_counts++;
                if (zero_counts > 1) return res;
            }
        }

        if (zero_counts) {
            int prod = 1;
            for (int i = 0; i<nums.size(); i++) 
                if (i != zero_idx) prod = prod * nums[i];
            res[zero_idx] = prod;
        }

        else {
            int prod = 1;
            for (int i = 0; i<nums.size(); i++) prod = prod * nums[i];
            for (int i = 0; i<nums.size(); i++) res[i] = prod / nums[i]; 
        }

        return res;
    }
};
