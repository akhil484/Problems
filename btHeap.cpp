// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

bool isHeap(struct Node * tree);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isHeap(root)<< endl;
  }
  return 0;
}

// } Driver Code Ends


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*You are required to complete this method */
int countnodes(Node *tree)
{
    if(tree==NULL)
        return 0;
    return (1+countnodes(tree->left)+countnodes(tree->right));
}

bool isCompUtil(Node *tree, int index, int nodes_count)
{
    if(tree==NULL)
        return true;
    if(index>=nodes_count)
        return false;
    return (isCompUtil(tree->left,2*index+1,nodes_count) && isCompUtil(tree->right,2*index+2,nodes_count));
}

bool isHeapUtil(Node *root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    if(root->right==NULL)
        return (root->data>=root->left->data);
    else
    {
        if(root->data >= root->left->data && 
            root->data >= root->right->data)
            {
                return ((isHeapUtil(root->left)) && 
                    (isHeapUtil(root->right))); 
            }
        else
            return false;
    }
}

bool isHeap(Node * tree)
{
 // Your code here
 int nodes_count = countnodes(tree);
 int index=0;
 if(isCompUtil(tree,index,nodes_count) && isHeapUtil(tree))
    return true;
 return false;
 
}
