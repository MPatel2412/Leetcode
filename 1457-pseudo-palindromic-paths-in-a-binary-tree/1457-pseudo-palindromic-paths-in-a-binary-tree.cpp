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
    int ans = 0;
    vector<int> vis;
    int count  = 0;
    
    void dfs(TreeNode *node,bool need)
    {
        if(node == NULL)
            return ;
        
        int val = node->val;
        vis[val] ^= 1;
        if(vis[val])
            count++;
        else
            count--;
        
        if(node->left==NULL && node->right==NULL)
        {
            ans += count == need;
        }
        dfs(node->left,need^1);
        dfs(node->right,need^1);
        
        vis[val]^=1;
        if(vis[val])
            count++;
        else
            count--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vis.resize(10,0);
        dfs(root,1);
        
        return ans;
    }
};