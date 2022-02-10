class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 0;
        string end = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string beg = "";
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                beg+=to_string(board[i][j]);
            }
        }
        unordered_set<string> visited;
        visited.insert(beg);
        queue<pair<string,int>> q;
        q.push({beg,0});
        while(!q.empty())
        {
            string curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(curr==end)
                return dist;
            int index = curr.find("0");
            for(auto i:moves[index])
            {
                string next = curr;
                swap(next[i],next[index]);
                if(!visited.count(next))
                {
                    visited.insert(next);
                    q.push({next,dist+1});
                }
            }
        }
        return -1;
    }
};