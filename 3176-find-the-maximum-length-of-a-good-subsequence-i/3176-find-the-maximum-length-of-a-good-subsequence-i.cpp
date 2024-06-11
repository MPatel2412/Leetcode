class Solution {
public:
    int dp[501][501][26];
    int f(vector<int> &nums,int index, int prev, int k)
    {
        //base condition
        if(index == nums.size())
        {
            return 0;
        }
        if(dp[index][prev + 1][k]!=-1)
            return dp[index][prev+1][k];
        
        int take = 0;
        if(prev == -1 || nums[index] == nums[prev])
        {
            take = max(take, 1 + f(nums,index+1,index,k));
            take = max(take,f(nums,index+1,prev,k));
        }
        else if(nums[index] != nums[prev])
        {
            if(k>0)
                take = max(take,1 + f(nums,index+1,index,k-1));
            
            take = max(take,f(nums,index+1,prev,k));
        }
        
        return dp[index][prev+1][k] = (take);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,0,-1,k);
        
    }
};