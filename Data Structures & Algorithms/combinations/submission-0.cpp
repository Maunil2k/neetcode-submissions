class Solution {
private:
    void dfs(int k, int n, int idx, vector<int>& curr, vector<vector<int>>& res) {
        if (idx > n) {
            if (curr.size() == k) res.push_back(curr);
            return;
        }

        // take
        curr.push_back(idx);
        dfs(k, n, idx+1, curr, res);

        // skip
        curr.pop_back();
        dfs(k, n, idx+1, curr, res);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(k, n, 1, curr, res);
        return res;
    }
};