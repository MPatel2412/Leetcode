class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string str = num;
        reverse(str.begin(),str.end());
        for(int i=0;i<n;i++)
        {
            char ch = str[i];
            int digit = ch - '0';
            if(digit%2==1)
            {
                string temp = str.substr(i,n-i);
                reverse(temp.begin(),temp.end());
                return temp;
            }
        }
        return "";
    }
};