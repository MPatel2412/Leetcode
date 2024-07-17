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
    void f(TreeNode *node,TreeNode *prev,vector<TreeNode*> &ans,unordered_map<int,int> &ump)
    {
        //base condition
        if(node == NULL)
            return;
        if(node->left == NULL && node->right == NULL)
        {
            if(ump.find(node->val) != ump.end())
            {
                if(prev != NULL)
                {
                    if(prev->left == node)
                    {
                        prev->left = NULL;
                    }
                    else
                    {
                        prev->right = NULL;
                    }
                }
                else
                {
                    node = NULL;
                }
            }
            else
            {
                if(prev == NULL)
                {
                    ans.push_back(node);
                }
            }
            return;
        }


        if(prev == NULL && ump.find(node->val) == ump.end()){
            ans.push_back(node);
        }

        if(ump.find(node->val) != ump.end())
        {
            if(prev != NULL)
            {
                if(prev->left == node)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
            }
            f(node->left,NULL,ans,ump);
            f(node->right,NULL,ans,ump);
        }
        else
        {
            f(node->left,node,ans,ump);
            f(node->right,node,ans,ump);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> ump;
        for(auto it : to_delete){
            ump[it]++;
        }
        TreeNode *temp = root;
        vector<TreeNode*> ans;
        f(temp,NULL,ans,ump);

        return ans;

    }
};