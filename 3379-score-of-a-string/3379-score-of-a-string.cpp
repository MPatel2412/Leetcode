class Solution {
public:
    int scoreOfString(string s) {
        int curr = s[0];
        int val = 0;
        for(int i=1;i<s.size();i++)
        {
            val += abs(s[i] - curr);
            curr =  s[i];
        }
        return val;
    }
};