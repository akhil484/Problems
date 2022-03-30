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
    void calc(TreeNode *root, int &res, string s)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            s=s+to_string(root->val);
            res+=stoi(s);
            return;
        }
        calc(root->left,res,s+to_string(root->val));
        calc(root->right,res,s+to_string(root->val));
    }
    
    int sumNumbers(TreeNode* root) {
        int res=0;
        calc(root,res,"");
        return res;
    }
};