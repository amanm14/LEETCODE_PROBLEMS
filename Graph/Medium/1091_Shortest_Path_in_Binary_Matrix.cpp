class Solution {
public://O(n^2) is tc and sc
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));

        ans[0][0] = 1;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return d;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {

                    if (i == 0 && j == 0)
                        continue;

                    int nr = r + i;
                    int nc = c + j;

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 0 &&
                        ans[nr][nc] > d + 1) {

                        ans[nr][nc] = d + 1;
                        q.push({d + 1, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};
