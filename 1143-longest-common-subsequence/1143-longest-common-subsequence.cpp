class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        //base condition
        if(i >= s1.size() || j >= s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take1 = 0;
        if(s1[i] == s2[j])
        {
            take1 = 1 + solve(i+1,j+1,s1,s2,dp);
        }
        int take2 = solve(i,j+1,s1,s2,dp);
        int take3 = solve(i+1,j,s1,s2,dp);
        
        return dp[i][j] = max(take1,max(take2,take3));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2,dp);
    }
};