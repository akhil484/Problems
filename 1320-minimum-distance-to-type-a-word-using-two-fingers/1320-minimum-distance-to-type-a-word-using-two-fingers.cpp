class Solution {
public:
    const int alpha = 27;
    const int inf = 301;
    
    int cost(char from, char to)
    {
        return from==26?0:abs(from/6-to/6)+abs(from%6-to%6);
    }
    
    int calculate(string &word, int pos, char other,vector<vector<int>> &dp)
    {
        if(pos>=word.size())
            return 0;
        if(dp[other][pos]==-1)
        {
            auto to = word[pos]-'A';
            auto last = word[pos-1]-'A';
            dp[other][pos] = min(cost(other,to)+calculate(word,pos+1,last,dp),cost(last,to)+calculate(word,pos+1,other,dp));
        }
        return dp[other][pos];
    }
    
    int minimumDistance(string word) {
        vector<vector<int>> dp(alpha,vector<int>(inf,-1));
        return calculate(word,1,26,dp);
    }
};