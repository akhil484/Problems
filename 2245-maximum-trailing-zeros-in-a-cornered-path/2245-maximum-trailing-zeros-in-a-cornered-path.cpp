class Solution {
public:
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<pair<int,int>>> suff(row,vector<pair<int,int>>(col));
        vector<vector<pair<int,int> >> pref(row,vector<pair<int,int>>(col));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int two = 0, five = 0;
                int x = grid[i][j];
                while(x%2==0)   
                {x/=2;two++;}
                while(x%5==0)   
                {x/=5;five++;}
                pref[i][j] = {two,five};
                
                if(j!=0)
                {
                    pref[i][j].first+=pref[i][j-1].first;
                    pref[i][j].second+=pref[i][j-1].second;
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=grid[i].size()-1;j>=0;j--)
            {
                int two = 0, five = 0;
                int x = grid[i][j];
                while(x%2==0)   
                {x/=2;two++;}
                while(x%5==0)   
                {x/=5;five++;}
                suff[i][j] = {two,five};
                
                if(j!=grid[i].size()-1)
                {
                    suff[i][j].first+=suff[i][j+1].first;
                    suff[i][j].second+=suff[i][j+1].second;
                }
            }
        }
        int ans=0;
        int cnt2=0,cnt5=0;
        for(int i=0;i<grid[0].size();i++)
        {
            cnt2=0,cnt5=0;
            for(int j=0;j<grid.size();j++)
            {
                ans = max(ans,min(cnt2+pref[j][i].first,cnt5+pref[j][i].second));
                ans = max(ans,min(cnt2+suff[j][i].first,cnt5+suff[j][i].second));
                int two = 0, five = 0;
                int x = grid[j][i];
                while(x%2==0)   
                {x/=2;two++;}
                while(x%5==0)   
                {x/=5;five++;}cnt2+=two;
                cnt5+=five;
            }
        }
        cnt2=0,cnt5=0;
        for(int i=0;i<grid[0].size();i++)
        {
            cnt2=0,cnt5=0;
            for(int j=grid.size()-1;j>=0;j--)
            {
                ans = max(ans,min(cnt2+pref[j][i].first,cnt5+pref[j][i].second));
                ans = max(ans,min(cnt2+suff[j][i].first,cnt5+suff[j][i].second));
                int two = 0, five = 0;
                int x = grid[j][i];
                while(x%2==0)   
                {x/=2;two++;}
                while(x%5==0)   
                {x/=5;five++;}cnt2+=two;
                cnt5+=five;
            }
        }
        return ans;
    }
    
};