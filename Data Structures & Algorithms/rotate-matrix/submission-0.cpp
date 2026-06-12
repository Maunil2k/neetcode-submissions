class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        // Flip left-right
        int l = 0, r = n-1;
        while (l<r) {
            for (int i = 0; i<n; i++) {
                int tmp = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = tmp; 
            }
            l++;
            r--;
        }
        return;
    }
};
