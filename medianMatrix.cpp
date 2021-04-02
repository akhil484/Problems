// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here    
        int mi=INT_MAX,m=INT_MIN;
        for(int i=0;i<r;i++)
        {
            if(matrix[i][0]<mi)
                mi=matrix[i][0];
            if(matrix[i][c-1]>m)
                m=matrix[i][c-1];
        }
        int des = (r*c+1)/2;
        while(mi<m)
        {
            int mid = mi + (m-mi)/2;
            int place = 0;
            for(int i=0;i<r;i++)
            {
                place += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(place<des)
                mi=mid+1;
            else
                m=mid;
        }
        return m;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends