class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> st1;
        unordered_set<string> st2;

        for(auto word : arr)
        {
            if(st1.count(word))
            {
                continue;
            }
            if(st2.count(word))
            {
                st2.erase(word);
                st1.insert(word);
            }
            else
            {
                st2.insert(word);
            }
        }
        for(auto word : arr){
            if(!st1.count(word))
            {
                k--;
            }
            if(k==0)
            {
                return word;
            }
        }
        return "";
    }
};