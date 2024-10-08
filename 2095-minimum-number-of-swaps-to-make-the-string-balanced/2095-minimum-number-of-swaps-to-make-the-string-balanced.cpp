class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int cnt = 0;
        int n = s.size();
        for(int i=0; i < n; i++)
        {
            char ch = s[i];
            if(ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                    st.pop();
                else
                    cnt++;
            }
        }
        return (cnt + 1)/2;
    }
};