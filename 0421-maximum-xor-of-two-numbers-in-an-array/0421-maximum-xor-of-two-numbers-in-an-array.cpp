struct Node{
    Node *links[2];
    bool flag = false;

    bool containsVal(int bit)
    {
        return links[bit] != NULL;
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    bool isEnd(){
        return flag;
    }
    void markEnd()
    {
        flag = true;
    }
    
};
class Trie{
    private: Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for(int i=31; i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containsVal(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
        node->markEnd();
    }
    int getMax(int num)
    {
        int maxNum = 0; 
        Node *node = root;
        for (int i = 31; i >= 0; i--) 
        { 
            int bit = (num >> i) & 1;
            if (node->containsVal(1 - bit)) {
                maxNum |= (1 << i); 
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum; 
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();
        int n = nums.size();
        for(auto num : nums)
        {
            t->insert(num);
        }
        int maxi = INT_MIN;
        for(auto it : nums)
        {
            maxi = max(maxi, t->getMax(it));
        }
        return maxi;
    }
};