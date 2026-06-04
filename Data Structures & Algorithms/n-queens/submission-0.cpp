class Solution {
private:
    vector<vector<string>> res;
    pair<bool, vector<vector<int>>> checkAndMark(vector<vector<int>> takenMap, int x, int y) {
        if (takenMap[x][y]) return {false, {{}}};
        int n = takenMap.size();
        // mark the horizontal cells
        for (int i = 0; i<n; i++) takenMap[x][i] = 1;

        // mark the verical cell
        for (int j = 0; j<n; j++) takenMap[j][y] = 1;

        // mark diagonal left-up
        int tmp_x = x, tmp_y = y;
        while(tmp_x >= 0 && tmp_y >= 0) {
            takenMap[tmp_x][tmp_y] = 1;
            tmp_x--;
            tmp_y--;
        }

        // mark diagonal right-up
        tmp_x = x;
        tmp_y = y;
        while(tmp_x>=0 && tmp_y<n) {
            takenMap[tmp_x][tmp_y] = 1;
            tmp_x--;
            tmp_y++;
        }

        // mark diagonal left-down
        tmp_x = x;
        tmp_y = y;
        while(tmp_x<n && tmp_y>=0) {
            takenMap[tmp_x][tmp_y] = 1;
            tmp_x++;
            tmp_y--;
        }

        // mark diagonal right-down
        tmp_x = x;
        tmp_y = y;
        while(tmp_x<n && tmp_y<n) {
            takenMap[tmp_x][tmp_y] = 1;
            tmp_x++;
            tmp_y++;
        }

        return {true, takenMap};
    }

public:
    void backtrack(int idx, int n, vector<vector<int>> taken, vector<string> &curr) {
        if (idx >= n) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i<n; i++) {
            pair<bool, vector<vector<int>>> tmp = checkAndMark(taken, idx, i);
            if (tmp.first) {
                string curr_string(n, '.');
                curr_string[i] = 'Q';
                curr.push_back(curr_string);
                backtrack(idx+1, n, tmp.second, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> taken(n, vector<int>(n, 0));
        vector<string> curr;
        backtrack(0, n, taken, curr);
        return res;
    }
};
