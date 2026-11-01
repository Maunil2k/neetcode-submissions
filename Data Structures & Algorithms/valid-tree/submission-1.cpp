class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjl(n);
        for (auto& e: edges) {
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }
        vector<int> visits(n, 0); // visits - 0: not visited, 1: visited, 2: in-queue
        queue<int> bfs;
        bfs.push(0);
        visits[0] = 2;
        while (!bfs.empty()) {
            int curr = bfs.front();
            bfs.pop();
            for (auto& n: adjl[curr]) {
                if (visits[n] == 2) return false;
                else if (visits[n] == 0) {
                    bfs.push(n);
                    visits[n] = 2;
                }
            }
            visits[curr] = 1;
        }

        for (auto& i: visits) if (i == 0) return false;
        return true;
    }
};
