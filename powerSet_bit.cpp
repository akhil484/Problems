// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    int len=s.length();
		    int pow_set = pow(2,len);
		    //To get all power set start i from 0 but we don't want empty set so we are starting from 1
		    for(int i=1;i<pow_set;i++)
		    {
		        string st = "";
		        for(int j=0;j<len;j++)
		        {
		            if(i&(1<<j))
		            {
		                st+=s[j];
		            }
		        }
		        res.push_back(st);
		    }
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code EndsGiven a string S find all possible substrings of the string in lexicographically-sorted order.
