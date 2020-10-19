// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Code here.
        int xo=nums[0];
        vector<int> res;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            xo^=nums[i];
        }
        int x=0;
        int y=0;
        int set_bit=xo & ~(xo-1);
        for(int i=0;i<n;i++)
        {
            if(nums[i] & set_bit)
                x=x^nums[i];
            else
                y=y^nums[i];
        }
        if(x>y)
        {
            res.push_back(y);
            res.push_back(x);
        }
        else
        {
            res.push_back(x);
            res.push_back(y);
        }
        return res;
    }
    
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
