class Solution {
public:
    int _calculate(vector<int> &prices,int ind,int buy,int count,vector<vector<vector<int>>> &dp)
    {   
        if(count==0)
            return 0;
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy][count]!=-1)
            return dp[ind][buy][count];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[ind] + _calculate(prices,ind+1,0,count,dp),_calculate(prices,ind+1,1,count,dp));
        }
        else
        {
            profit=max(prices[ind] + _calculate(prices,ind+1,1,count-1,dp),_calculate(prices,ind+1,0,count,dp));
        }
        return dp[ind][buy][count]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int> >(2, vector<int>(k+1, -1)));
        return _calculate(prices,0,1,k,dp);
    }
};