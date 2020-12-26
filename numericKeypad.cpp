// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
        if(N<=0)
            return 0;
        if(N==1)
            return 10;
        int row[] = {0, 0, -1, 0, 1}; 
        int col[] = {0, -1, 0, 1, 0}; 
        long long count[10][N+1];
        int num=0,ro=0,co=0,nextnum=0;
        long long tc=0;
        for(int i=0;i<10;i++)
        {
            count[i][0]=0;
            count[i][1]=1;
        }
        for(int k=2;k<=N;k++)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(keypad[i][j]!='*' && keypad[i][j]!='#')
                    {
                        num=keypad[i][j]-'0';
                        count[num][k]=0;
                        for(int move=0;move<5;move++)
                        {
                            ro=i+row[move];
                            co=j+col[move];
                            if(ro>=0&&ro<4&&co>=0&&co<3&&keypad[ro][co]!='*' && keypad[ro][co]!='#')
                            {
                                nextnum=keypad[ro][co]-'0';
                                count[num][k] += count[nextnum][k-1];
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<10;i++)
        {
            tc+=count[i][N];
        }
        return tc;
            
        
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
