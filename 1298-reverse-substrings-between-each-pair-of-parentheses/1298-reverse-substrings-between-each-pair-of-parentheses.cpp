class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<char> st;
        int n = s.size();
       
        for(int i=0; i < n ;i++)
        {
            char ch = s[i];
            if(ch == ')')
            {
                string temp="";
                while(!st.empty() && st.top() != '(')
                {
                    temp = temp + st.top();
                    st.pop();
                }
                //cout << temp << endl;
                st.pop();
                for(int index =0 ; index < temp.size(); index++)
                {
                    st.push(temp[index]);
                }
            }
            else
            {
                st.push(ch);
            }
        }
        while(!st.empty())
        {
            ans = st.top() + ans; 
            st.pop();
        }
        return ans;
    }
};