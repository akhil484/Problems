class Solution {
public:
    
    
    int cost(int from, int to)
    {
        return from==26?0:abs(from/6-to/6)+abs(from%6-to%6);
    }
    
    int calculate(string &word, int pos, int other,vector<vector<int>> &dp)
    {
        if(pos>=word.size())
            return 0;
        if(dp[other][pos]==-1)
        {
            int to = word[pos]-'A';
            int last = word[pos-1]-'A';
            dp[other][pos] = min(cost(other,to)+calculate(word,pos+1,last,dp),cost(last,to)+calculate(word,pos+1,other,dp));
        }
        return dp[other][pos];
    }
    
    int minimumDistance(string word) {
        vector<vector<int>> dp(27,vector<int>(301,-1));
        return calculate(word,1,26,dp);
    }
};