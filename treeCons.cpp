// { Driver Code Starts
//

#include<bits/stdc++.h>
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

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node *buildtreeUtil(int in[], int pre[], int instart,int inend, unordered_map<int,int> &mp,int *preindex)
{
    
    if(instart>inend)
        return NULL;
    int data_x = pre[(*preindex)++];
    Node *temp = new Node(data_x);
    temp->data = data_x;
    temp->left = temp->right = NULL;
    if(instart==inend)
        return temp;
    int index = mp[data_x];
    if(index<=inend)
    {
    temp->left = buildtreeUtil(in,pre,instart,index-1,mp,preindex);		//preindex inside this function is already of type int*, so we don't have to send address recursively
    temp->right = buildtreeUtil(in,pre,index+1,inend,mp,preindex);
    }
    return temp;
}

Node* buildTree(int in[],int pre[], int n)
{
//add code here.
unordered_map<int,int> mp;
for(int i=0;i<n;i++)
{
    mp[in[i]] = i;
}
int preindex = 0;
return buildtreeUtil(in,pre,0,n-1,mp,&preindex);
}