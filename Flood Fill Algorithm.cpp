class Solution
{
public:
    void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &ans, int color)
    {
        int incolor = image[sr][sc];
        ans[sr][sc] = color;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + dr[i];
            int ncol = sc + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] != color && ans[nrow][ncol] == incolor)
            {
                dfs(nrow, ncol, image, ans, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, color);
        return ans;
    }
};