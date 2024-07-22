class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> comb;
        for(int i=0; i < names.size(); i++)
        {
            comb.push_back({heights[i],names[i]});
        }
        sort(comb.rbegin(),comb.rend());
        vector<string> ans;
        for(int i=0;i < comb.size(); i++)
        {
            ans.push_back(comb[i].second);
        }
        return ans;
    }
};