// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
pair<pair<bool,int>,pair<int,int>> traverse(Node* root)
{
    if(!root)
    return {{1 , 0},{0 , 0}};
    
    if(!root->left && !root->right)
    return {{1 , 1} , {root->data , root->data}};
    
    pair<pair<bool,int>,pair<int,int>> p1=traverse(root->left);
    pair<pair<bool,int>,pair<int,int>> p2=traverse(root->right);
    
    bool left= (root->left) ? ((p1.second.second < root->data) ? 1 : 0) : 1;
    bool right= (root->right) ? ((p2.second.first > root->data) ? 1 : 0) : 1;
    
    int l=(root->left) ? p1.second.first : root->data;
    int r=(root->right) ? p2.second.second : root->data;
    
    if(p1.first.first && p2.first.first && left && right)
    return {{1 , p1.first.second + p2.first.second + 1} , {l , r}};
    
    return {{0 , max(p1.first.second , p2.first.second)} , {0 , 0}};
}
int largestBst(Node *root)
{
	return traverse(root).first.second;
}
