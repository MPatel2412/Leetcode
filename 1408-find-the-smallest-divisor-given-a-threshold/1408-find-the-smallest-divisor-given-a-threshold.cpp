class Solution {
public:
    bool check(int mid, vector<int> &nums, int thres)
    {
        int sum = 0;
        for(auto it : nums)
        {
            sum += ceil(it*1.0/mid);
        }
        return sum <= thres;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = INT_MIN;
        for(auto it : nums)
            r = max(r,it);

        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(check(mid,nums,threshold))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};