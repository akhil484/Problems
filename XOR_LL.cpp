// { Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node* insert(struct Node *head, int data);

vector<int> printList (struct Node *head);

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *head = NULL;
        int n, tmp;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            head = insert(head, tmp);
        }
        vector<int> vec = printList (head);
        for(int x : vec)
        cout<<x<<" ";
        cout<<endl;
        for(int i = vec.size() - 1;i>=0;i--){
            cout<<vec[i]<<" ";
        }
        cout<<"\n";
    }
	return (0);
}
// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
	int data;
	struct Node* npx; 
	
	Node(int x){
	    data = x;
	    npx = NULL;
	}
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers 
struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/


// function should insert the data to the front of the list
// Node* XOR (Node *a, Node *b)
// {
//     return reinterpret_cast<Node *>(
//       reinterpret_cast<uintptr_t>(a) ^
//       reinterpret_cast<uintptr_t>(b));
// }
struct Node* insert(struct Node *head, int data)
{
	// Code here
	Node *temp=new Node(data);
	temp->npx = head;
	if(head!=NULL)
	{
	    head->npx=XOR(temp,head->npx);
	}
	head=temp;
	return head;
}

vector<int> printList (struct Node *head)
{
	// Code here
	Node *cur=head;
	Node *prev=NULL;
	Node *next;
	vector<int> res;
	while(cur!=NULL)
	{
	    res.push_back(cur->data);
	    next=XOR(prev,cur->npx);
	    prev=cur;
	    cur=next;
	}
	return res;
}
