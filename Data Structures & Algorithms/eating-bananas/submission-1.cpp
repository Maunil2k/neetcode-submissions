class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_k = *max_element(piles.begin(), piles.end());
        // cout << max_k <<endl;
        vector<int> v(max_k); // Create vector of size n
        std::iota(v.begin(), v.end(), 1); // Fill with 1, 2, ..., n
        // for (int p: v) cout << p;
        int ans = max_k;
        int l = 0, r = v.size() - 1;

        while (l <= r) {
            int m = (l+r)/2;
            int rate = v[m];
            long long time = 0;
            for (int p : piles) {
                time += ceil(double(p) / rate); 
            }

            if (time <= h) {
                ans = rate;
                r = m - 1;
            }

            else l = m + 1;
        }

        return ans;
    }
};
