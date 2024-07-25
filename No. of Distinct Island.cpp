class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &v, int ro, int col)
    {
        vis[r][c] = 1;
        int p = r - ro;
        int q = c - col;
        int n = grid.size();
        int m = grid[0].size();
        v.push_back({p, q});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid, vis, v, ro, col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, grid, vis, v, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};