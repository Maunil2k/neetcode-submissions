class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, ans = 0;
        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            if (ans < area) ans = area;
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
