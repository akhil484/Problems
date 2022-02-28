class Solution {
    private:
    int best[1001];
    int maxLaps=0;
public:
    int f(int n, int changeTime, vector<int> &dp)
    {
        if(n==0)
            return -changeTime;
        if(dp[n]!=-1)
            return dp[n];
        int mini=INT_MAX;
        for(int lap=1;lap<=min(n,maxLaps);lap++)
        {
            int time = best[lap]+changeTime+f(n-lap,changeTime,dp);
            mini=min(mini,time);
        }
        return dp[n]=mini;
    }
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int n=tires.size();
        for(int i=0;i<=numLaps;i++)
            best[i]=INT_MAX;
        vector<int> dp(numLaps+1,-1);
        for(auto it:tires)
        {
            int fi=it[0];
            int ri=it[1];
            long long time=fi;
            long long curlaptime=fi;
            for(int lap=1;lap<=numLaps&&curlaptime<changeTime+fi;lap++)
            {
                if(time<best[lap])
                    best[lap]=time;
                maxLaps=max(maxLaps,lap);
                curlaptime*=ri;
                time+=curlaptime;
            }
        }
        return f(numLaps,changeTime,dp);
    }
};