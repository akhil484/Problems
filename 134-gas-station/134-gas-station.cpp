//total sum should be greater than or equal to 0.
//Let us say at i I am not able to go further that means from 0 to i there will be no solution as 
//the total sum for them is negative and to compensate that from i+1to end should be net positive and greater than or equal to the negative part.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,sum=0;
        int start=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0)
            {
                sum=0;
                start=i+1;
            }
        }
        return (total<0)?-1:start;
    }
};