class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto &t: times) adjList[t[0]].push_back({t[1], t[2]});
        vector<int> visited(n+1, 0);
        int t = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            if (visited[curr.second]) continue;
            visited[curr.second] = 1;
            t = curr.first;
            for (auto &e: adjList[curr.second]) {
                if (!visited[e.first]) {
                    minHeap.push({curr.first + e.second, e.first});
                }
            }
            
        }
        for (int i = 1; i<=n; i++) {
            if (!visited[i]) return -1;
        }
        return t;
    }
};
