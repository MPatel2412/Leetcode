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
    TreeNode* findChild(TreeNode *node)
    {
        if(node->right == NULL)
            return node;
        
        return findChild(node->right);
            
    }
public:
    TreeNode* f(TreeNode *root)
    {
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        
        TreeNode *rightChild = root->right;
        TreeNode *rightMostChild = findChild(root->left);
        rightMostChild->right = rightChild;
        
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val == key)
            return f(root);
        
        TreeNode *dummy = root;
        while(root!= NULL)
        {
            if(root->val > key)
            {
                if(root->left != NULL && root->left->val == key )
                {
                    root->left = f(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right != NULL && root->right->val == key )
                {
                    root->right = f(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};