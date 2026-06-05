class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nrows = grid.size(), ncols = grid[0].size();
        vector<vector<int>> taken(nrows, vector<int>(ncols, 0));
        int max_area = 0; 
        for (int i = 0; i<nrows; i++) {
            for (int j = 0; j<ncols; j++) {
                if (grid[i][j] && !taken[i][j]) {
                    int curr_area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> tmp = q.front();
                        q.pop();
                        int x = tmp.first, y = tmp.second;
                        taken[x][y] = 1;
                        curr_area++;
                        if (x-1>=0 && grid[x-1][y] && !taken[x-1][y]) q.push({x-1, y});
                        if (y-1>=0 && grid[x][y-1] && !taken[x][y-1]) q.push({x, y-1});
                        if (x+1<nrows && grid[x+1][y] && !taken[x+1][y]) q.push({x+1, y});
                        if (y+1<ncols && grid[x][y+1] && !taken[x][y+1]) q.push({x, y+1});
                    }
                    cout<<"current area "<<curr_area<<endl;
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};
