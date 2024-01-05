class Solution {
// public:
//     int _calculate(vector<int> &nums,int index,int prev,vector<vector<int>> &dp)
//     {   
//         //base condition
//         if(index==nums.size())
//             return 0;
//         if(dp[index][prev+1]!=-1)
//             return dp[index][prev+1];
//         int take=_calculate(nums,index+1,prev,dp);
//         if(prev==-1 || nums[index] > nums[prev])
//         {
//             take =max(take, 1 + _calculate(nums,index+1,index,dp));
//         } 
//         return dp[index][prev+1] = take;
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return _calculate(nums,0,-1,dp);
        //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // vector<int> curr(n+1,0), pre(n+1,0);
        // for(int index=n-1;index>=0;index--)
        // {
        //     for(int prev=index-1;prev>=-1;prev--)
        //     {
        //         int len = curr[prev + 1];
        //         if(prev==-1 || nums[index] > nums[prev])
        //         {
        //             len = max(len,1+curr[index+1]);
        //         }
        //         pre[prev+1] = len;
        //     }
        //     curr=pre;
        // }
        //return curr[0];
        int maxi=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i] > nums[prev])
                {
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }

};