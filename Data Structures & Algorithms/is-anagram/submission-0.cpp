class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> char_counts;
        for (int i =0; i<s.length(); i++) char_counts[s[i]] += 1;
        for (int i=0; i<t.length(); i++) {
            if (char_counts[t[i]] == 0) return false;
            else char_counts[t[i]] -= 1;
        }
        return true;
    }
};
