class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0, start = 0, end = heights.size() - 1;
        while (start < end) {
            int area = (end - start) * min(heights[start], heights[end]);
            if (area > ans) ans = area;
            if (heights[start] > heights[end]) end--;
            else start++;
        }
        return ans;
    }
};
