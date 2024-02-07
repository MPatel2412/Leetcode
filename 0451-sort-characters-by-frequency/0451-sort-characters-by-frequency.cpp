class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
            m[s[i]]++;
        string ans="";
        vector<pair<int,char>> vx;
        for(auto it:m)
        {
            vx.push_back({it.second,it.first});
        }
        sort(vx.rbegin(),vx.rend());
        for(auto i: vx)
        {
            int temp=i.first;
            while(temp--)
                ans+=i.second;
        }
        return ans;
            
    }
};