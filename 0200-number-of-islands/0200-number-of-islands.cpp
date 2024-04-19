class Solution {
public:
    int x[4] = {0,1,0,-1};
    int y[4] = {1,0,-1,0};
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int i,int j,int m,int n)
    {
        //base condition
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return ;
        }
        vis[i][j] = 1;
        for(int k=0;k<4;k++)
        {
            int newX = i + x[k];
            int newY = j + y[k];
            if(newX >= 0 && newY >= 0 && newX < m && newY < n && !vis[newX][newY] && grid[newX][newY]=='1')
                dfs(grid,vis,newX,newY,m,n);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
    }
};