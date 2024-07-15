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
    void DFS(TreeNode *node, unordered_map<int,vector<pair<int,int>>> &child,unordered_map<TreeNode*,bool> &dp){
        
        if(child.find(node->val) == child.end()){
            return;
        }
        if(dp.find(node) != dp.end())
            return;
        dp[node] = true;
        for(auto it : child[node->val])
        {
                int val = it.first;
                int leftChild = it.second;

                if(leftChild ==1)
                {
                    node->left = new TreeNode(val);
                    DFS(node->left, child,dp);
                }
                else
                {
                    node->right = new TreeNode(val);
                    DFS(node->right,child,dp);
                }
        }
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *root;
        unordered_map<int,int> parent;
        for(auto it : descriptions)
        {
            parent[it[1]] = it[0];
        }
        int rootNode ;
        for(auto it : parent){
            if(parent.find(it.second) == parent.end()){
                rootNode = it.second;
            }
        }
        unordered_map<int,vector<pair<int,int>>> child;
        for(auto it : descriptions)
        {
            child[it[0]].push_back({it[1],it[2]});
        }
        root = new TreeNode(rootNode);
        TreeNode *temp = root;
        unordered_map<TreeNode*,bool> dp;
        DFS(temp,child,dp);

        return root;

    }
};