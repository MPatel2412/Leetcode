class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1,cnt=0;
        for(auto c :word)
        {
            if(c==ch)
            {
                index=cnt;
                break;
            }
            cnt++;
        }
        if(index==-1)
            return word;
        string temp = word.substr(0,index+1);
        string temp2 = word.substr(index+1,word.size()-index);
        reverse(temp.begin(),temp.end());
        
        string ans = temp + temp2;
        
        return ans;
    }
};