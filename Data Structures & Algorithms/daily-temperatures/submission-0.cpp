class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> pairs;
        vector<int> ans(temperatures.size(), 0);
        pairs.push({temperatures[0], 0});
        for (int i=1; i<temperatures.size(); i++) {
            if (temperatures[i] <= pairs.top().first) pairs.push({temperatures[i], i});
            else {
                while (1) {
                    if (!pairs.empty() && pairs.top().first < temperatures[i]) {
                        ans[pairs.top().second] = i - pairs.top().second;
                        pairs.pop();
                    }
                    else {
                        pairs.push({temperatures[i], i});
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
