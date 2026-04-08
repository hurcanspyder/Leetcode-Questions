class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n, m;
    vector<int> sz;
    vector<vector<bool>> visited;


    bool checker(int x, int y, vector<vector<int>>& grid) {
        return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !visited[x][y]);
    }

    void dfs(int x, int y, int compo, vector<vector<int>>& grid) {
        sz[compo]++;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (checker(nx, ny, grid)) {
                dfs(nx, ny, compo, grid);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int max_ans = 0;


        vector<pair<int, int>> zeroes;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) zeroes.push_back({i, j});
            }
        }


        if (zeroes.empty()) return n * m;


        for (auto& p : zeroes) {
            grid[p.first][p.second] = 1; 
            

            int compo = 0;
            sz.assign(n * m + 1, 0); 
            visited.assign(n, vector<bool>(m, false));

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        dfs(i, j, compo, grid);
                        max_ans = max(max_ans, sz[compo]);
                        compo++;
                    }
                }
            }
            grid[p.first][p.second] = 0; 
        }

        return max_ans;
    }
};