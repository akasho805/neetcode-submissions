class NumMatrix {
public:
    vector<std::vector<int>> prefix;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefix.resize(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                prefix[i][j] = matrix[i-1][j-1]
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }        

        // elimininate if branching using above
        // prefix.resize(rows, vector<int>(cols, 0));

        // for(int i=0;i<rows;i++)
        // {
        //     for(int j=0;j<cols;j++)
        //     {
        //         if(i==0 and j ==0)
        //         {
        //             prefix[i][j] = matrix[i][j];
        //             continue;
        //         }
        //         if(i==0)
        //         {
        //             prefix[i][j] = matrix[i][j]+ prefix[i][j-1];
        //             continue;
        //         }
        //         if(j==0)
        //         {
        //             prefix[i][j] = matrix[i][j]+ prefix[i-1][j];
        //             continue;
        //         }
        //         prefix[i][j] = matrix[i][j]+ prefix[i-1][j]+ prefix[i][j-1]- prefix[i-1][j-1];
        //     }
        // }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        //code after eliminate if branching
        row1++; col1++; row2++; col2++;

        return prefix[row2][col2]
             - prefix[row1-1][col2]
             - prefix[row2][col1-1]
             + prefix[row1-1][col1-1];

        // int total = prefix[row2][col2];
        // int top = (row1 > 0) ? prefix[row1 - 1][col2] : 0;
        // int left = (col1 > 0) ? prefix[row2][col1 - 1] : 0;
        // int topLeft = (row1 > 0 && col1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;

        // return total - top - left + topLeft;

        //better above
        // if(row1==0 and col1 ==0)
        // {
        //     return prefix[row2][col2];
        // }
        // if(row1==0)
        // {
        //     return prefix[row2][col2] - prefix[row2][col1-1];
        // }
        // if(col1 ==0)
        // {
        //     return prefix[row2][col2] - prefix[row1-1][col2];
        // }
        // return prefix[row2][col2] - prefix[row1-1][col2]- prefix[row2][col1-1]+ prefix[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */