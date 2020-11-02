#include <iostream>
#include <algorithm>
using namespace std;

struct job{
    int id;
    int d;
    int profit;
};

bool comparator(struct job j1,job j2)
{
    return (j1.profit>j2.profit);
}
int main() {
	//code
	int t;
	cin>>t;
	for(int tc=0;tc<t;tc++)
	{
	    int n;
	    cin>>n;
	    struct job j[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>j[i].id;
	        cin>>j[i].d;
	        cin>>j[i].profit;
	    }
	    sort(j,j+n,comparator);
	    int result[n];
	    bool slots[n];
	    int totalprofit=0,process=0;
	    for(int i=0;i<n;i++)
	        slots[i] = false;
	    for(int i=0;i<n;i++)
	    {
	        for(int ja=min(n,j[i].d)-1;ja>=0;ja--)
	        {
	            if(slots[ja]==false)
	                {
	                    slots[ja]=true;
	                    result[ja] = i;
	                    totalprofit+=j[i].profit;
	                    process++;
	                    break;
	                }
	        }
	    }
	    cout<<process<<" "<<totalprofit<<endl;
	}
	return 0;
}
