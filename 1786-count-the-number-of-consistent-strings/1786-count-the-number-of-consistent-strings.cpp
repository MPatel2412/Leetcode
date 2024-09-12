class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for(auto it : allowed)
            st.insert(it);

        int cnt = 0;
        for(int i=0; i < words.size(); i++)
        {
            string s = words[i];
            bool flag = true;
            for(auto ch : s)
            {
                if(st.find(ch) == st.end())
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};