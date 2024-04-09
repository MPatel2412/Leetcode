class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i=0;i<tickets.size();i++)
        {
            q.push(i);
        }
        int time = 0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            time++;
            tickets[cur]--;
            if(cur == k && tickets[cur]==0)
            {
                return time;
            }
            if(tickets[cur] > 0)
            {
                q.push(cur);
            }
        }
        return time;
    }
};