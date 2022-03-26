class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int> s(begin(days),end(days));
        int dp[30]={};
        for(int i = days.front(); i <= days.back(); ++i)
        {
            if(s.find(i)==s.end())
                dp[i%30]=dp[(i-1)%30];
            else
            {
                dp[i%30] = min(dp[(i-1)%30]+cost[0],min(dp[max(0,i-7)%30]+cost[1],dp[max(0,i-30)%30]+cost[2]));
            }
        }
        return dp[days.back()%30];
    }
};