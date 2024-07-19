class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mini(m,INT_MAX);
        vector<int> maxi(n,INT_MIN);
        for(int i=0; i < m;i++)
        {
            for(int j=0; j < n;j++)
            {
                mini[i] = min(mini[i],matrix[i][j]);
            }
        }
        for(int i=0; i < n;i++)
        {
            for(int j=0; j < m;j++)
            {
                maxi[i] = max(maxi[i],matrix[j][i]);
            }
        }
        vector<int> ans;

        for(int i=0; i < m;i++)
        {
            for(int j=0; j < n;j++)
            {
                if((matrix[i][j] == mini[i]) && (matrix[i][j] == maxi[j]))
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};