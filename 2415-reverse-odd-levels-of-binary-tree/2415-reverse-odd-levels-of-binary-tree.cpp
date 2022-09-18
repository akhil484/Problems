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
    void utils(int level, TreeNode* in, TreeNode* rev_in)
    {
        if((in==NULL||rev_in==NULL))
            return;
        utils(level+1,in->left,rev_in->right);
        if(level%2==1)
        {
            int temp = in->val;
            in->val = rev_in->val;
            rev_in->val = temp;
            
        }
        if(level!=0)
            utils(level+1,in->right,rev_in->left);
        
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* in = root;
        TreeNode* rev_in = root;
        utils(0,in,rev_in);
        return root;
    }
};