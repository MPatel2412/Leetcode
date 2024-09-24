class Solution {
public:
    int f(string s, int index, set<string> &dict,unordered_map<int,int> &ump)
    {
        //base condition
        if(index == s.size())
            return 0;
        if(ump.count(index))
            return ump[index];
        int ans = 1 + f(s,index+1,dict,ump);
        for(int i=index; i < s.size(); i++)
        {   
            string sub_word = s.substr(index,i - index + 1);
            if(dict.find(sub_word) != dict.end())
            {
                ans = min(ans, f(s,i+1,dict,ump));
            }
        }   
        return ump[index] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> dict;
        for(auto word : dictionary)
        {
            dict.insert(word);
        }
        unordered_map<int,int> memo;
        return f(s,0,dict,memo);
    }
};