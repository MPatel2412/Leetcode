class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        unordered_map<char,int> ump;
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(ump.find(s[i])!=ump.end())
                ans = max(ans, i - ump[s[i]]-1);
            else
                ump[s[i]] = i;
        }
        return ans;
    }
};