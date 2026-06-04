class Solution {
private:
    vector<vector<string>> res;
public:
    bool isPalindrome(string s, int i, int j) {
        while (i<j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(int idx, vector<string> &part, string &s) {
        if (idx >= s.size()) {
            res.push_back(part);
            return;
        }

        for (int i = idx; i<s.size(); i++) {
            // check if the string s[0:i] is a palindrome
            if (isPalindrome(s, idx, i)) {
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
