// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
    if(n<=0)
        return NULL;
        
    Node *root = new Node(levelOrder[0]);
    int index=-1;
    for(int i=iStart;i<=iEnd;i++)
    {
        if(levelOrder[0]==inorder[i])
        {
            index = i;
            break;
        }
    }
    unordered_set<int> s;
    for(int i=iStart;i<index;i++)
    {
        s.insert(inorder[i]);
    }
    int Llevel[s.size()];
    int rlevel[iEnd  -iStart - s.size()];
    int li=0,ri=0;
    for(int i=1;i<n;i++)
    {
        if(s.find(levelOrder[i])!=s.end())
        {
            Llevel[li++] = levelOrder[i];
        }
        else
            rlevel[ri++] = levelOrder[i];
    }
    root->left = buildTree(inorder,Llevel,iStart,index-1,index-iStart);
    root->right = buildTree(inorder,rlevel,index+1,iEnd,iEnd-index);
    return root;
}