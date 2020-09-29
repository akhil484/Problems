#include<iostream>
#include<climits>
using namespace std;

class minheap
{
	int *harr;			  //pointer to array of elements in heap
	int capacity;		 //maximum size of the heap
	int heap_size;		//current number of elements in the heap
public:
	minheap(int capacity);
	void minheapify(int);
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return ((2*i)+1);
	}
	int right(int i)
	{
		return ((2*i)+2);
	}
	int extractmin();
	void decreaseKey(int i, int new_val);
	int getmin()
	{
		return harr[0];
	}
	void deleteKey(int i);
	void insertKey(int k);
};

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp; 
}

minheap::minheap(int c)
{
	heap_size = 0;
	capacity = c;
	harr = new int[c];
}

void minheap::insertKey(int k)
{
	if(heap_size == capacity)
	{
		cout<<"Could not insert key due to overflow"<<endl;
		return;
	}
	heap_size++;
	int i = heap_size-1;
	harr[i] = k;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}

}

int minheap::extractmin()
{
	if(heap_size<=0)
	{
		return INT_MAX;
	}
	if(heap_size==1)
	{
		heap_size--;
		return harr[0];
	}
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	minheapify(0);
	return root;
}

void minheap::minheapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l<heap_size && harr[l]<harr[i])
	{
		smallest=l;
	}
	if(r<heap_size && harr[r]<harr[smallest])
	{
		smallest = r;

	}
	if(smallest!=i)
	{
		swap(&harr[i],&harr[smallest]);
		minheapify(smallest);
	}
}

void minheap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while(i>0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i = parent(i);
	}
}
 void minheap::deleteKey(int i)
 {
 	decreaseKey(i,INT_MIN);
 	extractmin();
 }
int main()
{
	minheap h(11);
	h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
    cout << h.extractmin() << " "; 
    cout << h.getmin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getmin(); 
    return 0; 
}