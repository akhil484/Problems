#include<iostream>
#include<vector>
#include<string>
using namespace std;

string a[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void show(vector<int> vec, string res,int index)
{
	if(index==vec.size())
	{
		cout<<res<<" ";
		return;
	}
	for(int i=0;i<a[vec[index]].length();i++)
	{
		res+=a[vec[index]][i];
		show(vec,res,index+1);
		res=res.erase(res.length()-1);
		if(vec[index]==0 || vec[index]==1)
			return;	
	}
}


int main()
{
	string res="";
	int num;
	vector<int> vec;
	cin>>num;
	while(num!=0)
	{
		int rem=num%10;
		num=num/10;
		vec.insert(vec.begin(),rem);
	}
	//cout<<vec.size();
	show(vec,res,0);
}