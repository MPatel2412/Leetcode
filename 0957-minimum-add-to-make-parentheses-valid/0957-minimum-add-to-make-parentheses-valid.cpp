class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> st;
        for(auto ch : s)
        {
            if(ch == ')')
            {
                if(st.empty())
                    cnt++;
                else
                    st.pop();
            }
            else 
            {
                st.push(ch);
            }
        }
        return cnt + st.size();
    }
};