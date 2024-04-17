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
    void f(TreeNode *root,string s,string &res)
    {
        if(root==NULL)
        {
            return ;
        }
        char c = (char)(root->val + 'a');
        s += c;
        if(!root->left && !root->right)
        {
            reverse(s.begin(),s.end());
            if(res.empty() || s < res)
            {
                res = s;
            }
            reverse(s.begin(),s.end());
        }
        f(root->left,s,res);
        f(root->right,s,res);
    } 
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;
        f(root,"",res);
        return res;
    }
};
