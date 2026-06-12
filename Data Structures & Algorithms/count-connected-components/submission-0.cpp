class Solution {
private:
    void dfs(int n, vector<vector<int>> &adjList, vector<int> &visited) {
        if (visited[n]) return;
        visited[n] = 1;
        for (auto &i:adjList[n]) dfs(i, adjList, visited);
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto &e: edges) adjList[e[0]].push_back(e[1]);
        vector<int> visited(n, 0);
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
