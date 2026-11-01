class Solution {
private:
    bool dfs(int curr, vector<vector<int>>& adjl, vector<int>& visit) {
        if (visit[curr] == 2) return false;
        if (visit[curr] == 1) return true;
        visit[curr] = 2;
        for (auto& n: adjl[curr]) {
            bool res = dfs(n, adjl, visit);
            if (!res) return false;
        }
        visit[curr] = 1;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjl(numCourses);
        for (auto& p: prerequisites) adjl[p[0]].push_back(p[1]);
        vector<int> visit(numCourses, 0); // 0: not visited, 1: visited, 2: in-stack
        for (int i = 0; i<numCourses; i++) {
            if (visit[i] == 0) {
                bool res = dfs(i, adjl, visit);
                if (!res) return false;
            }
        }

        return true;
    }
};
