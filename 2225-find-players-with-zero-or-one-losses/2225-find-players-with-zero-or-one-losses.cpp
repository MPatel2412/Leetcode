class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loss;
        for(int i=0;i<matches.size();i++)
        {
            if(loss.find(matches[i][1]) == loss.end())
            {
                loss[matches[i][1]] = 1;
            }   
            else 
                loss[matches[i][1]]++;

        }
        vector<vector<int>> ans(2);
        for(int i=0;i<matches.size();i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if(loss.find(winner) == loss.end())
            {
                ans[0].push_back(winner);
                loss[winner]=2;
            }
            if(loss[loser]==1)
            {
                ans[1].push_back(loser);
            }
        }
        sort(ans[1].begin(),ans[1].end());
        sort(ans[0].begin(),ans[0].end());
        return ans;
    }
};