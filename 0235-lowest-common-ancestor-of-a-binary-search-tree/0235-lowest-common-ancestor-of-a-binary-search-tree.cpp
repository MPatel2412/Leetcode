/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = p->val;
        int y = q->val;
        int node = root->val;
        if(min(x,y) < node && node < max(x,y))
            return root;

        if(x < node && y < node)
            return lowestCommonAncestor(root->left,p,q);
        if(x > node && y > node)
            return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};