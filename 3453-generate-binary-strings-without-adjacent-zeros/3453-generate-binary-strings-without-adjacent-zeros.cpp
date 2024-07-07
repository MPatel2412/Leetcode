class Solution {
public:
    void f(int n,vector<string> &ans,string temp,int flag)
    {
        //base case
        if(n == 0)
        {
            ans.push_back(temp);
            return ;
        }
        if(flag == -1 || flag == 1)
        {
            temp.push_back('0');
            f(n-1,ans,temp,0);
            temp.pop_back();
        }
        temp.push_back('1');
        f(n-1,ans,temp,1);
        temp.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp="";
        
        f(n,ans,temp,-1);
        return ans;
    }
};