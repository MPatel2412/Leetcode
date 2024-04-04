class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                if(ans < cnt)
                {
                    ans = cnt;
                }
            }
            else if(s[i]==')')
            {
                cnt--;
                if(cnt<=0)
                {
                    cnt=0;
                }
            }
        }
        return ans;
    }
};