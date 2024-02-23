class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,1e9);
        queue<pair<int,int>> pq;
        pq.push({src,0});
        int stops=0;
        while(stops<=k && !pq.empty())
        {
            int len = pq.size();
            while(len--){
                int node = pq.front().first;
                int amount = pq.front().second;
                pq.pop();
                for(auto it : adj[node])
                {
                    int temp = it.first;
                    int wt = it.second;
                    if(wt + amount < dis[temp])
                    {
                        dis[temp] = wt + amount;
                        pq.push({temp,dis[temp]});
                    }
                }
            }
            stops++;
        }
        if(dis[dst]==1e9)
            return -1;
        return dis[dst];
    }
};