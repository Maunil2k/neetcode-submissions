class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1, ans=0;
        while(r!=prices.size()) {
            if (prices[r]-prices[l] > ans) ans = prices[r] - prices[l];
            if (prices[l] > prices[r]) l = r;
            r++;
        }
        return ans;
    }
};
