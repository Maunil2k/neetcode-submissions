class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto c: tasks) freq[c-'A']++;
        priority_queue<int> heap;
        queue<pair<int, int>> q;
        for (auto i: freq) {
            if (i>0) heap.push(i);
        }
        int ans = 0;
        while (!heap.empty() || !q.empty()) {
            ans++;
            if (!heap.empty()) {
                int cnt = heap.top();
                cnt--;
                heap.pop();
                if (cnt) {
                    pair<int, int> next = {cnt, ans+n};
                    q.push(next);
                }
            }

            if (!q.empty()) {
                pair<int, int> front = q.front();
                if (front.second == ans) {
                    heap.push(front.first);
                    q.pop();
                }
            }
        }

        return ans;
    }
};
