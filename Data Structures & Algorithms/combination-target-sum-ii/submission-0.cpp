class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int> &candidates, vector<int> &curr, int total, int i) {
        if (!total) {
            res.push_back(curr);
            return;
        }

        if (i >= candidates.size() || total < 0) return;

        curr.push_back(candidates[i]);
        dfs(candidates, curr, total-candidates[i], i+1); // it will consider duplicates

        curr.pop_back();
        while(i+1<candidates.size() && candidates[i] == candidates[i+1]) i++;

        dfs(candidates, curr, total, i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, curr, target, 0);
        return res;
    }
};
