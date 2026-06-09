class Solution {
private:
    int nc;
    vector<int> completed;

public:
    bool dfs(int node, vector<int> visited, vector<int> &ans, vector<vector<int>> &adjList) {
        if (visited[node]) return false;
        if (adjList[node].size() == 0 || completed[node]) {
            if (!completed[node]) {
                ans.push_back(node);
                completed[node] = 1;
            }
            return true;
        }
        visited[node] = 1;
        for (auto &p: adjList[node]) {
            bool res = dfs(p, visited, ans, adjList);
            if (!res) return false;
        }
        ans.push_back(node);
        completed[node] = 1;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        nc = numCourses;
        vector<int> ans;
        vector<vector<int>> adjList(nc);
        for (auto &p: prerequisites) adjList[p[0]].push_back(p[1]);
        completed.assign(nc, 0);
        for (int i = 0; i<numCourses; i++) {
            if (!completed[i]) {
                vector<int> visited(nc, 0);
                bool res = dfs(i, visited, ans, adjList);
                if (!res) return {};
            }
        }
        return ans;
    }
};
