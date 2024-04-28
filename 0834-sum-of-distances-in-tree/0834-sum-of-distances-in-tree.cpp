class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> res;
    
    void dfs1(int node, int parent)
    {
        for(auto x : graph[node])
        {
            if(x==parent)
                continue;
            
            dfs1(x,node);
            count[node] += count[x];
            res[node] += res[x] + count[x];
        }
    }
    
    void dfs2(int node,int parent)
    {
        for (int child : graph[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        count.resize(n,1);
        res.resize(n,0);
        
        dfs1(0,-1);
        dfs2(0,-1);
        
        return res;
    }
    
};