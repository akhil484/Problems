#include<iostream>
using namespace std;
int q[10],front=-1,rear=-1;
//int size=sizeof(q)/sizeof(q[0])
bool isEmpty()
{
	if(front==-1)
		return true;
	else
		return false;
}
bool isFull()
{
	if(front==(rear+1)%(sizeof(q)/sizeof(int)))
		return true;
	else
		return false;
}
void Enqueue(int data)
{
	if(isFull())
	{
		cout<<"Queue is completely filled"<<"\n";
		return;
	}
	else if(isEmpty())
	{
		front++;
		rear++;
		q[front]=data;
	}
	else
	{
		rear=(rear+1)%(sizeof(q)/sizeof(int));
		q[rear]=data;
	}
}
void Dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is Empty"<<"\n";
		return;
	}
	else if(front==rear)
		front=rear=-1;
	else
	{
		front=(front+1)%(sizeof(q)/sizeof(int));
	}
}
void display()
{
	cout<<"Queue:"<<"\n";
	int count=((rear+sizeof(q)/sizeof(int)-front)%(sizeof(q)/sizeof(int)))+1;
	for(int i=0;i<count;i++){
		int index=(front+i)%(sizeof(q)/sizeof(int));
		cout<<q[index]<<"\n";
	}
}
int main()
{
	Dequeue();
	Enqueue(1);
	Enqueue(8);
	Enqueue(7);
	Enqueue(6);
	Enqueue(2);
	Dequeue();
	display();
	Enqueue(5);
	Enqueue(3);
	display();
}