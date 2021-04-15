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
    int height(TreeNode *root,bool &isbal) {
			if(root == NULL)return 0;
			int lh=height(root->left,isbal);
            int rh=height(root->right,isbal);
            int curr_h=max(lh,rh)+1;
            int gap=abs(lh-rh);
            if(gap>1)
                isbal=false;
            return curr_h;
		}
    bool isBalanced(TreeNode* root) {
        bool isbal=true;
        height(root,isbal);
        return isbal;
    }
};
