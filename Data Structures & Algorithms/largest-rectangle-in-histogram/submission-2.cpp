class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> x;
        int ans = 0;
        for (int i=0; i<heights.size(); i++) {
            int start = i;
            while (!x.empty() && x.top().second > heights[i]) {
                pair <int, int> t = x.top();
                if (ans < t.second * (i - t.first)) {
                    ans = t.second * (i - t.first);
                }
                start = t.first;
                x.pop();
            }
            x.push({start, heights[i]});
        }

        while (!x.empty()) {
            pair <int, int> t = x.top();
            int tmp = t.second * (heights.size() - t.first);
            if (tmp > ans) ans = tmp;
            x.pop();
        }

        return ans;
    }
};
