class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i=0; i < n; i++)
        {
            pre[i] = cnt_b;
            if(s[i] == 'a')
                cnt_a++;
            else
                cnt_b++;
        }
        cnt_a = 0, cnt_b = 0;
        for(int i=n-1;i >=0; i--)
        {
            suff[i] = cnt_a;
            if(s[i] == 'a')
                cnt_a++;
            else
                cnt_b++;
        }
        int min_deletions = n;
        for (int i = 0; i < n; i++) {
            min_deletions = min(min_deletions, pre[i] + suff[i]);
        }

        return min_deletions;
    }
};