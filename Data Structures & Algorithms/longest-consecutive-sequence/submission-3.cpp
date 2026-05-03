class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        set <int> p;
        int res = 1;
        for (auto& n: nums) p.insert(n);

        for (auto& n: nums) {
            int i = 1;
            if (!p.count(n-1)) {
                while (1) {
                    if (p.count(n+i)) {
                        if (i+1 > res) res = i+1;
                        i++;
                    }

                    else break;
                }
            }
        }

        return res;
    }
};
