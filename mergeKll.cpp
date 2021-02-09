// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
class compare{
    public:

bool operator()(pair<Node*,int> a, pair<Node*,int> b)
{
    return a.first->data>b.first->data;
}
};
Node * mergeKLists(Node *a[], int N)
{
       // Your code here
    //   priority_queue<int, vector<int>, greater<int>> minHeap;
      
    //   for(int i=0;i<N;i++)
    //   {
    //       Node *temp = a[i];
    //       while(temp!=NULL)
    //       {
    //           minHeap.push(temp->data);
    //           temp = temp->next;
    //       }
    //   }

    //   Node *newhead = new Node(-1);
    //   Node *temp = newhead;
    //   while(!minHeap.empty())
    //   {
    //       temp->next = new Node(minHeap.top());
    //       minHeap.pop();
    //       temp = temp->next;
    //   }
      
    //   return newhead->next;
    
    priority_queue<pair<Node*,int>,vector<pair<Node*,int>>,compare> p;
    if(N==0)
        return NULL;
    Node *head,*tail;
    for(int i=0;i<N;i++)
    {
        if(a[i]!=NULL)
            p.push({a[i],i});
    }
    if(p.empty())
        return NULL;
    head=tail=p.top().first;
    int index=p.top().second;
    p.pop();
    a[index]=a[index]->next;
    if(a[index])
        p.push({a[index],index});
    while(!p.empty())
    {
        Node *temp=p.top().first;
        index=p.top().second;
        p.pop();
        tail->next=temp;
        tail=tail->next;
        a[index]=a[index]->next;
        if(a[index])
            p.push({a[index],index});
    }
    return head;
}

