class Solution {
public:

    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
          int n = grid.size();
          int m = grid[0].size();
          queue<pair<int,int>>q;
          q.push({row,col});
          vis[row][col]=1;
          while(!q.empty())
          {
            int new_row = q.front().first;
            int new_col = q.front().second;
            q.pop();
            for(int i =-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow = new_row+i;
                    int ncol = new_col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0)
                    {
                      vis[nrow][ncol]=1;
                      q.push({nrow,ncol});
                    }
                    
                }
            }
          }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    bfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};