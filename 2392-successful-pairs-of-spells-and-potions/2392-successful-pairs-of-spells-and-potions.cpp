class Solution {
public:
    int bs_potions(vector<int>& potions, long long spell, long long success)
    {
        long long val = 1;
        int l = 0, r = potions.size() - 1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r)/2;
            val = (long long)(spell * potions[mid]);
            if(val >= success)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(ans == -1)
            return 0;

        return (potions.size() - ans ); 
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int> ans(n,0);
        for(int i=0; i < n; i++)
        {
            int spell = spells[i];
            ans[i] = bs_potions(potions,spell,success);
        }
        return ans;
    }
};