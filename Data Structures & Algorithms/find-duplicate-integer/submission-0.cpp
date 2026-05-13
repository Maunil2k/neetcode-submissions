class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set <int> s;
        for (auto i: nums) {
            if (s.find(i) != s.end()) return i;
            else s.insert(i);
        }
        return -1;
    }
};
