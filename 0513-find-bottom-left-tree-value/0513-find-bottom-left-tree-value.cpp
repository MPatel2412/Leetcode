class Solution {
int maxDepth,bottomLeftValue;
private:
    void dfs(TreeNode *root,int depth)
    {
        if(root==NULL)
        {
            return;
        }
        if (depth > maxDepth) 
        {  
            maxDepth = depth;
            bottomLeftValue = root->val;
        }
        
        dfs(root->left,depth+1);
        dfs(root->right,depth + 1);
        
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        bottomLeftValue = 0;
        dfs(root, 0);
        return bottomLeftValue;
    }
};

