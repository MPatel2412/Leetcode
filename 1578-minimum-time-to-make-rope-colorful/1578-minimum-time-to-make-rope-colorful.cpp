class Solution {
public:
    int f(string &colors,vector<int> &time,int index,char prev,int prevTime,vector<int> &dp)
    {
        //base condition
        if(index<0)
        {
            return 0;
        }
        if(dp[index] != -1)
            return dp[index];
        if(colors[index] == prev)
        {
            return f(colors,time,index-1,prev,max(prevTime,time[index]),dp) + min(prevTime,time[index]);
        }
        else
        {
            return f(colors,time,index-1,colors[index],time[index],dp);
        }
    }
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n,-1);
        return f(colors,neededTime,n-1,'A',neededTime[n-1],dp);
    }
};