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
    int dfs(TreeNode *root, bool flag)
    {
        //base condition
        if(root==NULL)
            return 0;
        if(!root->left && !root->right)
        {
            if(!flag)
                return 0;
            else
                return root->val;
        }
        
        int leftVal = dfs(root->left,true);
        int rightVal = dfs(root->right,false);
        
        return leftVal + rightVal;
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,false);
    }
};