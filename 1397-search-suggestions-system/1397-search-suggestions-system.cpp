struct Node{
    public:
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie{
    public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) 
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) 
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix) 
    {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) 
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n= products.size();
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        
        for(int i=0; i < searchWord.size(); i++)
        {
            string pre = searchWord.substr(0,i+1);
            int index = 0;
            vector<string> temp;
            int cnt = 0;
            while(index < n && temp.size() < 3)
            {
                if(pre == products[index].substr(0,i+1))
                {
                    temp.push_back(products[index]);
                }
                index++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};