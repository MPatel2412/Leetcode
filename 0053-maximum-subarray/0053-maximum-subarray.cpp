class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        if(n==1)
        {
            return nums[0];
        }
        int temp=INT_MIN;
        int count=0;
        for(int k=0;k<n;k++)
        {
            temp=max(temp,nums[k]);
            if(nums[k]<=0)
                count++;
        }
        if(count==n)
        {
            return temp;
        }
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>0)
                ans=max(ans,sum);
            if(sum<=0)
                sum=0;
        }
        return ans;
    }
};