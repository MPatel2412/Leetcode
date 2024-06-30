class DisjointSet{
    public:
    vector<int> parent,size;
    int components;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
        components = n;
    }
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)
            return false;
        if(size[pu] > size[pv])
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        components--;
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        int cnt = 0;
        for(auto it : edges)
        {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if(wt == 3)
            {
                if(alice.unionBySize(u,v) | bob.unionBySize(u,v))
                {
                    cnt++;
                }
            }
        }
        for(auto it : edges)
        {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if(wt == 1)
            {
                if(alice.unionBySize(u,v))
                {
                    cnt++;
                }
            }
            else if(wt == 2)
            {
                if(bob.unionBySize(u,v))
                    cnt++;
            }
        }
        if(alice.components == 1 && bob.components == 1)
            return edges.size() - cnt;

        return -1;
    }
};
