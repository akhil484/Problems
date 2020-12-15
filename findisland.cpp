// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool isSafe(vector<int> A[], int r, int c, bool *visited,int N, int M)
{
    if(r>=0 && r<N && c>=0 && c<M &&(A[r][c]&&!(*((visited+r*M) + c))))
        return true;
    return false;
}
void DFS(vector<int> A[], int r, int c, bool *visited,int N, int M)
{
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    //visited[r][c] = true;
    *((visited+r*M) + c) = true;
    for(int k=0;k<8;k++)
    {
        if(isSafe(A,r+rowNbr[k],c+colNbr[k],(bool *)visited,N,M))
        {
            DFS(A,r+rowNbr[k],c+colNbr[k],(bool *)visited,N,M);
        }
    }
}
int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    bool visited[N][M];
    memset(visited,0,sizeof(visited));
    int count =0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j] && !visited[i][j])
            {
                DFS(A,i,j,(bool *)visited,N,M);
                count++;
            }
        }
    }
    return count;
}
