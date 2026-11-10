class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = INT_MIN, left = 0, n = s.size();
        set<char> vals;
        for (int right = 0; right < n; right++) {
            if (!vals.contains(s[right])) vals.insert(s[right]);
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
