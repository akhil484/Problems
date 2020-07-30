#include<iostream>
#include<queue>
using namespace std;
struct bnode
{
	int data;
	bnode *left;
	bnode *right;
};
bnode* createnewnode(int data)
{
	bnode *node=new bnode();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}
bnode* insert(bnode *root,int data)
{
	if(root==NULL)
	{
		root=createnewnode(data);
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
bnode *search(bnode *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(root->data==data)
	{
		return root;
	}
	else if(data<=root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
}
bnode *max(bnode *root)
{
	int m;
	if(root==NULL)
	{
		cout<<"empty";
		return root;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	else
	{
		while(root->right!=NULL)
		{
			return max(root->right);
		}
			return root;
	}
}
int min(bnode *root)
{
	if(root==NULL)
	{
		cout<<"empty";
		
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return root->data;
	}
	else
	{
		while(root->left!=NULL)
		{
			return min(root->left);
		}
		return root->data;
	}
}

bnode* mini(bnode *root)
{
	if(root==NULL)
	{
		cout<<"empty";
		
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return root;
	}
	else
	{
		while(root->left!=NULL)
		{
			return mini(root->left);
		}
		return root;
	}
}
void levelorder(bnode *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		queue<bnode *> q;
		q.push(root);
		while(!q.empty())
		{
			bnode *current=q.front();
			cout<<current->data<<" ";
			if(current->left!=NULL)
				q.push(current->left);
			if(current->right!=NULL)
				q.push(current->right);
			q.pop();
		}
	}
}
int calh(bnode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	return max(calh(root->left),calh(root->right))+1;
}

void preorder(bnode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(bnode *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void Inorder(bnode *root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	
}

bool IsBinarySearchTreeUtil(bnode *root,int minval,int maxval)
{
	if(root==NULL)
		return true;
	if(root->data>=minval&&root->data<maxval&&IsBinarySearchTreeUtil(root->left,minval,root->data)&&IsBinarySearchTreeUtil(root->right,root->data,maxval))
	{
		return true;
	}
	else
		return false;
}

bool IsBinarySearchTree(bnode *root)
{
	return IsBinarySearchTreeUtil(root,INT_MIN,INT_MAX);
}

bnode *del(bnode *root,int value)
{
	if(root==NULL)
	{
		cout<<"Not Found"<<endl;
		return root;
	}
	if(root->data>value)
	{
		root->left=del(root->left,value);
	}
	else if(root->data<value)
	{
		root->right=del(root->right,value);
	}
	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			delete root;
			root=NULL;			//that address is empty but root is a pointer to node so it is not empty.
			return root;
		}
		else if(root->right==NULL)
		{
			bnode *temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else if(root->left==NULL)
		{
			bnode *temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else
		{
			bnode *temp=mini(root->right);        //find node with minimum value in right subtree
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}

	}
}

int getSuccessor(bnode *root,int data)
{
	//maximum value will not have a Inorder Successor
	bnode *temp=search(root,data);
	if(temp==NULL)
		return -1;
	if(temp->right!=NULL)
	{
		bnode *temp1=mini(temp->right);
		return temp1->data;
	}
	//No right subtree
	bnode *ancestor=root;
	bnode *successor=NULL;
	while(ancestor!=temp)
	{
		if(ancestor->data>temp->data)
		{
			successor=ancestor;
			ancestor=ancestor->left;
		}
		else
			ancestor=ancestor->right;
	}
	return successor->data;
}


int getPredeccessor(bnode *root,int data)
{
	//minimum value will not have a predeccessor
	bnode *temp=search(root,data);
	if(temp==NULL)
		return -1;
	if(temp->left!=NULL)
	{
		bnode *temp1=max(temp->right);
		return temp1->data;
	}
	//No left subtree
	bnode *ancestor=root;
	bnode *predeccessor=NULL;
	while(ancestor!=temp)
	{
		if(ancestor->data<temp->data)
		{
			predeccessor=ancestor;
			ancestor=ancestor->right;
		}
		else
			ancestor=ancestor->left;
	}
	return predeccessor->data;
}

int main()
{
	int item,n,num;
	bnode *root=NULL;
	/*char ch;
	cout<<"Do you want to add items in trees?"<<"\n";
	cin>>ch;
	while(ch=='y')
	{
		cin>>item;
		insert(root,item);
		cout<<"Do you want to add items in trees?"<<"\n";
		cin>>ch;
	}
	cout<<"enter number you want to search";
	cin>>n;*/
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

	// cout<<"enter number you want to search";
	// cin>>n;
	// if(search(root,n)==true)
	// 	cout<<"Found"<<"\n";
	// else
	// 	cout<<"Not found"<<"\n";
	// num=max(root);
	// cout<<"Maximum number \t"<<num<<"\n";
	// int num1=min(root);
	// cout<<"Minimum number \t"<<num1<<"\n";
	// cout<<"Root \t"<<root->data<<"\n";
	// cout<<"Height "<<calh(root)<<endl;
	// levelorder(root);
	// cout<<"\n";
	// preorder(root);
	// cout<<"\n";
	// postorder(root);
	// cout<<"\n";
	// Inorder(root);
	// cout<<"\n";
	// root=del(root,19);
	//Inorder(root);
	cout<<getSuccessor(root,12)<<endl;
	cout<<getPredeccessor(root,25);
	return 0;


}