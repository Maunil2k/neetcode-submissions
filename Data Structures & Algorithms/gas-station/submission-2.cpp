class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0, n = cost.size(), total = 0;
        vector<int> diff(n, 0);
        for (int i = 0; i<n; i++) {
            diff[i] = gas[i] - cost[i];
            total += diff[i];
        }
        if (total < 0) return -1;
        total = 0;
        for (int i = 0; i<n; i++) {
            total += diff[i];
            if (total < 0) {
                ans = i;
                total = 0;
            }
        }
        return ans+1;
    }
};
