class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i=1; i <= n; i++)
        {
            pre[i] = pre[i-1] ^ arr[i-1];
        } 
        vector<int> ans;
        for(auto q : queries)
        {
            int start = q[0];
            int end = q[1];
            ans.push_back(pre[end+1]^pre[start]);
        }
        return ans;
    }
};