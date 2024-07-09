class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long mini = INT_MAX;
        int n = nums.size();
        vector<long long> pre(n,0);
        vector<long> suff(n,0);
        pre[0] = nums[0];
        for(int i=1; i < n; i++)
        {
            pre[i] = pre[i-1] + nums[i];
        } 
        suff[n-1] = 0;
        for(int i=n-2; i >=0 ;i--)
        {
            suff[i] = suff[i+1] + nums[i+1];
        }

        int ans = -1;
        for(int i=0; i < n ; i++)
        {
            long long f_avg = pre[i]/(i+1);
            long long s_avg = 0;
            if(i != n-1)
                s_avg = suff[i]/(n-i-1);
                
            if(abs(f_avg - s_avg) < mini)
            {
                mini = abs(f_avg - s_avg);
                ans = i; 
            }
        }
        return ans;
    }
};