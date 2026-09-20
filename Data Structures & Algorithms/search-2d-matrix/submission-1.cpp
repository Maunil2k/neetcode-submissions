class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> vec;
        for (auto x: matrix) {
            vec.insert(vec.end(), x.begin(), x.end());
        }
        int l = 0, r = vec.size()-1;
        while(l<=r) {
            int m = (l+r)/2;
            if (vec[m] == target) return true;
            else if (vec[m] < target) l = m+1;
            else r = m-1;
        }
        return false;
    }
};
