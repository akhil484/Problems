// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


 // } Driver Code Ends
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
class Solution{
  public:
    // function should print the topView of the binary tree
    vector<int> topView(struct Node *root)
    {
        //Your code here
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> p=q.front();
            q.pop();
            Node *curr=p.first;
            int vertical_dist = p.second;
            if(mp.find(vertical_dist)==mp.end())
            {
                mp[vertical_dist]=curr->data;
            }
            if(curr->left)
            {
                q.push(make_pair(curr->left,vertical_dist-1));
            }
            if(curr->right)
            {
                q.push(make_pair(curr->right,vertical_dist+1));
            }
        }
        // sort(mp.begin(),mp.end());
        map<int, int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }

};



// { Driver Code Starts.


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        Solution obj;
        vector<int> res = obj.topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




  // } Driver Code Ends
