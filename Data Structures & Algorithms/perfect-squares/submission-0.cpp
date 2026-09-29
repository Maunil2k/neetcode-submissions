class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);

        // Base case:
        // 0 requires 0 perfect squares.
        dp[0] = 0;

        for (int target = 1; target <= n; target++) {

            // Try every perfect square <= target.
            for (int s = 1; s * s <= target; s++) {

                int square = s * s;

                dp[target] = min(
                    dp[target],
                    1 + dp[target - square]
                );
            }
        }

        return dp[n];
    }
};