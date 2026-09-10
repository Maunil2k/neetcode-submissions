class Solution {
public:
    bool checkValidString(string s) {
        stack<char> par, star;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '(') par.push('(');
            else if (s[i] == ')') {
                if (!par.empty()) par.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
            else star.push('*');
        }

        while (!par.empty() && !star.empty()) {
            if (par.top() > star.top()) return false;
            star.pop();
            par.pop();
        }

        return par.empty();
    }
};
