class Solution {
public:
    int checkWays(string &s,int index,vector<int> &dp)
    {
       if(index >= s.size())
       {
            return 1;
       }
       if(stoi(string(1,s[index]))==0) 
            return dp[index] = 0;
        if(dp[index] != -1)
            return dp[index];
        int takeOne=0,takeTwo=0;
        if(index + 1 < s.size())
        {
            if(stoi(s.substr(index,2)) <= 26)
            {
                takeTwo = checkWays(s,index+2,dp);
            }
        }
        takeOne = checkWays(s,index+1,dp);

        return dp[index] = takeOne + takeTwo;

    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return checkWays(s,0,dp);
    }
};