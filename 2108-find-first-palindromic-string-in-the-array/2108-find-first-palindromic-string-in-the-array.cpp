class Solution {
public:
    bool checkPali(string s)
    {
        int l = 0,r=s.size()-1;
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            if(checkPali(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};