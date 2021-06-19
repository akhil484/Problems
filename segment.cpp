// #include<bits/stdc++.h>
// using namespace std;


// int getmid(int s,int e)
// {
// 	return s+(e-s)/2;
// }

// // int minval(int x,int y)
// // {
// // 	return (x<y)?x:y;
// // }


// // int RMQUtil(int *st,int ss,int se,int qs,int qe,int si)
// // {
// // 	if(qs<=ss&&qe>=se)
// // 	{
// // 		return st[si];
// // 	}
// // 	if(qs>se||qe<ss)
// // 		return INT_MAX;

// // 	int mid = getmid(ss, se);
// // 	return minval(RMQUtil(st,ss,mid,qs,qe,2*si+1),RMQUtil(st,mid+1,se,qs,qe,2*si+2));
// // }


// // int RMQ(int *st,int n,int qs,int qe)
// // {
// // 	if(qs>qe||qs<0||qe>n-1)
// // 	{
// // 		cout<<"Invalid Input";  
// //         return -1;
// // 	}
// // 	return RMQUtil(st,0,n-1,qs,qe,0);
// // }


// void updatevalutil(int *st,int diff,int ss,int se,int si,int i)
// {
// 	if(i>se||i<ss)
// 		return;
// 	st[si]=st[si]+diff;
// 	if(se!=ss)
// 	{
// 		int mid=getmid(ss,se);
// 		updatevalutil(st,diff,ss,mid,2*si+1,i);
// 		updatevalutil(st,diff,mid+1,se,2*si+2,i);
// 	}
// }


// void updateValue(int a[],int *st,int n,int i,int val)
// {
// 	if(i<0||i>n-1)
// 	{
// 		cout<<"Invalid Input";
// 		return;
// 	}
// 	int diff=val-a[i];
// 	a[i]=val;
// 	updatevalutil(st,diff,0,n-1,0,i);
// }




// int getsumutil(int ss,int se,int qs,int qe,int *st,int si)
// {
// 	if(qs<=ss&&qe>=se)
// 		return st[si];
// 	if(ss>qe||qs>se)
// 		return 0;
// 	int mid=getmid(ss,se);
// 	return getsumutil(ss,mid,qs,qe,st,2*si+1)+getsumutil(mid+1,se,qs,qe,st,2*si+2);

// }



// int getSum(int *st,int n,int qs,int qe)
// {
// 	if(qs<0||qe>n-1||qs>qe)
// 	{
// 		cout<<"Invalid Input"<<endl;
// 		return -1;
// 	}
// 	getsumutil(0,n-1,qs,qe,st,0);
// }


// int constructST(int ss,int se,int a[],int si,int *st)
// {
// 	if(ss==se)
// 	{
// 		st[si]=a[ss];
// 		return a[ss];
// 	}
// 	int mid=getmid(ss,se);
// 	st[si]=(constructST(ss,mid,a,2*si+1,st)+constructST(mid+1,se,a,2*si+2,st));
// 	return st[si];
// }


// int *constructSegmentTree(int a[], int n)
// {
// 	int h=(int)(ceil(log2(n)));
// 	int size = 2*(int)pow(2,h)-1;
// 	int *st=new int[size];
// 	constructST(0,n-1,a,0,st);

// 	return st;
// }


// int main()
// {
// 	int arr[] = {1, 3, 5, 7, 9, 11};  
//     int n = sizeof(arr)/sizeof(arr[0]); 
//     int *st = constructSegmentTree(arr, n);

//     cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;		//Print sum of values in array from index 1 to 3
//     updateValue(arr, st, n, 1, 10);  
  
//     // Find sum after the value is updated  
//     cout<<"Updated sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;
//     //cout<<"Minimum of values in range [1,4] is: "<<RMQ(st, n, 1,5)<<endl;
//     return 0;

// }


struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};
class NumArray {
    SegmentTreeNode* root;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }
   
    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            diff = modifyTree(i,val,root->right);
        } else {
            diff = modifyTree(i,val,root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};
