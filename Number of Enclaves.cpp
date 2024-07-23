

int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        int ro = q.front().first;
        int col = q.front().second;
        q.pop();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nr = ro + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1)
            {
                q.push({nr, nc});
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}
