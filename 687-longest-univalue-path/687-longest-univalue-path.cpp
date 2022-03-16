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
    pair<int,int> calc(TreeNode* root, int &m)
    {
        if(root==NULL)
            return {-1001,-1};
        if(root->left==NULL&&root->right==NULL)
            return {root->val,1};
        
        pair<int,int> l = calc(root->left,m);
        pair<int,int> r = calc(root->right,m);
        if(root->val==l.first&&root->val==r.first)
        {
            m = max(m,1+l.second+r.second);
            return {root->val,1+max(l.second,r.second)};
        }
        if(root->val==l.first)
            return {root->val,1+l.second};
        if(root->val==r.first)
            return {root->val,1+r.second};
        m = max(m,max(l.second,r.second));
        return {root->val,1};
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int m = 1;
        pair<int,int> ans = calc(root,m);
        m=max(m,ans.second);
        return --m;
    }
};