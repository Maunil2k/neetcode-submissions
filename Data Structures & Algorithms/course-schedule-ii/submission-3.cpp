class Solution {
private:
    vector<int> ans;
    bool dfs(int& curr, vector<int>& visits, vector<vector<int>> adjl) {
        // visit - 0: not attended, 1: completed, 2: under-process
        if (visits[curr] == 2) return false;
        if (visits[curr] == 1) return true;
        visits[curr] = 2;
        for (auto& n: adjl[curr]) {
            bool res = dfs(n, visits, adjl);
            if (!res) return false;
        }
        visits[curr] = 1;
        ans.push_back(curr);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjl(numCourses);
        for (auto& p: prerequisites) adjl[p[0]].push_back(p[1]);
        vector<int> visits(numCourses, 0);
        for (int i = 0; i<numCourses; i++) {
            if (visits[i] == 0) {
                bool res = dfs(i, visits, adjl);
                if (!res) return {};
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
