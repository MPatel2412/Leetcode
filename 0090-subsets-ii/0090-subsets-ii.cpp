class Solution {
public:
    void func(vector<int> &nums,int n,int index, vector<int> ds,set<vector<int>> &st)
    {
        if(index==n)
        {
            sort(ds.begin(),ds.end());
            st.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        func(nums,n,index+1,ds,st);
        ds.pop_back();
        func(nums,n,index+1,ds,st);
    
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ds;
        int n = nums.size();
        func(nums,n,0,ds,st);
        
        vector<vector<int>> ans;
        for(auto it : st)
            ans.push_back(it);
        
        return ans;
        
    }
};