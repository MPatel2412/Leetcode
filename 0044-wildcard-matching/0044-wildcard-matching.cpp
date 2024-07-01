class Solution {
public:
    bool f(string pattern,string text,int i,int j,vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return true;
        if(i < 0 && j>=0)
            return false;
        if(j < 0 && i >= 0)
        {
            for(int k = 0; k <= i; k++)
                if(pattern[k] != '*')   return false;
            
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(pattern[i] == text[j] || pattern[i] =='?')
        {
            return dp[i][j] = f(pattern,text,i-1,j-1,dp);
        }
        if(pattern[i] == '*')
        {
            return dp[i][j] = f(pattern,text,i-1,j,dp) | f(pattern,text,i,j-1,dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size();
        int m = text.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0]= true;
        for(int i = 1; i <=m;i++)
        {
            dp[0][i] = false;
        }
        for(int i=1; i<= n ;i++)
        {
            bool flag = true;
            for(int k=1; k<= i;k++)
            {   
                if(pattern[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag; 
        }

        for(int i=1; i <= n; i++)
        {
            for(int j=1 ; j <= m ; j++)
            {
                if(pattern[i-1] == text[j-1] || pattern[i-1] =='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
        // return f(p,s,n-1,m-1,dp);
    }
};