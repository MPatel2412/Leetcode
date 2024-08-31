class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> graph[n];
        for(int i=0;i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back({v,succProb[i]});
            graph[v].push_back({u,succProb[i]});
        }
        vector<double> maxProb(n,0);
        maxProb[start] = 1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it : graph[node])
            {
                int u = it.first;
                double prob = it.second;

                if(maxProb[node] * prob > maxProb[u])
                {
                    maxProb[u] = maxProb[node] * prob;
                    q.push(u);
                }
            }
        }
        return maxProb[end];
    }
};