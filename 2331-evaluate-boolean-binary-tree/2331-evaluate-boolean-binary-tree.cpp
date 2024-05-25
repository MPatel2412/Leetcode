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
    bool solve(TreeNode *root)
    {
        if(root->left == NULL && root->right==NULL)
            return root->val;
        
        bool leftVal = solve(root->left);
        bool rightVal = solve(root->right);
        bool ans;
        if(root->val == 2)
        {
            ans = leftVal | rightVal;
        }
        else 
        {
            ans = leftVal & rightVal;
        }
        return ans;
        
        
    }
public:
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};