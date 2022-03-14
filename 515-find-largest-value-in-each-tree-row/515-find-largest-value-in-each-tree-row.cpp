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
    void calc(TreeNode* root, int level, vector<int>&res)
    {
        if(root==NULL)
            return;
        else if(res.size()<=level)
        {
            res.push_back(root->val);
        }
        else
        {
            res[level] = max(res[level],root->val);
        }
        calc(root->left,level+1,res);
        calc(root->right,level+1,res);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        calc(root,0,res);
        return res;
    }
};