class Solution {
public:
int mod = 1e9 + 7;
    int f(int n,int index,int k,int target,vector<vector<int>> &dp)
    {
        //base condition
        if(index==n)
        {
            if(target == 0)
            {
                return 1;
            }
            return 0;
        }
        if(target < 0)
            return 0;

        if(dp[index][target]!=-1)
            return dp[index][target];
            
        int ways = 0;
        for(int i=1;i<=k;i++)
        {
            ways = (ways + f(n,index+1,k,target - i,dp))%mod;
        }
        return dp[index][target] = ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return f(n,0,k,target,dp);
    }
};