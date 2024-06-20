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
int index;
    TreeNode* f(vector<int>& inorder,vector<int>& preorder,int l,int r)
    {
        if(l > r)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        int temp;
        for(int i=l;i<=r;i++)
        {
            if(inorder[i] == root->val)
            {
                temp = i;
                break;
            }
        }
        root->left = f(inorder,preorder,l,temp-1);
        root->right = f(inorder,preorder,temp+1,r);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        index = 0;
        int n = preorder.size();
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        return f(inorder,preorder,0,n-1);
    }
};