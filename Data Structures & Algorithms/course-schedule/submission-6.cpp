class Solution {
private:
    bool dfs(vector<int>& state, int u, vector<vector<int>>& adjList) {
        // 0 -> not visited
        // 1 -> in the dfs stack
        // 2 -> completed
        if (state[u] == 1) return false;
        else if (state[u] == 2) return true;
        state[u] = 1;
        for (auto& n: adjList[u]) if (!dfs(state, n, adjList)) return false;
        state[u] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (auto& p: prerequisites) adjList[p[0]].push_back(p[1]);
        for (int i = 0; i<numCourses; i++) {
            if (!state[i] && !dfs(state, i, adjList)) return false;
        }
        return true;
    }
};
