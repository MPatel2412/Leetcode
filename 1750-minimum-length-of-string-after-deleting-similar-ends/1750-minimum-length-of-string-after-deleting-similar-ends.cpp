class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n==1)
            return 1;
        int l = 0, r = n-1;
        while(l < r && s[l]==s[r])
        {
            char temp = s[l];
            while(l <= r && s[l]==temp)
            {
                l++;
            }

            while(r > l && s[r] == temp)
            {
                r--;
            }
        }
        return r-l+1;
    }
};