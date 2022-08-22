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
    void createGraph(TreeNode* root, unordered_map<int,vector<int>> &mp)
    {
        if(!root)
            return;
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});
        while(!q.empty())
        {
            auto [node,parent] = q.front();
            q.pop();
            if(parent!=-1)
            {
                mp[parent].push_back(node->val);
                mp[node->val].push_back(parent);
            }
            if(node->left)
                q.push({node->left,node->val});
            if(node->right)
                q.push({node->right,node->val});
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> mp;
        createGraph(root,mp);
        
        queue<pair<int,int>> q;
        q.push({start,0});
        int maxTime=0;
        unordered_map<int,bool> vis;
        vis[start]=true;
        while(!q.empty())
        {
            auto [node,time] = q.front();
            q.pop();
            maxTime=max(maxTime,time);
            for(auto it:mp[node])
            {
                if(!vis[it])
                {
                    q.push({it,time+1});
                    vis[it]=true;
                }
            }
        }
        return maxTime;
    }
};