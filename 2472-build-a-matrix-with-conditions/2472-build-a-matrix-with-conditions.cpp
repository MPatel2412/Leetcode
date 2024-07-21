class Solution {
public:
    vector<int> topoSort(vector<vector<int>> &graph,int k)
    {
        vector<int> inDegree(k+1,0);
        for(int i=1; i <= k; i++)
        {
            for(auto it : graph[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=1; i <=k;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
            cnt++;
			topo.push_back(node);

			for (auto it : graph[node]) 
            {
				inDegree[it]--;
				if (inDegree[it] == 0) 
                    q.push(it);
			}
		}
        if(cnt != k) return {};
		return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));

        vector<vector<int>> row(k+1);
        vector<vector<int>> col(k+1);
        for(auto it : rowConditions)
        {
            row[it[0]].push_back(it[1]);
        }
        for(auto it : colConditions)
        {
            col[it[0]].push_back(it[1]);
        }
        vector<int> rowOrder = topoSort(row,k);
        vector<int> colOrder = topoSort(col,k);

        if(rowOrder.empty() || colOrder.empty()){
            return {};
        }
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rowOrder[i] == colOrder[j]) {
                    ans[i][j] = rowOrder[i];
                }
            }
        }
        return ans;

    }
};