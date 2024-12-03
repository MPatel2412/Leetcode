class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int n = s.size();
        string ans(n + spaces.size(),' ');
        int index = 0;
        for(int i=0; i < n ; i++)
        {
            if(index < spaces.size() && i == spaces[index])
            {
                ans[i+index] = ' ';
                index++;
            }
            ans[i+index] = s[i];
        }
        return ans;
    }
};