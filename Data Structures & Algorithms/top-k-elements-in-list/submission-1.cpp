class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (auto& n: nums) {
            if (freq.find(n) != freq.end()) freq[n]++;
            else freq.insert({n, 1});
        }

        vector<vector<int>> rev_idx(nums.size()+1);
        for (auto& p: freq) rev_idx[p.second].push_back(p.first);

        vector<int> res;
        int i = nums.size();
        while (k>0 && i>=0) {
            if (rev_idx[i].size()) {
                for (auto& x: rev_idx[i]) res.push_back(x);
                k-=rev_idx[i].size();
            }
            i--;
        }

        return res;
    }
};
