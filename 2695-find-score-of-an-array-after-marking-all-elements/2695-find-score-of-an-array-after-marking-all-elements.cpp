class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0; i < n; i++)
        {
            int num = nums[i];
            pq.push({num,i});
        }
        long long score = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            if(vis[it.second] == 1)
            {
                continue;
            }

            score = score + it.first;

            vis[it.second] = 1;
            if(it.second > 0)
            {
                vis[it.second - 1] = 1;
            }
            if(it.second < n-1)
            {
                vis[it.second + 1] = 1;
            }
        }

        return score;
    }
};