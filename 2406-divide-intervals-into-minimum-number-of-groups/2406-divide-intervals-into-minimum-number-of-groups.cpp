class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int max_grp = 1;
        int grp = 1;
        vector<int> start;
        vector<int> ending;
        
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            ending.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(ending.begin(),ending.end());
        int i=1,j=0;
        while(i<n&&j<n)
        {
            if(start[i]>ending[j])
            {
                grp--;
                j++;
            }
            else
            {
                grp++;
                i++;
            }
            max_grp=max(grp,max_grp);
        }
        return max_grp;
    }
};