class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice = 0, bob = 0;
        int l = 0, r = piles.size() - 1;
        bool alice_turn = true;
        while (l<r) {
            int val;
            if (piles[l] < piles[r]) {
                val = piles[r];
                r--;
            }
            else {
                val = piles[l];
                l++;
            }
            if (alice_turn) {
                alice += val;
                alice_turn = false;
            }
            else {
                bob += val;
                alice_turn = true;
            }
        }
        return alice > bob;
    }
};