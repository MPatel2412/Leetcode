class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        set<string> st;
        for(auto it : dictionary)
        {
            st.insert(it);
        }
        
        int n = sentence.size();
        string temp;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            char ch = sentence[i];
            if(ch==' ')
            {
                flag = 0;
                for(int j=0;j<temp.size();j++)
                {
                    string r = temp.substr(0,j+1);
                    if(st.find(r) != st.end())
                    {
                        ans += r + " ";
                        flag = 1;
                        break;
                    }
                }
                
                if(!flag)
                    ans+=temp + " ";
                temp="";
            }
            else
            {
                temp+=ch;
            }
        }
        flag = 0;
        for(int j=0;j<temp.size();j++)
                {
                    string r = temp.substr(0,j+1);
                    if(st.find(r) != st.end())
                    {
                        ans += r;
                        flag = 1;
                        break;
                    }
                }
        if(!flag)
            ans+=temp;
        return ans;
    }
};