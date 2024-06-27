class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> graph[n+1];
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }
        for(int i=0;i<n+1;i++)
        {
            if(graph[i].size() == n)
                return i+1;
        }
        return -1;
    }
};