class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = s.size()-1; 
        while (l<r) {
            if (s[l] == '*' || s[r]=='*') {
                l++;
                r--;
            }
            else if (s[l] == '(' && s[r] == ')') {
                l++;
                r--;
            }
            else return false;
        }
        if (l==r) {
            if (s[l] == '(' || s[l] == ')') return false;
            else return true;
        } 
        return true;
    }
};
