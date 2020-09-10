#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *right;
	node *left;
};

node *getNewnode(int num)
{
	node *temp = new node();
	temp->data = num;
	temp->left = temp->right = NULL;
	return temp;
}

node *insert(node *root, int num)
{
	if(root==NULL)
		root=getNewnode(num);
	else if(root->data>num)
		root->left = insert(root->left,num);
	else
		root->right = insert(root->right,num);

	return root;
}

void inorder(node *root,int n)
{
	//cout<<n<<endl;
	static int count = 0;			//there is only one copy of a static variable in a program
	if(root==NULL)
		return;

	if(count<=n)
	{
	inorder(root->left,n);
	count++;
	if(count==n)
		cout<<root->data;
	
	inorder(root->right,n);
}
}

void diagonalPrintUtil(node *root, int d, map<int, vector<int>> &dp)
{
	if(!root)
		return;
	dp[d].push_back(root->data);
	diagonalPrintUtil(root->left,d+1,dp);
	diagonalPrintUtil(root->right,d,dp);
}


void diagonalPrint(node *root)
{
	map<int, vector<int> > dp;
	diagonalPrintUtil(root,0,dp);
	cout<<"DIagonal Traversal of Tree:"<<endl;
	//map<int, vector<int> >::iterator itr;
	//map<int, vector<int> >::iterator it;
	for(auto itr=dp.begin();itr!=dp.end();itr++)
	{
		for(auto it = itr->second.begin();it!=itr->second.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	node *root = NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	//root=insert(root,8);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	root=insert(root,6);
	root=insert(root,11);
	root=insert(root,16);
	root=insert(root,27);
	//inorder(root,5);
	diagonalPrint(root);
	return 0;
}