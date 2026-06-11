class Solution {
public://O(M*N) is tc and sc I solve took help from gpt at lst 
    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        int m = board.size();
        int n = board[0].size();

        vis[i][j] = 1;

        int delr[] = {0, 1, 0, -1};
        int delc[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + delr[k];
            int nc = j + delc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                vis[nr][nc] == 0 &&
                board[nr][nc] == 'O') {

                dfs(nr, nc, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Left and Right boundaries
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);

            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                dfs(i, n - 1, board, vis);
        }

        // Top and Bottom boundaries
        for (int j = 0; j < n; j++) {

            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);

            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                dfs(m - 1, j, board, vis);
        }

        // Convert surrounded O's to X
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
