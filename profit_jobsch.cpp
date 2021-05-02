class Solution {
public:
   static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end(),comp);
        int dp[n];
        dp[0] = v[0][2];
        for(int i=1;i<n;i++)
        {
            int low=0;
            int high=i-1;
            int includeee=v[i][2];
            int last=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(v[mid][1]<=v[i][0])
                {
                    last=mid;
                    low=mid+1;
                }
                else
                    high=mid-1;
                
            }
            if(last!=-1)
                includeee+=dp[last];
            int excludeee=dp[i-1];
            dp[i]=max(includeee,excludeee);
        }
        return dp[n-1];
    }
};
