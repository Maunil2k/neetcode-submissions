class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (auto& row: board) {
            vector<int> count(10, 0);
            for (auto& r: row) {
                if (r != '.') {
                    int a = r - '0';
                    if (a>9 || a<1 || count[a]==1) return false;
                    else count[a]++;
                } 
            }
        }

        // check column 
        for (int i=0; i<9; i++) {
            vector<int> count(10, 0);
            for (int j=0; j<9; j++) {
                if (board[j][i] != '.') {
                    int a = board[j][i] - '0';
                    if (a>9 || a<1 || count[a]==1) return false;
                    else count[a]++;
                }
            }
        }

        // check sub-square
        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3) {
                vector<int> count(10, 0);
                for (int x=0; x<3; x++) {
                    for (int y=0; y<3; y++) {
                        if (board[i+x][j+y] != '.') {
                            int a = board[i+x][j+y] - '0';
                            if (a>9 || a<1 || count[a]==1) return false;
                            else count[a]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
