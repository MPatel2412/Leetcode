class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> freq;
        for(auto it : nums)
        {
            freq[it]++;
        }
        int cnt = 0;
        int maxi=INT_MIN;
        for(auto &x : freq)
        {
            if(x.second >= maxi)
            {
                maxi = x.second;
            }
        }
        for(auto &x : freq)
        {
            if(x.second==maxi)
            {
                cnt+=x.second;
            }
        }
        return cnt;
    }
};