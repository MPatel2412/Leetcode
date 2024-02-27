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
int maxi ,curr;
public:
    int f(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int left = f(root->left);
        int right = f(root->right);
        maxi = max(maxi,left+right);
        return max(left,right)+1;
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = INT_MIN;
        curr = 0;
        int temp = f(root);
        return maxi;
    }
};