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
    void calSum(TreeNode* root, int &sum, TreeNode* parent,TreeNode* grandparent)
    {
        if(!root)
            return;
        if(grandparent&&grandparent->val%2==0)
            sum+=root->val;
        calSum(root->left, sum,root,parent);
        calSum(root->right, sum,root,parent);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        calSum(root, sum,NULL,NULL);
        return sum;
    }
};