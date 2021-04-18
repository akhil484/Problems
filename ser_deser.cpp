/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
//     void utils(TreeNode *root,string &serl)
//     {
//         if(!root)
//         {
//             serl=serl+" #";
//             return;
//         }
//         serl=serl+" "+to_string(root->val);
//         utils(root->left,serl);
//         utils(root->right,serl);
        
//     }
    
    TreeNode *utild(istringstream& ss)
    {
        string s;
        ss >> s;
        if(s=="#")
        {
            return NULL;
        }
        TreeNode *tmp=new TreeNode(stoi(s));
        tmp->left=utild(ss);
        tmp->right=utild(ss);
        return tmp;
    }
        
    string serialize(TreeNode* root) {
        return !root ? " #" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // int curr=0;
        // return utild(data,curr);
        istringstream ss(data);
        return utild(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
