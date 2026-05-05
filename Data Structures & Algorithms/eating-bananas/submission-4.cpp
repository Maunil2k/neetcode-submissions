class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int rate = (l+r)/2;
            long long time = 0;
            for (int p : piles) {
                time += ceil(static_cast<double>(p) / rate); 
            }

            if (time <= h) {
                ans = rate;
                r = rate - 1;
            }

            else l = rate + 1;
        }

        return ans;
    }
};
