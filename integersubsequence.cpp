#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n,num;
	    cin>>n;
	    vector<int> a;
	    for(int i=0;i<n;i++)
	    {
	        cin>>num;
	        a.push_back(num);
	    }
	    unordered_set<int> s;
	    int l=1,maxlen=1;
	    for(int i=0;i<n;i++)
	    {
	        s.insert(a[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(s.find(a[i]-1)==s.end())
	        {
	            int j=a[i];
	            while(s.find(j)!=s.end())
	            {
	                j++;
	            }
	            maxlen=max(maxlen,j-a[i]);
	        }
	    }
	    cout<<maxlen<<endl;
	}
	return 0;
}