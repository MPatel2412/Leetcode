class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt = 0;
        int operations = 0;
        for(int i=0; i < n; i++)
        {
            if(s[i] == '1')
                cnt++;
            else if(s[i] == '0' && cnt > 0)
            {
                int index = i;
                while(index < n && s[index] == '0')
                {
                    index++;
                }
                operations += cnt;
                i = index-1;
            }
            //else i++;
        }
        return operations;
    }
};