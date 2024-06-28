class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> adj[n];
        for(auto road : roads)
        {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        priority_queue<pair<long long,long long>> pq;
        for(long long i=0;i<n;i++)
        {
            pq.push({adj[i].size(),i});
        }
        long long index = n;
        vector<int> graph(n);
        while(!pq.empty())
        {
            long long node = pq.top().second;
            graph[node] = index;
            index--;
            pq.pop();
        }
        vector<long long> vis(n,0);
        long long ans =0 ;
        for(int i=0;i<n;i++)
        {
            vis[i] = 1;
            for(auto node : adj[i])
            {
                if(!vis[node])
                    ans += (graph[i] + graph[node]);   
            }
        }
        return ans;
    }
};