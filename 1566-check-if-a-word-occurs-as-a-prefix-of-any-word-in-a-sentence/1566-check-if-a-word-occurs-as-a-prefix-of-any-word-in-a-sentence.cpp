class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        string temp = "";
        int n = sentence.size();
        for(int i=0; i < n; i++)
        {
            char ch = sentence[i];
            if(i == n-1)
            {
                temp += ch;
                if(temp == searchWord)
                    return index;
            }
            if(ch == ' ')
            {
                index++;
                temp = ""; 
            }
            else
            {
                temp += ch;
            }
            if(searchWord == temp)
            {
                return index;
            }
        }
        return -1;
    }
};