class Solution {
public:
    bool validPalindrome(string s) {
        int errs = 1;
        int l = 0, r = s.size()-1;
        while (l<r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }


            else {
                if (!errs) return false;
                else {
                    errs = 0;
                    r--;
                }
            }
        }
        return true;
    }
};