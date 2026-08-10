class Solution {
public:
    bool dfs(int i, vector<int> &visits, int prev, vector<vector<int>> &adjList) {
        if (visits[i]) return false;

        visits[i] = 1;
        for (auto &p: adjList[i]) {
            if (p == prev) continue;
            if (!dfs(p, visits, i, adjList)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (!n) return true;
        vector<vector<int>> l(n);
        for (auto &e: edges) {
            l[e[0]].push_back(e[1]);
            l[e[1]].push_back(e[0]);
        }
        vector<int> visits(n, 0);
        bool loop = dfs(0, visits, -1, l);
        if (!loop) return false;
        for (auto &i: visits) if (!i) return false;
        return true;
    }
};
