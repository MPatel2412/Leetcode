class Solution {
public:
    int solve(vector<int> &nums,int index,int n,vector<int> &dp)
    {
        //base condition
        if(index>=n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int take=0,notTake = 0;
        take = nums[index] + solve(nums,index+2,n,dp);
        notTake = solve(nums,index+1,n,dp);
        
        return dp[index] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return max(solve(nums,1,n,dp),solve(nums,0,n,dp));
    }
};