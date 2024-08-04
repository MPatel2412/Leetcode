class Solution {
string f(string s)
    {
        s += " ";
        int n = s.size();
        int cnt = 1;
        string ans = "";
        for(int i=0; i < n-1; i++){
            if(s[i+1] == s[i])
                cnt++;
            else
            {
                ans += ('0' + cnt);
                ans += s[i];
                cnt = 1;
            }
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string x=f(countAndSay(n-1));
        return x;
    }
};