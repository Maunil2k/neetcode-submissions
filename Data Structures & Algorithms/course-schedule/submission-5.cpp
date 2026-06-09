class Solution {
public:
    bool dfs(vector<vector<int>> &adjList, vector<int> &completed, int node, vector<int> visits, int &numCourses) {
        if (visits[node]) return false;

        if (completed[node] || adjList[node].size() == 0) {
            completed[node] = 1;
            return true;
        }

        visits[node] = 1;

        for (auto &p: adjList[node]) {
            bool res = dfs(adjList, completed, p, visits, numCourses);
            if (!res) return false;
            completed[p] = 1;
        }
        completed[node] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> completed(numCourses, 0);
        for (auto &pL: prerequisites) adjList[pL[0]].push_back(pL[1]);
        for (int i = 0; i<numCourses; i++) {
            if (!completed[i]) {
                vector<int> visits(numCourses, 0);
                bool res = dfs(adjList, completed, i, visits, numCourses);
                if (!res) return false;
            }
        }
        return true;
    }
};
