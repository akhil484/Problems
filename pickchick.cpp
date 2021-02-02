#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c;
    cin>>c;
    for(int tc=0;tc<c;tc++)
    {
        int n,k,b,t;
        cin>>n>>k>>b>>t;
        int x[n],v[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int count=0;
        int ans=0;
        int canttreach=0;
        for(int i=n-1;i>=0;i--)
        {
            long long dis=b-x[i];
            long long cover=v[i]*t;
            if(dis<=cover)
            {
                count++;
                if(canttreach>0)
                {
                    ans+=canttreach;
                }
            }
            else
            {
                canttreach++;
            }
            if(count==k)
                break;
            
        }
        if(count<k)
            cout << "Case #" << tc+1 << ": " << "IMPOSSIBLE" << endl;
        else
            cout << "Case #" << tc+1 << ": " << ans << endl;
    }
}
