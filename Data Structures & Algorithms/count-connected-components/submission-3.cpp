class Solution {
private:
    void dfs(int n, vector<vector<int>> &adjList, vector<bool> &visited) {
        visited[n] = true;
        for (auto &i:adjList[n]) {
            if (!visited[i]) dfs(i, adjList, visited);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto &e: edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i<n; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                ans++;
            }
        }
        return ans;
    }
};
