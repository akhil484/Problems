class Solution {
public:
    void add(vector<string> &ans,string num, string exp, int target, int pos, long long curval, long long lastval)
    {
        if(pos==num.length())
        {
            if(curval==target)
            {
                ans.push_back(exp);
            }
            return;
        }
        for(int i=pos;i<num.length();i++)
        {
            if(pos!=i && num[pos]=='0')
                break;
            string part=num.substr(pos,i+1-pos);
            long long curr=stoll(part);
            if(pos==0)
            {
                add(ans,num,exp+part,target,i+1,curr,curr);

            }
            else
            {
                add(ans,num,exp+"+"+part,target,i+1,curval+curr,curr);
                add(ans,num,exp+"-"+part,target,i+1,curval-curr,-curr);
                add(ans,num,exp+"*"+part,target,i+1,curval-lastval+lastval*curr,lastval*curr);
            }
        }
        
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        add(ans,num,"",target,0,0,0);
        return ans;
    }
};