class Solution {
public:
    int mod=pow(10,9)+7;

    int Comb(int n, int k, vector<vector<int>>& memo)
    {
        if(k == 0) return 1;
        if(n == 0) return 0;
        
        if(memo[n][k] != 0)
            return memo[n][k];
        
        memo[n][k] = Comb(n-1, k, memo)+Comb(n-1, k-1, memo);
        memo[n][k] %= mod;
        return memo[n][k];
    }
    int count(int val,int ind,int n,int maxV,vector<vector<int>> &dp,vector<vector<int>> &memo){
        //cout<<ind<<" "<<val<<" "<<endl;
        if(ind==n ){
            return 1;
        }
        
        int j=2;
        if(dp[ind][val]!=-1){
            return dp[ind][val];
        }
        
        long long ans=0;
        bool flag=0;
        
        //Multiple of Previous Value
        while(val*j<=maxV){
            //Totally Increasing
            ans=(ans%mod+count(val*j,ind+1,n,maxV,dp,memo)%mod)%mod;
            j++;
            
            //Non-decreasing
            //Value inside the array won't matter here. The formula will be same as long as
            //the array is non-decreasing
            //  _ _ _ _ _ _ _ _ _ _
            //If we have 4 elemets = {1,2,4,8}
            //We have to create groups or somehow calculate how many 1's will we take, how many 2's will we take
            // _ |_ _ _ |_ _ _ _ _ _
            // All places where you can create partition and before 1st partition will be all 1,
            //between 1-2 partition will be 2.
            //(n-1) places to put partition and you have to choose no of elements-1
            //Because if we have 4 elements{1.2.4.8} then we have to choose 3 places to put partitions
            if(val*j>maxV){
                ans=(ans%mod+Comb(n-1,ind-1,memo)%mod)%mod;
            }
            flag=1;
        }
        
        if(flag==0){
            if(val*j>maxV){
                ans=(ans%mod+Comb(n-1,ind-1,memo)%mod)%mod;
            }
        }
        
        dp[ind][val]=ans%mod;
        return dp[ind][val];
        
    }
    int idealArrays(int n, int maxV) {
        
        vector<vector<int>> dp(15,vector<int>(maxV+1,-1) );
        vector<vector<int>> memo(n+1,vector<int>(15,0));
        
        long long ans=0;
        
        //Starting Element
        for(int i=1;i<=maxV;i++)
            ans=(ans%mod+count(i,1,n,maxV,dp,memo)%mod)%mod;
        
        return ans;
    }
};