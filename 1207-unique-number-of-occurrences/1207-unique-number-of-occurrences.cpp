class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(auto it : arr)
        {
            ump[it]++;
        }
        set<int> s;
        for(auto x : ump)
        {
            if(s.find(x.second) != s.end())
            {
                return false;
            }
            s.insert(x.second);
        }
        return true;
            
    }
};