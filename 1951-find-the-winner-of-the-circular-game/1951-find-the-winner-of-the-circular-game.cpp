class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vis(n,0);
        int start = 0;
        int cnt = n;
        while(cnt > 1)
        {
            int index = start;
            int jumps = 0;
            while(jumps < k-1)
            {
                index = index%n;
                if(!vis[index])
                {
                    jumps++;
                }
                index++;
            }
            while(vis[index%n])
            {
                index++;
            }
            vis[index%n] = 1;
            start = (index+1)%n;
            cnt--;
        }
        int i;
        for(i=0;i < n;i++)
        {
            if(vis[i] == 0)
                break;
        }
        return i+1;
    }
};