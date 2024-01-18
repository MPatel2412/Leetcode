class Solution {
public:
    int solveBU(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        if(n==0) return dp[0];
        dp[1]=1;
        if(n==1) return dp[1];
        dp[2]=2;

        for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];

        return dp[n];
    }
public:
    int climbStairs(int n) {
       return solveBU(n);
    }
};