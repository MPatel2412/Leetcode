class Solution {
public:
    int func(int mid,vector<int> &nums)
    {
        int n = nums.size();
        int ans = 1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                ans++;
            }
        }
        return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0,maxi = INT_MIN;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxi = max(maxi,nums[i]);
        }
        
        int low = maxi, high = sum;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(func(mid,nums) > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};