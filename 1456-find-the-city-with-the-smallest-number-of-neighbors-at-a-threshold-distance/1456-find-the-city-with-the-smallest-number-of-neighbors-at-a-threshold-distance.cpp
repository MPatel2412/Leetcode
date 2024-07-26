class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n,vector<int>(n,1e9));
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            grid[u][v] = wt;
            grid[v][u] = wt;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    grid[i][j] = 0;
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        
        int cntCity = n;
        int cityNo = -1;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = i;
			}
        }
        return cityNo;
    }
};