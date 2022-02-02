class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        
        int n = heights.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--)
        {
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
            if(s.empty())
                s.push(i);
            else if(heights[s.top()]>heights[i])
            {
                res[i]++;
                s.push(i);
            }
            else
            {
                while(!s.empty()&&heights[s.top()]<heights[i])
                {
                    res[i]++;
                    s.pop();
                }
                if(!s.empty()&&heights[s.top()]>heights[i])
                    res[i]++;
                s.push(i);
            }
        }
        return res;
    }
};