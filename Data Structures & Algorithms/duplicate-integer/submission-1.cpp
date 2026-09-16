class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto &n: nums) {
            if (counts.find(n) != counts.end()) return true;
            else counts[n] = 1;
        }
        return false;
    }
};