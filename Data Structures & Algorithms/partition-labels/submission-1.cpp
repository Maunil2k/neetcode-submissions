class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastidx;
        int n = s.size();
        for (int i = 0; i<n; i++) lastidx[s[i]] = i;
        vector<int> res;
        int start = 0, end = 0;
        while (end < n) {
            for (int i=start; i<=end; i++) {
                if (end < lastidx[s[i]]) end = lastidx[s[i]];
            }
            res.push_back(end - start + 1);
            end = end+1;
            start = end;
        }

        return res;
    }
};
