class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c1=0,c0=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                c0++;
            else
                c1++;
        }
        string ans ;
        ans.push_back('1');
        c1--;
        while(c0>0)
        {
            ans.push_back('0');
            c0--;
        }
        while(c1>0)
        {
            ans.push_back('1');
            c1--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};