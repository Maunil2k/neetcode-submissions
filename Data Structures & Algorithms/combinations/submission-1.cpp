class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void recursion(int& k, int& n, int i) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        if (i == n+1 || curr.size() > k) return;

        // take
        curr.push_back(i);
        recursion(k, n, i+1);

        // skip
        curr.pop_back();
        recursion(k, n, i+1);

        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        recursion(k, n, 1);
        return ans;
    }
};