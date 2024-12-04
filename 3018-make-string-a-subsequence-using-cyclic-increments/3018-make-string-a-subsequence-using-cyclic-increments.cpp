class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        //unordered_map<char,int> m;
        int cnt =0;
        int n = str1.size();
        int m = str2.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            char ch = str1[i];
            char next = (char)('a' + (ch-'a'+1)%26);
            if(next==str2[j] || ch ==str2[j])
            {
                cnt++;
                j++;
            }
            i++;
        }
        if(cnt==m)
            return true;
        return false;
    }
};