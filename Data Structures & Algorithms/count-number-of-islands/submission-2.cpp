class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<int>> taken(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i<grid.size(); i++) {
            for (int j = 0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1' && !taken[i][j]) {
                    ans++;
                    queue<pair<int,int>> bfs;
                    bfs.push({i,j});
                    taken[i][j] = 1;

                    while (!bfs.empty()) {
                        auto [x, y] = bfs.front();
                        bfs.pop();

                        if (x-1 >= 0 && grid[x-1][y] == '1' && !taken[x-1][y]) {
                            taken[x-1][y] = 1;
                            bfs.push({x-1, y});
                        }

                        if (y-1 >= 0 && grid[x][y-1] == '1' && !taken[x][y-1]) {
                            taken[x][y-1] = 1;
                            bfs.push({x, y-1});
                        }

                        if (x+1 < grid.size() && grid[x+1][y] == '1' && !taken[x+1][y]) {
                            taken[x+1][y] = 1;
                            bfs.push({x+1, y});
                        }

                        if (y+1 < grid[0].size() && grid[x][y+1] == '1' && !taken[x][y+1]) {
                            taken[x][y+1] = 1;
                            bfs.push({x, y+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
