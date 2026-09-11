class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int pw = abs(n);
        for (int i = 0; i<pw; i++) ans *= x;
        return n<0 ? 1.0/ans: ans;
    }
};
