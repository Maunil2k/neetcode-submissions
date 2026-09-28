class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c: s) cnt[c-'a']++;

        int maxIdx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        if (cnt[maxIdx] > (n+1)/2) return "";
        string res(n, ' ');
        int i = 0;
        while (cnt[maxIdx] > 0) {
            res[i] = 'a' + maxIdx;
            i+=2;
            cnt[maxIdx]--;
        }

        for (int c = 0; c<26; c++) {
            while (cnt[c] > 0) {
                if (i>=n) i=1;
                res[i] = 'a' + c;
                i+=2;
                cnt[c]--;
            }
        }
        return res;
    }
};