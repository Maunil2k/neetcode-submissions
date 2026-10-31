class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() != n-1) return -1;
        vector<int> delta(n+1, 0);
        for(auto &t:trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }

        for(int i = 1; i<=n; i++) {
            if (delta[i] != -1 && delta[i] != n-1) return -1;
            else if (delta[i] == n-1) return i;
        }
    }
};