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

        if (par.empty()) return true;

        while (!star.empty()) {
            if (!par.empty()) {
                par.pop();
                star.pop();
            }
            else return true;
        } 

        return false;
    }
};
