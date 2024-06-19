class Solution {
public:
    bool checkDays(vector<int> &nums,int m,int k,int mid)
    {
        int cnt =0,num=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= mid)  cnt++;
            else
            {
                num+=cnt/k;
                cnt=0;
            }
        }
        num+=cnt/k;
        return num >= m;
    }
public:
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        long long val = m * 1ll * k * 1ll;
        if(val>n) return -1;
        int max_days=INT_MAX,min_days=INT_MAX;
        for(int i=0;i<n;i++)
        {
            max_days = max(max_days,b[i]);
            min_days = min(min_days,b[i]);
        }
        int l=min_days,r=max_days;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(checkDays(b,m,k,mid))
            {
                r=mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};