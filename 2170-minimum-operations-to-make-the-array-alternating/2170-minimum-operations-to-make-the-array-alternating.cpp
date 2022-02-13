class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        int totaleven=0;
        int totalodd=0;
        unordered_map<int,int> even,odd;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                totaleven++;
                even[nums[i]]++;
            }
            else
            {
                totalodd++;
                odd[nums[i]]++;
            }
        }
        
         int firstevencount = 0, firsteven=0;
        int secondevencount = 0, secondeven=0;
        for(auto it=even.begin();it!=even.end();it++)
        {
            int num = it->first;
            int freq = it->second;
            if(freq>=firstevencount)
            {
                secondevencount = firstevencount;
                secondeven = firsteven;
                firsteven = num;
                firstevencount = freq;
            }
            else if(freq>=secondevencount)
            {
                secondevencount = freq;
                secondeven = num;
            }
        }
        
        int firstoddcount = 0, firstodd=0;
        int secondoddcount = 0, secondodd=0;
        for(auto it=odd.begin();it!=odd.end();it++)
        {
            int num = it->first;
            int freq = it->second;
            if(freq>=firstoddcount)
            {
                secondoddcount = firstoddcount;
                secondodd = firstodd;
                firstodd = num;
                firstoddcount = freq;
            }
            else if(freq>=secondoddcount)
            {
                secondoddcount = freq;
                secondodd = num;
            }
        }
        int operationseven=0, operationsodd=0;
        operationseven = totaleven-firstevencount;
        if(firsteven!=firstodd)
            operationseven+=(totalodd-firstoddcount);
        else
            operationseven+=(totalodd-secondoddcount);

        operationsodd = totalodd-firstoddcount;
        if(firsteven!=firstodd)
            operationsodd+=(totaleven-firstevencount);
        else
            operationsodd+=(totaleven-secondevencount);
        return min(operationseven,operationsodd);
    }
};