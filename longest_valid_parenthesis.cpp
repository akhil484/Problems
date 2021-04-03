class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<=1)
            return 0;
        int currmax=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            int t=st.top();
            if(t!=-1 && s[i]==')'&&s[t]=='(')
            {
                st.pop();
                currmax=max(currmax,i-st.top());
            }
            else
            {
                st.push(i);
            }
        }
        return currmax;
        
    }
};
