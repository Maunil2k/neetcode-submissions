class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> widths;
        widths.push({heights[0], 0});
        int ans = INT_MIN;
        for (int i = 1; i<heights.size(); i++) {
            if (heights[i] > widths.top().first) {
                widths.push({heights[i], i});
            }

            else if (!widths.empty() && heights[i] < widths.top().first) {
                int idx; 
                while (!widths.empty() && heights[i] < widths.top().first) {
                    idx = widths.top().second;
                    int h = widths.top().first;
                    widths.pop();
                    ans = max(ans, h * (i - idx));
                }
                widths.push({heights[i], idx});
            }
        }
        int i = heights.size();
        while (!widths.empty()) {
            int h = widths.top().first, idx = widths.top().second;
            ans = max(ans, h * (i - idx));
            widths.pop();
        }

        return ans;
    }
};
