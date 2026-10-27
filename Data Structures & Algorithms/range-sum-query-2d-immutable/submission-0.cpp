class NumMatrix {
private:
    vector<vector<int>> prefixsum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        prefixsum = vector<vector<int>>(r+1, vector<int>(c+1, 0));
        for (int i = 0; i<r; i++) {
            int prefix = 0;
            for (int j = 0; j<c; j++) {
                prefix += matrix[i][j];
                prefixsum[i+1][j+1] = prefix + prefixsum[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; row2++; col1++; col2++;
        int bottomRight = prefixsum[row2][col2];
        int above = prefixsum[row1-1][col2];
        int below = prefixsum[row2][col1-1];
        int top = prefixsum[row1-1][col1-1];
        return bottomRight - above - below + top;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */