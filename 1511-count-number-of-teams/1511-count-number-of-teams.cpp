class Solution {
public:
    int dp[1002][1002][4];
    int solve(int idx, int val, int k, vector<int>& rating){
        if(k==3) return 1;
        if(idx<0){
            if(k==3) return 1;
            return 0;
        }
        if(val!=-1 && dp[idx][val][k]!=-1) return dp[idx][val][k];
        int nontaken = solve(idx-1, val, k, rating);
        int taken=0;
        if(val==-1 || rating[idx]>rating[val]){
            taken = solve(idx-1, idx, k+1, rating);
        }
        if(val!=-1){
            dp[idx][val][k] = taken + nontaken;
        }
        return taken+nontaken;
    }
    int numTeams(vector<int>& rating) {
        int ans =0, n = rating.size();
        memset(dp, -1, sizeof(dp));
        ans += solve(n-1, -1, 0, rating);
        reverse(rating.begin(), rating.end());
        memset(dp, -1, sizeof(dp));
        ans += solve(n-1, -1, 0, rating);
        return ans;
    }
};