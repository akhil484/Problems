class Solution {
public:
    
    int m = 0;
    void maxpoints(int numArrows, vector<int>& aliceArrows, int index, int currScore, vector<int> &res,vector<int> &temp)
    {
        if(numArrows<0)
            return;
        if(currScore>=m)
        {
            m=currScore;
            for(int i=0;i<12;i++)
                res[i]=temp[i];
        }
        if(numArrows==0)
            return;
        temp[index] = (index==0)?numArrows:aliceArrows[index]+1;
        maxpoints(numArrows-temp[index], aliceArrows, index-1, currScore+index, res, temp);
        temp[index] = (index==0)?numArrows:0;
        maxpoints(numArrows-temp[index], aliceArrows, index-1, currScore, res,temp);
        temp[index]=0;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12,0);
        vector<int> temp(12,0);
        maxpoints(numArrows, aliceArrows, 11, 0,res,temp);
        return res;
    }
};