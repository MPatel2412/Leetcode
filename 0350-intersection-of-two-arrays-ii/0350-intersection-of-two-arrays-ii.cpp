class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        for(auto it : nums1)
        {
            ump[it]++;
        }
        vector<int> ans;
        for(auto x : nums2)
        {
            if(ump.find(x) != ump.end())
            {
                ump[x]--;
                if(ump[x] <= 0)
                    ump.erase(x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};