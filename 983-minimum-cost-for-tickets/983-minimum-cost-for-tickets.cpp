class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int> s(begin(days),end(days));
        int dp[366]={};
        for(int i=1;i<366;i++)
        {
            if(s.find(i)==s.end())
                dp[i]=dp[i-1];
            else
            {
                dp[i] = min(dp[i-1]+cost[0],min(dp[max(0,i-7)]+cost[1],dp[max(0,i-30)]+cost[2]));
            }
        }
        return dp[365];
    }
};