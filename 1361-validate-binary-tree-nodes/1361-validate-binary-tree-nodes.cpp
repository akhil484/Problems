class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> directParent(n,-1);
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1 && directParent[leftChild[i]]!=-1) return false;
            if(rightChild[i]!=-1 && directParent[rightChild[i]]!=-1) return false;
            if(leftChild[i]!=-1) directParent[leftChild[i]] = i;
            if(rightChild[i]!=-1) directParent[rightChild[i]] = i;
        }
        int count =0;
        int index = -1;
        for(int i=0; i<n; i++){
            if (directParent[i] ==-1) {
                count++;
                index = i;
            }
        }
        if(count!=1)
            return false;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(index);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(vis[node]==1) return false;
            vis[node] = 1; 
            if(leftChild[node]!=-1) q.push(leftChild[node]);
            if(rightChild[node]!=-1) q.push(rightChild[node]);
        }
        for(int i:vis)
        {
            if(i==0)
                return false;
        }
        return true;
    }
};