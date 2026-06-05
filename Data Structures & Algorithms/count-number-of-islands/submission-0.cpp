class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<int>> taken(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1' && !taken[i][j]) {
                    ans++;
                    queue<pair<int, int>> bfs;
                    bfs.push({i,j});
                    while(!q.empty()) {
                        pair<int, int> tmp = bfs.pop();
                        taken[tmp.first, tmp.second] = 1;
                        if ()
                    }
                }
            }
        }
    }
};
