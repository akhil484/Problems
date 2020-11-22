// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings
int dic_contain(string sub, vector<string> &B)
{
    for(int i=0;i<B.size();i++)
    {
        if(B[i].compare(sub)==0)
            return 1;
    }
    return 0;
}


int wordBreak(string A, vector<string> &B) {
    //code here
    int l=A.length();
    if(l==0)
        return 1;
    int wb[l+1];
    memset(wb,0,sizeof(wb));
    wb[0]=1;
    
    for(int i=1;i<=l;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(wb[j] && dic_contain(A.substr(j,i-j),B))
            {   
                wb[i] = 1;
                break;
            }
            
        }
    }
    return wb[l];
}
