class Solution {
public:
    bool isHappy(int n) {
        set<int> sums;
        int new_sum = 0;
        while (1) {
            while (n) {
                int r = n % 10;
                new_sum += r*r;
                n = n / 10;
            }
            if (new_sum == 1) return true;
            else {
                if (sums.find(new_sum) != sums.end()) return false;
                else {
                    sums.insert(new_sum);
                    n = new_sum;
                    new_sum = 0;
                }
            }
        }
    }
};
