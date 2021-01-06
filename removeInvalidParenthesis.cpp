class Solution {
public:
    bool isParenthesis(char c) 
{ 
    return ((c == '(') || (c == ')')); 
} 
    
    bool isValid(string s)
    {
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
                cnt--;
            else if(s[i]=='(')
                cnt++;
             if (cnt < 0) 
                return false; 
        }
        if(cnt==0)
            return true;
        else 
            return false;
    }
        
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        if(s.length()==0)
        {
            res.push_back("");
            return res;
        }
        unordered_set<string> sset;
        queue<string> q;
        string temp;
        bool level=false;
        q.push(s);
        sset.insert(s);
        while(!q.empty())
        {
            s=q.front();
            q.pop();
            if(isValid(s))
            {
                
                res.push_back(s);
                level=true;
                
            }
            if(level)
                continue;
            for(int i=0;i<s.length();i++)
            {
                
                if(!isParenthesis(s[i]))
                    continue;
                temp=s.substr(0,i)+s.substr(i+1);
                if(sset.find(temp)==sset.end())
                {
                    
                    q.push(temp);
                    sset.insert(temp);
                }
            }
            
        }
        return res;
    }
};
