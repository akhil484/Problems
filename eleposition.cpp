#include<iostream>
#include<vector>
using namespace std;

 vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int ans=-1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                r=mid-1;
            }
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        res.push_back(ans);
        l=0;
        r=nums.size()-1;
        ans=-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                l=mid+1;
            }
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        res.push_back(ans);
        return res;
    }


int main()
{
	int n,num,target;
	cout<<"Enter the value of n"<<" ";
	cin>>n;
	vector<int> a;
	vector<int> res;
	cout<<"Enter array elements"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>num;
		a.push_back(num);
	}
	cout<<"Enter the value of target"<<" ";
	cin>>target;
	res = searchRange(a,target);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
}