#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode 
{ 
// The element to be stored 
    int element; 
  
// index of the array from which the element is taken 
    int i; 
  
// index of the next element to be picked from the array  
    int j; 
};

class Minheap
{
    MinHeapNode *harr;
    int heap_size;

public:
    Minheap(MinHeapNode arr[], int size);
    void Minheapify(int r);

    int left(int i)
    {
        return (2*i+1);
    }

    int right(int i)
    {
        return (2*i+2);
    }

    MinHeapNode getNode()
    {
        return harr[0];
    }

    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        Minheapify(0);
    }
};

Minheap::Minheap(MinHeapNode arr[], int size)
{
    heap_size = size;
    harr = arr;
    int i = (heap_size-1)/2;
    while(i>=0)
    {
        Minheapify(i);
        i--;
    }
}

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp=*x;
    *x=*y;
    *y=temp;
}

void Minheap::Minheapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if(l<heap_size&&harr[l].element<harr[i].element)
        smallest=l;
    if(r<heap_size&&harr[r].element<harr[smallest].element)
        smallest = r;
    if(smallest!=i)
    {
        swap(&harr[smallest],&harr[i]);
        Minheapify(smallest);
    }
}




void printArray(int arr[], int size) 
{ 
    for (int i=0; i < size; i++) 
        cout << arr[i] << " "; 
} 

void mergeKArrays(int *arr, int n, int k)
{
    int *output = new int[n*k];
    MinHeapNode *harr = new MinHeapNode[k];
    for(int i=0;i<k;i++)
    {
        harr[i].element=*((arr+i*n)+0);
        harr[i].i=i;
        harr[i].j=1;
    }
    Minheap hp(harr,k);
    for(int count=0;count<(n*k);count++)
    {
        MinHeapNode root = hp.getNode();
        //output[count] = root.element;
        cout<<root.element<<" ";
        if(root.j<n)
        {
            root.element = *((arr+(root.i)*n)+root.j);
            root.j +=1;
        }
        else 
            root.element = INT_MAX;
        hp.replaceMin(root);
    }
    //return output;
}

int main() 
{ 
    // Change n at the top to change number of elements 
    // in an array 
    int arr[][4] =  {{2, 6, 12, 34}, 
                     {1, 9, 20, 1000}, 
                     {23, 34, 90, 2000}}; 
    int k = sizeof(arr)/sizeof(arr[0]); 
    cout << "Merged array is " << endl;
     mergeKArrays((int *)arr, 4, k); 
  
     
    //printArray(output, 4*k); 
  
    return 0; 
} 