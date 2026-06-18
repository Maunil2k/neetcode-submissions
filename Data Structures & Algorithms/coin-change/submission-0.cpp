class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+1, amount+1);
        mem[0] = 0;
        for (int i = 1; i<amount+1; i++) {
            for (auto &c: coins) {
                if (i - c >= 0) {
                    mem[i] = min(mem[i], 1 + mem[i-c]);
                }
            }
        }
        return mem[amount] > amount ? -1 : mem[amount];
    }
};
