class Solution {
private:

public:
    string longestPalindrome(string s) {
        int n = s.size(), res_len = 0;
        string res;
        for (int i = 0; i<n; i++) {
            // Odd length strings
            int l = i, r = i;
            while(l>=0 && r<n && s[l] == s[r]) {
                if (r-l+1>res_len) {
                    res = s.substr(l, r-l+1);
                    res_len = r-l+1;
                }
                l--;
                r++;
            }

            // Even length strings
            l = i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                if (r-l+1>res_len) {
                    res = s.substr(l, r-l+1);
                    res_len = r-l+1;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
