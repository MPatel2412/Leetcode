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
private:
    int calc(TreeNode *root,int &maxi)
    {
        //base condition
        if(root==NULL)
            return 0;
        
        int left = max(0,calc(root->left,maxi));
        int right = max(0,calc(root->right,maxi));
        
        maxi = max(maxi,left+right+root->val);
        return root->val + max(left,right);
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int temp = calc(root,maxi);
        return maxi;
    }
};