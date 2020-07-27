#include<iostream>
using namespace std;
/*
int arr[10];
int top=-1;
void push(int data)
{
	if(top==9){
		cout<<"Stack Overflown";
	}
	else{
	top++;
	arr[top]=data;
}
}
void pop()
{
	if(top==-1){
		cout<<"Stack Already Empty";
	}
	else{
	top--;	
	}
	
}


void display()
{
	for(int i=0;i<=top;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
void isEmpty(){
	if(top==-1){
		cout<<"true"<<"\n";
	}
	else{
		cout<<"False"<<"\n";
	}
}*/
struct node{
	int data;
	node *next;
};
node *top=NULL;
void push(int data){
	node *newNode=new node();
	newNode->data=data;
	newNode->next=NULL;
	if(top==NULL){
		top=newNode;
	}
	else{
		newNode->next=top;
		top=newNode;
	}
}
void pop(){
	node *temp;
	if(top==NULL){
		cout<<"Stack already empty";
	}
	else{
		temp=top;
		top=top->link;
	}
	delete temp;
}
void display(){
	node *temp=top;
	while(temp->next!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<"\n";
}
int main(){
	push(4);
	push(2);
	push(5);
	push(1);
	display();
	pop();
	display();
	push(6);
	display();
	pop();
	display();
	return 0;
}