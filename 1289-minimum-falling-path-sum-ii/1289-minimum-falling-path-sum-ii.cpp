class Solution {
public:
    int f(vector<vector<int>>& grid, int index, int prev,vector<vector<int>> &dp)
    {
        //base condition
        if(index>= grid.size())
        {
            return 0;
        }
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        int ans = 1e6;
        for(int i=0;i<grid.size();i++)
        {
            int take = 1e6;
            if(prev!=i || prev==-1)
            {
                take = grid[index][i] + f(grid,index+1,i,dp);
            }
            ans = min(ans, take);
        }
        return dp[index][prev+1] = ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(grid,0,-1,dp);
    }
};