#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> nums, int k) {
	unordered_map<int,int> s;
	int currsum=0,res=0;
	for(int i=0;i<nums.size();i++)
	{
		currsum+=nums[i];
		if(currsum==k)
			res++;
		if(s.find(currsum-k)!=s.end())
		{
			res+=s[currsum-k];
		}
		s[currsum]++;
	}
	return res;
}


int main()
{
	int n,sum,num;
	cin>>n>>sum;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		nums.push_back(num);
	}
	cout<<subarraySum(nums,sum)<<endl;
	return 0;

}