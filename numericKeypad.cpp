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
        
		
	//2nd method with O(1) space
		// Your code goes here
		list<int> mylist[10];
		mylist[0].assign({ 0, 8 }); 
    mylist[1].assign({ 1, 2, 4 }); 
    mylist[2].assign({ 2, 1, 3, 5 }); 
    mylist[3].assign({ 3, 6, 2 }); 
    mylist[4].assign({ 4, 1, 7, 5 }); 
    mylist[5].assign({ 5, 4, 6, 2, 8 }); 
    mylist[6].assign({ 6, 3, 5, 9 }); 
    mylist[7].assign({ 7, 4, 8 }); 
    mylist[8].assign({ 8, 5, 0, 7, 9 }); 
    mylist[9].assign({ 9, 6, 8 }); 
    
      // Storing values for n = 1 
    long long arr[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; 
    for(int i=2;i<=N;i++)
    {
        long long arr2[10]={0};
        for(int j=0;j<10;j++)
        {
            for(int x:mylist[j])
                arr2[x]+=arr[j];
        }
        for(int j=0;j<10;j++)
            arr[j]=arr2[j];
    }
    long long tc=0;
        for(int i=0;i<10;i++)
        {
            tc+=arr[i];
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
