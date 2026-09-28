class Solution {
private:
    bool isCap(int cap, vector<int>& weights, int days) {
        int required_days = 1;
        int curr_weight = 0;
        
        for (int w : weights) {
            // If adding this package exceeds capacity, ship it on the next day
            if (curr_weight + w <= cap) {
                curr_weight += w; // FIX: Accumulate the weight
            } else {
                required_days++;
                curr_weight = w; // Start the next day with the current package
            }
        }
        return required_days <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // The minimum possible capacity is the heaviest single package.
        // The maximum possible capacity is the sum of all packages shipped in 1 day.
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        // Binary search directly over the range [l, r] without allocating a vector
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (isCap(mid, weights, days)) {
                ans = mid;     // mid is a valid capacity, try to find a smaller one
                r = mid - 1;
            } else {
                l = mid + 1;   // mid is too small, increase capacity
            }
        }
        return ans;
    }
};