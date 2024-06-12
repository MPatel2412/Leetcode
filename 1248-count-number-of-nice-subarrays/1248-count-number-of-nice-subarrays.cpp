class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =  0; i < n ;i++)
        {
            cnt += nums[i]&1;
            if(cnt == k)
            {
                ans++;
            }
            int rem = cnt - k;
            if(mp.find(rem)!=mp.end())
            {
                ans += mp[rem];
            }
            
            mp[cnt]++;
        }
        return ans;
    }
};