class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int i=a.length()-1,j=b.length()-1;
        int c=0;
        while(i>=0||j>=0||c==1)
        {
            c+=i>=0?a[i--]-'0':0;
            c+=j>=0?b[j--]-'0':0;
            res=char(c%2+'0')+res;
            c=c/2;
        }
        return res;
    }
};