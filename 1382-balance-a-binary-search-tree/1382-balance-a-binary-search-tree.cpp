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
    // int index;
public:
    void inorder(TreeNode *root, vector<int> &tree)
    {
        if(root==NULL)
            return ;
        
        inorder(root->left,tree);
        tree.push_back(root->val);
        inorder(root->right,tree);
    }
public:
    TreeNode *makeTree(vector<int> &inorder,int l,int r,int index)
    {
        if(l > r)
            return NULL;
        
        TreeNode *root = new TreeNode(inorder[index]);
        
        root->left = makeTree(inorder,l,index - 1, (l + index - 1)/2);
        root->right = makeTree(inorder,index + 1, r, (index + r + 1)/2);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        inorder(root,tree);
        int l = 0, r = tree.size() - 1;
        int index = (l + r)/2;
        
        return makeTree(tree,l,r,index);
    }
};