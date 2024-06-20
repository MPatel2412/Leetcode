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
class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;
public:
    BSTIterator(TreeNode* root,bool var) {
        reverse = var;
        pushAll(root);
    
    }
    
    int next() {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
    void pushAll(TreeNode *node)
    {
        while(node!=NULL)
        {
            myStack.push(node);
            if(!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i < j)
        {
            if(i+j == k)
                return true;
            else if(i+j > k)
            {
                j = r.next();
            }
            else
            {
                i = l.next();
            }
        }
        return false;
    }
};