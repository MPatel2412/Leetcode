class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vis(nums.size()+1,0);
        for(int i = 0; i < nums.size() ; i++)
        {
            vis[nums[i]] += 1;
        }
        int rep = -1;
        int loss = -1;
        for(int i = 1; i < vis.size() ; i++)
        {
            if(vis[i]==0)
            {
                loss = i;
            }
            if(vis[i] == 2)
            {
                rep = i;
            }
        }
        return {rep,loss};
    }
};