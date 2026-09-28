class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (r-l>1) {
            int m = (l+r)/2;
            if (m*m <= x) l = m;
            else r = m - 1;
        }
        return r;
    }
};