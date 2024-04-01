class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int index = n - 1;
        while(index >= 0 && s[index]==' ')
        {
            index = index - 1;
        }
        int ans = 0;
        while(index >= 0 && s[index]!=' ')
        {
            ans++;
            index--;
        }
        return ans;
    }
};