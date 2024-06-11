class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(auto it : arr1)
            mpp[it]++;
        
        vector<int> ans;
        for(int i=0;i < arr2.size(); i++)
        {
            while(mpp[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                mpp[arr2[i]]--;
            }
        }
        for(auto x : mpp)
        {
            if(x.second > 0)
            {
                while(x.second > 0)
                {
                    ans.push_back(x.first);
                    x.second--;
                }
            }
        }
        return ans;
    }
};