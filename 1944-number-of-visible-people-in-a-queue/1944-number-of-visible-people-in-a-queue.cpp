class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        
        int n = heights.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[s.top()]<=heights[i])
                {
                    res[s.top()]++;
                    s.pop();
                }
            // int next=-1;
            // int temp=0;
            // for(int j=i+1;j<n;j++)
            // {
            //     if(heights[j]>heights[i])
            //     {
            //         temp++;
            //         break;
            //     }
            //     else if(next<heights[j])
            //     {
            //         next=heights[j];
            //         temp++;
            //     }
            // }
            // res[i]=temp;
            if(!s.empty())
                res[s.top()]++;
            
            s.push(i);
            
        }
        return res;
    }
};