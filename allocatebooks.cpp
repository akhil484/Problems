bool possible(int limit, vector<int> &A, int B)
{
    int pages=0, as=1;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]>limit)
            return false;
        if(pages+A[i]>limit)
        {
            as+=1;
            pages=A[i];
            
                
        }
        else
        {
            pages+=A[i];
        }
    }
    if(B<as)
        return false;
    return true;
}

bool isMinimum(vector<int>A, int pages, int noOfStudent){
int stud=1, sum=0;
for(auto n: A){
    if(sum+n>pages){
        sum=n;
        stud++;
        if(stud>noOfStudent) return false;
    }
    else sum+=n;
}
return true;
}

int Solution::books(vector<int> &A, int B) {
    int l=INT_MAX,r=0,res=-1;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        r+=A[i];
        if(l>A[i])
            l=A[i];
    }
   if(B>n)
    return -1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(possible(mid,A,B))
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}
