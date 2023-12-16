class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26]={0};
        int l=s.size();
        for(int i=0;i<l;i++)
        {
            count[s[i]-'a']++;
        }
        l=t.size();
        for(int i=0;i<l;i++)
        {
            count[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            return false;
        }
        return true;
    }
};