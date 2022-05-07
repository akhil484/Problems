/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
    Node* dfs(Node* cur,vector<Node*>& vis)
    {
        
        Node* copy=new Node(cur->val);
        
        vis[cur->val] = copy;
            for(auto it:cur->neighbors)
            {
                if(vis[it->val]!=NULL)   
                {
                    (copy->neighbors).push_back(vis[it->val]);    
                }
                else
                    (copy->neighbors).push_back(dfs(it,vis));
            }
            
            return copy;
    }
    Node* cloneGraph(Node* node) {
        vector<Node*> vis(101,NULL);
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //Single node
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,vis);
    }
};