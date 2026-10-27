class Solution {
public:
    bool checkPalindromes(string s, int l, int r) {
        while (l<r) {
            if (s[l] != s[r]) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l<r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }

            else return checkPalindromes(s, l+1, r) || checkPalindromes(s, l, r-1);
            
        }
        return true;
    }
};