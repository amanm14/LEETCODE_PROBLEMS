class Solution {
public://O(n*m) is tc and sc
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vis[i][j]) continue;

                queue<vector<int>> q;
                q.push({i, j, -1, -1});
                vis[i][j] = true;

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    int row = curr[0];
                    int col = curr[1];
                    int parentRow = curr[2];
                    int parentCol = curr[3];

                    for (int k = 0; k < 4; k++) {
                        int nr = row + dr[k];
                        int nc = col + dc[k];

                        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                            continue;

                        if (grid[nr][nc] != grid[row][col])
                            continue;

                        if (nr == parentRow && nc == parentCol)
                            continue;

                        if (vis[nr][nc])
                            return true;

                        vis[nr][nc] = true;
                        q.push({nr, nc, row, col});
                    }
                }
            }
        }

        return false;
    }
};
