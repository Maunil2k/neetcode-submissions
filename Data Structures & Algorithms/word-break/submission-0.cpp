class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        for (int i = s.size()-1; i>=0; i--) {
            for (auto &w: wordDict) {
                if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
                    if (dp[i+w.size()]) dp[i] = dp[i+w.size()];
                    else dp[i] = false;
                }
            }
        }
        
        return dp[0];
    }
};
