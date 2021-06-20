void dfs(vector<vector<int>> &adj, vector<int> &sum, int curr, vector<int> &A){
    sum[curr] += A[curr];
    for(int i : adj[curr]){
        if(sum[i]==0){
            dfs(adj, sum, i, A);
            sum[curr] += sum[i];
        }
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> adj(n);
    for(auto v : B){
        adj[v[0]-1].push_back(v[1]-1);
        adj[v[1]-1].push_back(v[0]-1);
    }
    vector<int> sum(n, 0);
    dfs(adj, sum, 0, A);
    int ans = INT_MIN;
    int mod = 1e9+7;
    for(auto v : B){
        long long temp1 = min(sum[v[0]-1], sum[v[1]-1]);
        long long temp2 = sum[0] - temp1;
        int temp3 = (temp1*temp2)%mod;
        ans = max(temp3, ans);
    }
    return ans;
}
