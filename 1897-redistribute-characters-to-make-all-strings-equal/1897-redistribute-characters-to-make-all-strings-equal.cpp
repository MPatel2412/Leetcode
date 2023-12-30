class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> checkMap;
        for(auto &s : words)
        {
            for(int i=0;i<s.size();i++)
            {
                checkMap[s[i]]++;
            }
        }
        for(auto x : checkMap)
        {
            if(x.second % words.size() != 0)
                return false;
        }
        return true;
    }
};