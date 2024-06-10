class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch=='(' || ch=='[' || ch=='{')
            {
                st.push(ch);
            }
            else
            {
                char temp;
                if(!st.empty())
                {
                    temp = st.top();
                    if((ch == ')' && temp=='(') || (ch == ']' && temp=='[') || (ch == '}' && temp=='{'))
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(st.empty()==true)
            return true;
        
        return false;
    }
};