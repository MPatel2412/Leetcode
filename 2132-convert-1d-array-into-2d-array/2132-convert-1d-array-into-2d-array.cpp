class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();

        if(m*n != len)
            return {};
        int index = 0;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0; i < m; i++)
        {
            for(int j=0;j < n;j++)
            {
                ans[i][j] = original[index++];
            }
        }
        return ans;
    }
};