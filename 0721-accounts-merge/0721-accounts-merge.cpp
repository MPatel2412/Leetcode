class DisjointSet{
    public:
        vector<int> size,parent;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
        {
            parent[i] = i;
        }
    }
    int uParent(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = uParent(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int x = uParent(u);
        int y = uParent(v);
        
        if(x == y)  return;
        if(size[x] > size[y])
        {
            parent[y] = x;
            size[x] += size[y];
        }
        else
        {
            parent[x] = y;
            size[y] += size[x];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<arr[i].size();j++)
            {
                if(mp.find(arr[i][j]) != mp.end())
                {
                    ds.unionBySize(i,mp[arr[i][j]]);
                }
                else{
                    mp[arr[i][j]] = i;
                }
            }
        }
        unordered_map<int,vector<string>> components;
        for(auto it : mp)
        {
            string email = it.first;
            int group = it.second;
            components[ds.uParent(group)].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto x : components)
        {
            int group = x.first;
            vector<string> comp = {arr[group][0]};
            comp.insert(comp.end(), x.second.begin(), 
                             x.second.end());
            sort(comp.begin() + 1, comp.end());
            ans.push_back(comp);
        }
        return ans;
    }
};