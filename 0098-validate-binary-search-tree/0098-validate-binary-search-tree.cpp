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
    bool check(TreeNode *root,long long l,long long r)
    {
        if(root == NULL)
            return true;
        
        if(root->val < r && root->val > l)
        {
            return check(root->left,l,root->val) && check(root->right,root->val,r);
        }
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->right == NULL && root->left == NULL)
            return true;
        long long int min = -1000000000000, max = 1000000000000;
        return check(root,min,max);
    }
};