class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        vis[r][c] = 1; 

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && vis[nr][nc] == 0) {
                dfs(nr, nc, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; 
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));  

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O' && vis[i][j] == 0) {
                    dfs(i, j, board, vis);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};