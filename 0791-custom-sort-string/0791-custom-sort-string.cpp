class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        string ans;
        for(int i=0;i<order.size();i++)
        {
            while(freq[order[i]-'a']!=0)
            {
                ans.push_back(order[i]);
                freq[order[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++)
        {
            while((freq[i]--)!=0)
                ans.push_back((char)(i+'a'));
        }
        return ans;
    }
};