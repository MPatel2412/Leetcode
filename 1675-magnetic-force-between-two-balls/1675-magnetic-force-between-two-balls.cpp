class Solution {
public:
    bool check(int mid,vector<int>& position, int m)
    {
        int cnt = 1;
        int n = position.size();
        int last = position[0];
        for(int i=1;i<n;i++)
        {
            if(position[i] - last >= mid)
            {
                cnt++;
                last = position[i];
            }
            if(cnt >= m)
                return true;
        }
        if(cnt >= m)
            return true;
        
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        long long l = 1, r= position[n-1] - position[0];
        
        while(l <= r)
        {
            long long mid = l + (r-l)/2;
            if(check(mid,position,m))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};