class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for(int j = 0; j<m; j++)
            dp[n-1][j] = matrix[n-1][j];

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<m; j++){

                for(int y = -1; y<=1; y++){
                    if(j+y >= 0 && j+y < m)
                        dp[i][j] = min(dp[i][j], dp[i+1][j+y]);
                }

                dp[i][j] += matrix[i][j];
            }
        }

        for(int j = 0; j<m; j++)
            minSum = min(minSum, dp[0][j]);

        return minSum;
    }
};