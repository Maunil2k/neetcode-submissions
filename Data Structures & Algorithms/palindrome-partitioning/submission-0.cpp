class Solution {
private:
    vector<vector<string>> res;
public:
    void dfs(int idx, vector<string> &part, string &s) {
        if (idx >= s.size()) {
            res.push_back(part);
            return;
        }

        for (int i = idx; i<s.size(); i++) {
            // check if the string s[0:i] is a palindrome
            bool is_palindrome = true;
            for (int j = 0; j<=idx/2; j++) {
                if (s[j] != s[idx-j]) {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome) {
                part.push_back(s.substr(idx, i+1-idx));
                dfs(i+1, part, s);
                part.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, part, s);
        return res;
    }
};
