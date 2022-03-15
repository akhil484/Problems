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
    pair<int,int> calc(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        pair<int,int> l = calc(root->left);
        pair<int,int> r = calc(root->right);
        int incl = root->val+l.second+r.second;
        int excl = max(l.first,l.second)+max(r.first,r.second);
        return {incl,excl};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>ans = calc(root);
        return max(ans.first,ans.second);
    }
};