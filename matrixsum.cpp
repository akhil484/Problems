class NumMatrix {
    
public:
    int row,col;
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.empty())
        {
            row = matrix.size();
            col = matrix[0].size();
            mat.resize(row,vector<int>(col));
            mat=matrix;
            for(int i=0;i<row;i++)
            {
                for(int j=1;j<col;j++)
                {
                    mat[i][j]+=mat[i][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(mat.empty())
            return 0;
        int sum=0;
        if(col1==0&&col2<col)
        {
            for(int i=row1;i<=row2;i++)
                sum+=mat[i][col2];
        }
        else
        {
            for(int i=row1;i<=row2;i++)
            {
                sum+=mat[i][col2]-mat[i][col1-1];
            }
        }
        return sum;
    }
   
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
