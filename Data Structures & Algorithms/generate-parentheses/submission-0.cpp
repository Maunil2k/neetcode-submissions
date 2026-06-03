class Solution {
private:
    vector<string> ans;
    string curr;
public:
    void backtrack(int openp, int closep, int n, string &curr) {
        if (openp == n && closep == n) {
            ans.push_back(curr);
            return;
        }

        if (openp < n) {
            curr.push_back('(');
            backtrack(openp+1, closep, n, curr);
            curr.pop_back();
        }

        if (closep < openp) {
            curr.push_back(')');
            backtrack(openp, closep+1, n, curr);
            curr.pop_back();
        }
    } 
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n, curr);
        return ans;
    }
};
