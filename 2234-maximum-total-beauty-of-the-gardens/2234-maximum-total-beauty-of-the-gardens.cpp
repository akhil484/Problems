class Solution {
public:
    //sort flowers in descending order and then start with bigger ones so that you can make a garden full with less flowers.
    //In one case keeping one garden incomplete can be beneficial than completing all garden
    //we will start with minF = last value of flowers and will go upto target to see at what maximum value of minF we get the maximum answer and for that we might have to decrease f i.e take flowers back from our complete garden
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(),flowers.end(),greater<int>());
        long long sz = flowers.size();
        long long f = 0, sum=0;
        for(;f<sz;f++)
        {
            if(target-flowers[f]>newFlowers)
                break;
            newFlowers -= max(0,target-flowers[f]);
        }
        if(f==sz){
            return max(sz * full, (sz - 1) * full + (flowers.back() < target ? (long long)(target - 1) * partial : full));
        }
        long long res=0;
         for (long long minF = flowers.back(), end = flowers.size() - 1; minF < target; )
         {
             while(end>=f&&flowers[end]<=minF)
                 sum+=flowers[end--];
             int needed = (sz-1-end)*minF - sum;
             if(needed>newFlowers)
             {
                 if(--f<0)
                     break;
                 newFlowers+=max(0,target-flowers[f]);
             }
             else
             {
                 res = max(res,minF*partial+f*full);
                 ++minF;
             }
         }
        return res;
    }
};