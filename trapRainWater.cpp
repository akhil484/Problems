class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        if(n==0)
            return 0;
//         vector<int> l(n,0);
//         vector<int> r(n,0);
//         l[0]=height[0];
//         r[n-1]=height[n-1];
//         for(int i=1;i<n;i++)
//         {
//             l[i]=max(l[i-1],height[i-1]);
//         }
        
//         for(int i=n-2;i>=0;i--)
//         {
//             r[i]=max(r[i+1],height[i+1]);
//         }
//         for(int i=0;i<n;i++)
//         {
//             ans+=max(0,(min(l[i],r[i])-height[i]));
//         }
        int rmax=0,lmax=0;
        int l=0,r=n-1;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]>=lmax)
                    lmax=height[l];
                else
                    ans+=lmax-height[l];
                l++;
            }
            else
            {
                if (height[r] >= rmax)
                    rmax = height[r];
                else
                    ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }

};
