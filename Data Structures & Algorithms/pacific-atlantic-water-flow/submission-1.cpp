class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false)), atlantic(rows, vector<bool>(cols, false)), visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> bfs;
        for (int i = 0; i<rows; i++) {
            pacific[i][0] = true;
            visited[i][0] = true;
            bfs.push({i, 0});
        }
        for (int i = 0; i<cols; i++) {
            pacific[0][i] = true;
            visited[0][i] = true;
            bfs.push({0, i});
        }

        // For pacific
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            if (x+1 < rows && !visited[x+1][y] && heights[x][y] <= heights[x+1][y]) {
                pacific[x+1][y] = true;
                visited[x+1][y] = true;
                bfs.push({x+1, y});
            }

            if (y+1 < cols && !visited[x][y+1] && heights[x][y] <= heights[x][y+1]) {
                pacific[x][y+1] = true;
                visited[x][y+1] = true;
                bfs.push({x, y+1});
            }
        }

        fill(visited.begin(), visited.end(), vector<bool>(cols, false));

        for (int i = 0; i<rows; i++) {
            atlantic[i][cols-1] = true;
            visited[i][cols-1] = true;
            bfs.push({i, cols-1});
        }
        for (int i = 0; i<cols; i++) {
            atlantic[rows-1][i] = true;
            visited[rows-1][i] = true;
            bfs.push({rows-1, i});
        }

        // For atlantic
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            if (x-1 >= 0 && !visited[x-1][y] && heights[x][y] <= heights[x-1][y]) {
                atlantic[x-1][y] = true;
                visited[x-1][y] = true;
                bfs.push({x-1, y});
            }

            if (y-1 >= 0 && !visited[x][y-1] && heights[x][y] <= heights[x][y-1]) {
                atlantic[x][y-1] = true;
                visited[x][y-1] = true;
                bfs.push({x, y-1});
            }
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j<cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};
