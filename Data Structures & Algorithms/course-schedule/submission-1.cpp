class Solution {
public:
    bool dfs(vector<vector<int>> &adjList, vector<int> &visited, int node) {
        if (visited[node]) return false;
        visited[node] = 1;
        for (auto p: adjList[node]) {
            bool res = dfs(adjList, visited, p);
            if (!res) return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto &p: prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }
        
        vector<int> visited(numCourses, 0);
        for (int i = 0; i<numCourses; i++) {
            if (!visited[i]) {
                bool r = dfs(adjList, visited, i);
                if (!r) return false;
            }
        }
        return true;
    }
};
