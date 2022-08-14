class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> s;
        string ans;
        for(int i=0;i<=pattern.size();i++)
        {
            s.push(i+1);
            if(i==pattern.length()||pattern[i]=='I')
            {
                while(!s.empty())
                {
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return ans;
    }
};