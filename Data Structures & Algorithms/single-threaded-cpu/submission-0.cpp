class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        time += tasks[0][0] + tasks[0][1];
        vector<int> ans;
        ans.push_back(tasks[0][2]);
        for (int i = 1; i<n; i++) {
            if (tasks[i][0] <= time) minHeap.push({tasks[i][1], tasks[i][2]});
            else if (!minHeap.empty()){
                pair<int, int> tmp = minHeap.top();
                minHeap.pop();
                time+=tmp.first;
                ans.push_back(tmp.second);
                i--;                
            }
            else {
                time+=tasks[i][1];
                ans.push_back(tasks[i][2]);
            }
        }

        while(!minHeap.empty()) {
            pair<int, int> t = minHeap.top(); minHeap.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};