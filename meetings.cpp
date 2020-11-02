#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

struct meet{
    int start;
    int end;
    int pos;
};

bool comparator(struct meet m1, meet m2)
{
    return m1.end<m2.end;
}



int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n;
	    cin>>n;
	    int s[n],f[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    for(int i=0;i<n;i++)
	        cin>>f[i];
	struct meet m[n];
    for(int i=0;i<n;i++)
    {
        m[i].start=s[i];
        m[i].end=f[i];
        m[i].pos=i+1;
    }
    sort(m,m+n,comparator);
    vector<int> meetings;
    meetings.push_back(m[0].pos);
    int end_time = m[0].end;
    for(int i=1;i<n;i++)
    {
        if(m[i].start>=end_time)
        {
            meetings.push_back(m[i].pos);
            end_time = m[i].end;
        }
    }
    for(int i=0;i<meetings.size();i++)
        cout<<meetings[i]<<" ";
	}
	return 0;
}