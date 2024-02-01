class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i < n;i+=3)
        {
            vector<int> temp;
            for(int j=i; j < i+3;j++)
            {
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        for(auto it : ans)
        {
            if(it[2] - it[0] > k)
            {
                return {};
            }
        }
        return ans;
    }
};