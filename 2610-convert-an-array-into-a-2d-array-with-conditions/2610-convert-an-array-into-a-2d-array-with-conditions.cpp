class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> taken(n,0);
        vector<vector<int>> ans;
        while(true)
        {
            vector<int> temp;
            bool changed = false;
            set<int> s;
            for(int i=0;i<n;i++)
            {
                if(!taken[i] && s.find(nums[i]) == s.end())
                {
                    changed = true;
                    temp.push_back(nums[i]);
                    s.insert(nums[i]);
                    taken[i]=1;
                }
            }
            if(!changed)
            {
                break;
            }
            else
            {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};