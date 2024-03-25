class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto x : mp)
        {
            if(x.second==2)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};