class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        int ans = 1, left = 0, n = s.size();
        set<char> vals;
        for (int right = 0; right < n; right++) {
            if (!vals.contains(s[right])) {
                vals.insert(s[right]);
                ans = max(ans, right - left + 1);
            }
            else {
                ans = max(ans, right - left);
                while (vals.contains(s[right])) {
                    vals.erase(s[left]);
                    left++;
                }
                vals.insert(s[right]);
            }
        }
        return ans;
    }
};
