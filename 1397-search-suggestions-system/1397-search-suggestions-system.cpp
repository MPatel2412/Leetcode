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
    void DFS(vector<string> &ans,string temp,Node *node)
    {
        if(ans.size() == 3)
            return ;
        if(node->isEnd())
        {
            ans.push_back(temp);
        }

        for(char ch ='a'; ch <= 'z'; ch++)
        {
            if(node->containsKey(ch))
            {
                temp.push_back(ch);
                DFS(ans,temp,node->get(ch));
                temp.pop_back();
            }
        }
    }
    vector<string> getStringswithPre(string prefix)
    {
        vector<string> ans;
        string temp = "";
        Node *node = root;
        for(int i=0; i < prefix.size(); i++)
        {
            if(node->containsKey(prefix[i]))
            {
                temp += prefix[i];
                node = node->get(prefix[i]);
            }
            else
                return ans;
        }
        DFS(ans,temp,node);
        return ans;
    }

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n= products.size();
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        Trie t;

        for(auto it : products)
        {
            t.insert(it);
        }
        for(int i=0; i < searchWord.size(); i++)
        {
            string pre = searchWord.substr(0,i+1);
            ans.push_back(t.getStringswithPre(pre));
        }

        return ans;
    }
};