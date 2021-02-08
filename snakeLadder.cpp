class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        unordered_map<int, int> moves;
        moves[1] = 0;
        while(!q.empty())
        {
            int curr_sq = q.front();
            q.pop();
            for(int i=1;i<=6;i++)
            {
                int next_sq = curr_sq+i;
                if(next_sq>n*n)
                    break;
                int row = (next_sq-1)/n;
                int col = (row%2==0)? (next_sq-1)%n : (n-1)-(next_sq-1)%n;
                if(board[n-1-row][col]!=-1)
                    next_sq = board[n-1-row][col];
                if(moves.find(next_sq)==moves.end())
                {
                    moves[next_sq]=moves[curr_sq]+1;
                    if(next_sq==n*n)
                        return moves[next_sq];
                    q.push(next_sq);
                }
            }
            
        }
        return -1;
    }
};
