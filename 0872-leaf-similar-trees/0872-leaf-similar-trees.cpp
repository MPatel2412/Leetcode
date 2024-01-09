/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverseTree(TreeNode *root, vector<int> &order)
    {
        if(root==NULL)
            return ;
        traverseTree(root->left,order);
        if(root->left == NULL && root->right == NULL)
        {
            order.push_back(root->val);
        }
        traverseTree(root->right,order);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> order1;
        vector<int> order2;

        traverseTree(root1,order1);
        traverseTree(root2,order2);

        if(order1.size() != order2.size())  
            return false;
        int i = 0, j = 0;
        while( i < order1.size() && j < order2.size())
        {
            if(order1[i] != order2[j])
                return false;
            else
            {
                i++;
                j++;
            }
        }
        if(i!=j)
            return false;
        return true;
    }
};