class Solution {
private:
    int r, c;
    vector<int> dy = {-1, 0, 1};
public:
    bool isInside(int y) {
        return (y >= 0 && y < c);
    }

    int f(int x, int y1, int y2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(x >= r || !isInside(y1) || !isInside(y2)) return 0;
        int &mxScore = dp[x][y1][y2];
        if(mxScore != -1) return mxScore;
        mxScore = 0;
        int currScore = (y1 == y2 ? grid[x][y1] : grid[x][y1] + grid[x][y2]);
        for(int i = 0; i < 3; i++) {
            int curry1 = y1 + dy[i];
            for(int j = 0; j < 3; j++) {
                int curry2 = y2 + dy[j];
                mxScore = max(mxScore, currScore + f(x + 1, curry1, curry2, grid, dp));
            }
        }
        return mxScore;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return f(0, 0, c - 1, grid, dp);
    }
};