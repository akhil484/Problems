class Solution {
public:
    double findMed(vector<int> a, vector<int> b, int n, int m)
    {
        int l=0,h=n;
	    while(l<=h)
	    {
		    int c1=(l+h)/2;
		    int c2=((n+m)/2)-c1;

		    int l1=(c1==0)?INT_MIN:a[c1-1];
		    int l2=(c2==0)?INT_MIN:b[c2-1];
		
		    int r1=(c1==n)?INT_MAX:a[c1];
		    int r2=(c2==m)?INT_MAX:b[c2];
		    if(l1>r2)
		    {
			    h=c1-1;
		    }
		    else if(l2>r1)
		    {
			    l=c1+1;
		    }
		    else
		    {
                if((n+m)%2==0)
			        return ((double)(max(l1,l2)+min(r1,r2))/2);
                else
                    return ((double) min(r1,r2));
		    }
	    }
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2>=n1)
            return findMed(nums1, nums2, n1,n2);
        else
            return findMed(nums2,nums1,n2,n1);
    }
};
