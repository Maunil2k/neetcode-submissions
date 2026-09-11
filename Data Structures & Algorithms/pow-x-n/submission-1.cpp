class Solution {
private:
    double helper(double x, int n) {
        if (n == 0) return 1;
        double res = helper(x, n/2);
        res = res * res;
        return n%2 ? x * res : res;
    }
public:
    double myPow(double x, int n) {
        if (!x) return 0;
        double ans = helper(x, abs(n));
        return n < 0 ? 1.0/ans : ans;
    }
};
