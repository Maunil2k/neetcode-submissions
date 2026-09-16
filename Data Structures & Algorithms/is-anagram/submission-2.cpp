class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.size();
        vector<int> counts(26, 0);
        for (auto &c: s) {
            int j = c - 'a';
            counts[j]+=1;
        }

        for (auto &c: t) {
            int j = c - 'a';
            if (counts[j] == 0) return false;
            else counts[j]-=1;
        }

        for (int i = 0; i<26; i++) if (counts[i] != 0) return false;
        return true;
    }
};
