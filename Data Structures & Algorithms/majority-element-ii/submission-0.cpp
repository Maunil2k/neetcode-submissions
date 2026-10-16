class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int s = nums.size() / 3; 
        vector<int> ans;
        for (auto &n: nums) {
            if (freq.find(n) == freq.end()) freq[n] = 1;
            else freq[n]+=1;
        }

        for (auto &[k, v]: freq) if (v > s) ans.push_back(k);

        return ans;
    }
};