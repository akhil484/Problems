#include<bits/stdc++.h>
using namespace std;
static int i=0;
struct node
{
	int data;
	node *left;
	node *right;
};

 node* get_newnode(char s)
{
	node *temp = new node();
	temp->data = s;
	temp->left = temp->right = NULL;
	return temp;
}

int find(string s, int si, int ei)
{
	if(si>ei)
		return -1;
	stack<char> st;
	for(int i=si;i<=ei;i++)
	{
		if(s[i]=='(')
			st.push(s[i]);
		else if(s[i]==')')
		{
			if(st.top()=='(')
			{
				st.pop();
				if(st.empty())
					return i;
			}
		}
	}
	return -1;
}

node* build_tree(string s, int si,int ei)
{
	if(si>ei)
		return NULL;
	
	node *temp=get_newnode(s[si]-'0');
	int index=-1;
	if(si+1<=ei && s[si+1]=='(')
		index = find(s,si+1,ei);
	if(index!=-1)
	{
		temp->left = build_tree(s,si+2,index-1);
		temp->right = build_tree(s,index+2,ei-1);
	}
	return temp; 

}
void inorder(node *root)
{
	if(root==NULL)
		return;

	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}



int main()
{
	string s;
	cin>>s;
	
	node *root = NULL;
	if(s.length()==0)
		cout<<"Empty Tree"<<endl;
	else
	{
		root = build_tree(s,0,s.length()-1);
	}
	preorder(root);
}