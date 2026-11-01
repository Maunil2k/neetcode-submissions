class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<vector<int>>> adj(n+1); // 1 -> [[2, 1], [4, 4]]
        for (auto& edge: times) adj[edge[0]].push_back({edge[1], edge[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        dist[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            pair<int, int> tmp = minHeap.top(); minHeap.pop();
            if (tmp.first > dist[tmp.second]) continue;
            int d = tmp.first, node = tmp.second;

            for (auto& edge: adj[node]) {
                if (d + edge[1] < dist[edge[0]]) {
                    dist[edge[0]] = d + edge[1];
                    minHeap.push({dist[edge[0]], edge[0]});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i<=n; i++) {
            if (dist[i] == INT_MAX) return -1;
            else if (dist[i] > ans) ans = dist[i];
        }

        return ans;
    }
};
