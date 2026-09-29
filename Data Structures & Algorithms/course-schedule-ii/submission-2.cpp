class Solution {
private:
    bool dfs(vector<int>& state, int u, vector<int>& order, vector<vector<int>>& adjList) {
        // state 0 -> not visited (need to compute)
        // state 1 -> in the recursion stack (DAG) (return false)
        // state 2 -> visited (return true)
        if (state[u] == 1) return false;
        else if (state[u] == 2) return true;
        state[u] = 1;
        for (auto& n: adjList[u]) if (!dfs(state, n, order, adjList)) return false;
        order.push_back(u);
        state[u] = 2;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (auto& p: prerequisites) adjList[p[1]].push_back(p[0]);
        vector<int> ans;
        for (int i = 0; i<numCourses; i++) {
            if (!state[i] && !dfs(state, i, ans, adjList)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
