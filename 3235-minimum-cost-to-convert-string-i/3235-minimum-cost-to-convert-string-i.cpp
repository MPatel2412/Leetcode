class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26,vector<long long>(26,INT_MAX));
        int n = original.size();
        for(int i=0; i < 26; i++)
            adj[i][i] = 0;
        for(int i=0; i < n; i++)
        {
            adj[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i],adj[original[i] - 'a'][changed[i] - 'a']);
        }
        
        for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) 
            {
                if(adj[i][k] < INT_MAX)
                {
                    for (int j = 0; j < 26; j++) 
                    {
                        if(adj[k][j] < INT_MAX) 
                        {
                            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                        }
				    }
                }
			}
		}
        long long ans = 0;
        for(int i=0; i < source.size(); i++)
        {
            char u = source[i];
            char v = target[i];
            if(adj[u-'a'][v-'a'] != INT_MAX)
                ans += (adj[u-'a'][v-'a']);
            else
                return -1;
        }
        return ans;
    }
};