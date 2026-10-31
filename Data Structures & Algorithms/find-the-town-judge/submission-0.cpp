class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> edges(n+1, -1);
        for(auto &t:trust) edges[t[0]] = t[1];
        int flag = 0;
        int ans = -1;
        for(int i = 1; i<=n; i++) {
            if (edges[i] == -1 && flag == 0) {
                flag++;
                ans = i;
            }
            else if (edges[i] == -1 && flag == 1) return -1;
        }
        return ans;
    }
};