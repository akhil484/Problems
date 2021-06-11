#include<bits/stdc++.h>
using namespace std;

int findways(string s1, string s2)
{
    int l1=s1.length();
    int l2=s2.length();
    vector<vector<int>> dpt(l1,vector<int>(l1,0));
    vector<vector<int>> dpf(l1,vector<int>(l1,0));
    // int dpt[l1][l1];
    // int dpf[l1][l1];
    for(int g=0;g<l1;g++)
    {
        for(int i=0,j=g;j<l1;j++,i++)
        {
            if(g==0)
            {
                if(s1[i]=='T')
                {
                    dpt[i][j]=1;
                    dpf[i][j]=0;
                }
                else
                {
                    dpt[i][j]=0;
                    dpf[i][j]=1;
                }
            }
            else
            {
                for(int k=i;k<j;k++)
                {
                    int ltc=dpt[i][k];
                    int rtc=dpt[k+1][j];
                    int lfc=dpf[i][k];
                    int rfc=dpf[k+1][j];
                    if(s2[k]=='&')
                    {
                        dpt[i][j]+=ltc*rtc;
                        dpf[i][j]+=lfc*rtc+ltc*rfc+lfc*rfc;
                    }
                    else if(s2[k]=='|')
                    {
                        dpt[i][j]+=ltc*rtc+lfc*rtc+ltc*rfc;
                        dpf[i][j]+=lfc*rfc;
                    }
                    else
                    {
                        dpt[i][j]+=lfc*rtc+ltc*rfc;
                        dpf[i][j]+=lfc*rfc+ltc*rtc;
                    }
                }
            }
        }
    }
    return dpt[0][l1-1];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<findways(s1,s2);
    return 0;
}
