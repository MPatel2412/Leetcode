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
    TreeNode *createTree(vector<int> &preorder,vector<int> &inorder,int start,int end)
    {
        if(start > end)
            return NULL;
        int rootIndex;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i] == preorder[index])
            {
                rootIndex = i;
                break;
            }
        }
        TreeNode *node = new TreeNode(preorder[index]);
        index++;
        node->left = createTree(preorder,inorder,start,rootIndex-1);
        node->right = createTree(preorder,inorder,rootIndex+1,end);
        
        return node;
    }
public:
    int index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        int n = inorder.size();
        if(n == 0)
            return NULL;
        return createTree(preorder,inorder,0,n-1);
    }
};