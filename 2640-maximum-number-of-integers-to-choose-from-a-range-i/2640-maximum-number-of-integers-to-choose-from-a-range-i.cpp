class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st;
        for(auto it : banned)
        {
            st.insert(it);
        }
        
        int currSum = 0;
        int cnt = 0;
        for(int i=1; i <= n; i++)
        {
            if(st.count(i))
                continue;
            if(maxSum - i >= 0)
            {
                cnt++;
                maxSum -= i;
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};