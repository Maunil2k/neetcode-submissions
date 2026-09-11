class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        int n = s.size();
        for (int i = 0; i<n; i++) {
            if (s[i] == '(') left.push(i);
            else if (s[i] == ')') {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
            else star.push(i);
        }

        while (!left.empty() && !star.empty()) {
            if (left.top() < star.top()) {
                left.pop();
                star.pop();
            }
            else return false;
        }

        return left.empty();
    }
};
