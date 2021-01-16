// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int top=0,left=0,down=r-1,right=c-1;
        int d=0;
        vector<int> res;
        while(top<=down && left<=right)
        {
           if(d==0)
           {
               for(int i=left;i<=right;i++)
               {
                   res.push_back(matrix[top][i]);
               }
               top++;
           }
           else if(d==1)
           {
               for(int i=top;i<=down;i++)
               {
                   res.push_back(matrix[i][right]);
               }
               right--;
           }
           else if(d==2)
           {
               for(int i=right;i>=left;i--)
               {
                   res.push_back(matrix[down][i]);
               }
               down--;
           }
           else
           {
               for(int i=down;i>=top;i--)
               {
                   res.push_back(matrix[i][left]);
               }
               left++;
           }
           d=(d+1)%4;
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
