class Solution {
public:
    bool isValid(string s) {
       stack<char> par;
       for (int i =0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') par.push(s[i]);
            else {
                if (par.empty()) return false;
                char c = par.top();
                par.pop();
                if ((s[i] == ')' && c!='(') || (s[i] == ']' && c!='[') || (s[i] == '}' && c!='{')) return false;
            }
        }
        if (par.empty()) return true;
        else return false; 
    }
};
