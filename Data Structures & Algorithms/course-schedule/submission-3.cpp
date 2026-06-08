class Solution {
public:
    bool dfs(vector<vector<int>> &adjList, vector<int> &dfsVisits, int node, vector<int> &visited) {
        if (dfsVisits[node]) return false;
        dfsVisits[node] = 1;
        visited[node] = 1;
        for (auto p: adjList[node]) {
            bool res = dfs(adjList, dfsVisits, p, visited);
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
                vector<int> dfsVisits(numCourses, 0);
                bool r = dfs(adjList, dfsVisits, i, visited);
                if (!r) return false;
            }
        }
        return true;
    }
};
