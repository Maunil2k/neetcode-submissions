class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (char c : s1) freq[c - 'a']++;

        int n = s1.size();
        for (int i = 0; i + n <= s2.size(); i++) {
            vector<int> temp = freq;
            bool ok = true;

            for (int j = i; j < i + n; j++) {
                int k = s2[j] - 'a';

                if (temp[k] == 0) {
                    ok = false;
                    break;
                }

                temp[k]--;
            }

            if (ok) return true;
        }

        return false;
    }
};